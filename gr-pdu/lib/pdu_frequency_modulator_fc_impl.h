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

    /*!
     * \brief PDU formatted messages received in this port are frequency modulated.
     *
     * This port receives messages from the scheduler's message handling mechanism and
     * frequency modulates the vector data. A pulse shaping filter with parameterized taps
     * can also be applied by this block. The resulting FC32 PDU is emitted out of this
     * block. The input port is safe for all PMT objects but anything other than F32 PDUs
     * are dropped.
     *
     * \param pdu A F32 PDU message passed from the scheduler's message handling.
     */
    void handle_pdu(pmt::pmt_t pdu);

public:
    pdu_frequency_modulator_fc_impl(float sensitivity, const std::vector<float> taps);
    ~pdu_frequency_modulator_fc_impl() override;

    void set_sensitivity(float sensitivity) override;
    void set_taps(std::vector<float> taps) override;
};

} // namespace pdu
} // namespace gr

#endif /* INCLUDED_PDU_PDU_FREQUENCY_MODULATOR_FC_IMPL_H */
