/* -*- c++ -*- */
/*
 * Copyright 2021 NTESS LLC.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_PDU_PDU_FREQUENCY_MODULATOR_FC_H
#define INCLUDED_PDU_PDU_FREQUENCY_MODULATOR_FC_H

#include <gnuradio/block.h>
#include <gnuradio/pdu/api.h>

namespace gr {
namespace pdu {

/*!
 * \brief PDU Frequency Modulator
 * \ingroup modulators_blk
 * \ingroup pdu_blk
 *
 * This block accepts a float PDU of size n containing baseband
 * data, applies frequency modulation with a configurable pulse shaping filter and emits a
 * gr_complex PDU of size n-len(taps)+1.
 */
class PDU_API pdu_frequency_modulator_fc : virtual public gr::block
{
public:
    typedef std::shared_ptr<pdu_frequency_modulator_fc> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of pdu::pdu_frequency_modulator_fc.
     *
     * @param sensitivity -
     * @param taps -
     */
    static sptr make(float sensitivity, const std::vector<float> taps);

    /**
     * Sets sensitivity
     *
     * @param sensitivity -
     */
    virtual void set_sensitivity(float sensitivity) = 0;

    /**
     * Sets taps array
     *
     * @param taps -
     */
    virtual void set_taps(std::vector<float> taps) = 0;
};

} // namespace pdu
} // namespace gr

#endif /* INCLUDED_PDU_PDU_FREQUENCY_MODULATOR_FC_H */
