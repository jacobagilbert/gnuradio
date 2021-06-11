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
/* BINDTOOL_HEADER_FILE(take_skip_to_pdu.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(0fd64d6f3ff06d4bdfa2031a0afffd27)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/pdu/take_skip_to_pdu.h>
// pydoc.h is automatically generated in the build directory
#include <take_skip_to_pdu_pydoc.h>

template <typename T>
void bind_take_skip_to_pdu_template(py::module& m, const char* classname)
{

    using take_skip_to_pdu = ::gr::pdu::take_skip_to_pdu<T>;


    py::class_<take_skip_to_pdu,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<take_skip_to_pdu>>(m, classname)

        .def(py::init(&gr::pdu::take_skip_to_pdu<T>::make),
             py::arg("take"),
             py::arg("skip"),
             D(take_skip_to_pdu, make))

        .def("set_take",
             &take_skip_to_pdu::set_take,
             py::arg("take"),
             D(take_skip_to_pdu, set_take))

        .def("set_skip",
             &take_skip_to_pdu::set_skip,
             py::arg("skip"),
             D(take_skip_to_pdu, set_skip));
}

void bind_take_skip_to_pdu(py::module& m)
{
    bind_take_skip_to_pdu_template<unsigned char>(m, "take_skip_to_pdu_b");
    bind_take_skip_to_pdu_template<short>(m, "take_skip_to_pdu_s");
    bind_take_skip_to_pdu_template<float>(m, "take_skip_to_pdu_f");
    bind_take_skip_to_pdu_template<gr_complex>(m, "take_skip_to_pdu_c");
}
