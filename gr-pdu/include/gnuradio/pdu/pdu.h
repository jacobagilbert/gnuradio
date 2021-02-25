/* -*- c++ -*- */
/*
 * Copyright 2013,2021 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */


#ifndef INCLUDED_PDU_PDU_H
#define INCLUDED_PDU_PDU_H

#include <gnuradio/gr_complex.h>
#include <gnuradio/pdu/api.h>
#include <pmt/pmt.h>

namespace gr {
namespace pdu {

// PDU uniform vector types
namespace types {
enum vector_type { byte_t, float_t, complex_t };
} // namespace types

// static const PMT interned string getters
namespace ports {
PDU_API const pmt::pmt_t data();
PDU_API const pmt::pmt_t dict();
PDU_API const pmt::pmt_t emit();
PDU_API const pmt::pmt_t msg();
PDU_API const pmt::pmt_t pdus();
} // namespace ports

// pdu functions
PDU_API size_t itemsize(types::vector_type type);
PDU_API bool type_matches(types::vector_type type, pmt::pmt_t v);
PDU_API pmt::pmt_t
make_pdu_vector(types::vector_type type, const uint8_t* buf, size_t items);
PDU_API types::vector_type type_from_pmt(pmt::pmt_t vector);


} // namespace pdu
} // namespace gr

#endif /* INCLUDED_PDU_PDU_H */
