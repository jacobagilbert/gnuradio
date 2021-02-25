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
/* BINDTOOL_HEADER_FILE(pdu_to_tagged_stream.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(3a93b879f5a4b6786b1ec4598e9a8786)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/pdu/pdu_to_tagged_stream.h>
// pydoc.h is automatically generated in the build directory
#include <pdu_to_tagged_stream_pydoc.h>

void bind_pdu_to_tagged_stream(py::module& m)
{

    using pdu_to_tagged_stream = ::gr::pdu::pdu_to_tagged_stream;


    py::class_<pdu_to_tagged_stream,
               gr::tagged_stream_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<pdu_to_tagged_stream>>(
        m, "pdu_to_tagged_stream", D(pdu_to_tagged_stream))

        .def(py::init(&pdu_to_tagged_stream::make),
             py::arg("type"),
             py::arg("lengthtagname") = "packet_len",
             D(pdu_to_tagged_stream, make))


        ;
}
