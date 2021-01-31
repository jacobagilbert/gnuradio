# Copyright 2021 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Install header files
########################################################################
install(FILES
    api.h
    pdu_frequency_modulator_fc.h
    pdu_split.h
    pdu.h
    DESTINATION ${GR_INCLUDE_DIR}/gnuradio/pdu
)

