/* -*- c++ -*- */
/*
 * Copyright 2021 NTESS LLC.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_PDU_PDU_FREQUENCY_MODULATOR_FC_IMPL_H
#define INCLUDED_PDU_PDU_FREQUENCY_MODULATOR_FC_IMPL_H

#include <gnuradio/filter/fir_filter.h>
#include <gnuradio/pdu/pdu_frequency_modulator_fc.h>

namespace gr {
namespace pdu {

class pdu_frequency_modulator_fc_impl : public pdu_frequency_modulator_fc
{
private:
    float d_phase;
    float d_sensitivity;
    std::vector<float> d_taps;
    filter::kernel::fir_filter_fff* d_fir;
    std::vector<float> d_log_ramp;

public:
    /**
     * constructor
     *
     * @param sensitivity -
     * @param taps -
     */
    pdu_frequency_modulator_fc_impl(float sensitivity, const std::vector<float> taps);

    /**
     * Deconstructor
     */
    ~pdu_frequency_modulator_fc_impl();

    void handle_pdu(pmt::pmt_t pdu);

    /**
     * Sets sensitivity
     *
     * @param sensitivity -
     */
    void set_sensitivity(float sensitivity);

    /**
     * Sets taps array
     *
     * @param taps -
     */
    void set_taps(std::vector<float> taps);
};

} // namespace pdu
} // namespace gr

#endif /* INCLUDED_PDU_PDU_FREQUENCY_MODULATOR_FC_IMPL_H */
