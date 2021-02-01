/* -*- c++ -*- */
/*
 * Copyright 2021 NTESS LLC.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "pdu_frequency_modulator_fc_impl.h"
#include <gnuradio/io_signature.h>
#include <gnuradio/pdu/pdu.h>

#include <gnuradio/fxpt.h>
#include <cmath>

namespace gr {
namespace pdu {

pdu_frequency_modulator_fc::sptr
pdu_frequency_modulator_fc::make(float sensitivity, const std::vector<float> taps)
{
    return gnuradio::make_block_sptr<pdu_frequency_modulator_fc_impl>(sensitivity, taps);
}

pdu_frequency_modulator_fc_impl::pdu_frequency_modulator_fc_impl(
    float sensitivity, const std::vector<float> taps)
    : gr::block("pdu_frequency_modulator_fc",
                gr::io_signature::make(0, 0, 0),
                gr::io_signature::make(0, 0, 0)),
      d_phase(0),
      d_sensitivity(sensitivity),
      d_taps(taps)
{
    d_fir = new filter::kernel::fir_filter_fff(taps);

    // table of a log-ramp for scaling bursts
    // [10**((x-50)/10.) for x in range(0,50)]
    d_log_ramp.clear();
    for (auto i = 0; i < 50; i++) {
        d_log_ramp.push_back(std::pow(10, ((float)i - 50.0) / 10.0));
    }

    message_port_register_in(PMTCONSTSTR__pdus());
    set_msg_handler(PMTCONSTSTR__pdus(),
                    [this](pmt::pmt_t msg) { this->handle_pdu(msg); });
    message_port_register_out(PMTCONSTSTR__pdus());
}

pdu_frequency_modulator_fc_impl::~pdu_frequency_modulator_fc_impl() {}

void pdu_frequency_modulator_fc_impl::handle_pdu(pmt::pmt_t pdu)
{
    // make sure PDU data is formed properly
    if (!(pmt::is_pdu(pdu))) {
        GR_LOG_WARN(d_logger, "Message received is not a PDU, dropping");
        return;
    }

    // gr::thread::scoped_lock l(d_setlock);

    /* code */
    pmt::pmt_t meta = pmt::car(pdu);
    pmt::pmt_t v_data = pmt::cdr(pdu);

    if (pmt::is_f32vector(v_data)) {
        uint32_t v_len = pmt::length(v_data);

        const std::vector<float> d_in = pmt::f32vector_elements(v_data);

        std::vector<gr_complex> mod; // output
        uint32_t start = d_taps.size() - 1;
        // adjust length by filter taps
        v_len -= start;
        mod.resize(v_len);

        // do FIR filtering
        for (auto ii = 0U; ii < v_len; ii++) {
            if (d_taps.size() > 1) {
                float in_filt = 0;

                in_filt = d_fir->filter(&d_in[ii]);

                d_phase = d_phase + d_sensitivity * in_filt;
            } else {
                d_phase = d_phase + d_sensitivity * d_in[ii];
            }

// place phase in [-pi, +pi)
#define F_PI ((float)(M_PI))

            float oi, oq;
            float p_mod = std::fmod(d_phase + F_PI, 2.0f * F_PI) - F_PI;

            int32_t angle = gr::fxpt::float_to_fixed(p_mod);
            gr::fxpt::sincos(angle, &oq, &oi);

            // mod[ii] = gr_complex(oi, oq);
            mod[ii] = std::complex<float>(oi, oq);
        }

        // make vectors same size (by dumb end-extension)
        gr_complex fill_val = mod.back();
        for (auto ii = 0U; ii < start; ii++) {
            mod.push_back(fill_val);
            v_len++;
        }

        // scale the first HARDCODE 50 samples with a simple ramp function
        size_t end_samp = std::min(d_log_ramp.size(), mod.size());
        for (auto i = 0U; i < end_samp; i++) {
            mod[i] *= d_log_ramp[i];
        }

        message_port_pub(
            PMTCONSTSTR__pdus(),
            (pmt::cons(meta, pmt::init_c32vector(v_len, (const gr_complex*)&mod[0]))));
        d_phase = 0;

    } else {
        GR_LOG_WARN(d_logger, "PDU vector type is not f32, dropping");
    }
}


void pdu_frequency_modulator_fc_impl::set_sensitivity(float sensitivity)
{
    // gr::thread::scoped_lock l(d_setlock);

    d_sensitivity = sensitivity;
}


void pdu_frequency_modulator_fc_impl::set_taps(std::vector<float> taps)
{
    // gr::thread::scoped_lock l(d_setlock);

    d_taps = taps;
}

} /* namespace pdu */
} /* namespace gr */
