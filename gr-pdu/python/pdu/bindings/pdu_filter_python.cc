/*
 * Copyright 2021 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(pdu_filter.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(8ca41a1466a0f9939a533af682d055cb)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/pdu/pdu_filter.h>
// pydoc.h is automatically generated in the build directory
#include <pdu_filter_pydoc.h>

void bind_pdu_filter(py::module& m)
{

    using pdu_filter = ::gr::pdu::pdu_filter;


    py::class_<pdu_filter, gr::block, gr::basic_block, std::shared_ptr<pdu_filter>>(
        m, "pdu_filter", D(pdu_filter))

        .def(py::init(&pdu_filter::make),
             py::arg("k"),
             py::arg("v"),
             py::arg("invert") = false,
             D(pdu_filter, make))


        .def("set_key", &pdu_filter::set_key, py::arg("key"), D(pdu_filter, set_key))


        .def("set_val", &pdu_filter::set_val, py::arg("val"), D(pdu_filter, set_val))


        .def("set_inversion",
             &pdu_filter::set_inversion,
             py::arg("invert"),
             D(pdu_filter, set_inversion))

        ;
}
