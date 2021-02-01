#
# Copyright 2021 Jacob Gilbert
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#
#

'''
Compatibility layer for transition to gr-pdu. Scheduled for removal in 3.11.
'''


from gnuradio import gr, pdu

byte_t = pdu.byte_t
float_t = pdu.float_t
complex_t = pdu.complex_t
vector_type = pdu.vector_type

class pdu_filter(pdu.pdu_filter):
    def __init__(self, *args, **kwargs):
        gr.log.warn('`pdu_filter` has moved to gr-pdu and will be removed from gr-blocks soon. Please update to use pdu.pdu_filter()')
        pdu.pdu_filter.__init__(self, *args, **kwargs)

class pdu_remove(pdu.pdu_remove):
    def __init__(self, *args, **kwargs):
        gr.log.warn('`pdu_remove` has moved to gr-pdu and will be removed from gr-blocks soon. Please update to use pdu.pdu_remove()')
        pdu.pdu_remove.__init__(self, *args, **kwargs)

class pdu_set(pdu.pdu_set):
    def __init__(self, *args, **kwargs):
        gr.log.warn('`pdu_set` has moved to gr-pdu and will be removed from gr-blocks soon. Please update to use pdu.pdu_set()')
        pdu.pdu_set.__init__(self, *args, **kwargs)

class pdu_to_tagged_stream(pdu.pdu_to_tagged_stream):
    def __init__(self, *args, **kwargs):
        gr.log.warn('`pdu_to_tagged_stream` has moved to gr-pdu and will be removed from gr-blocks soon. Please update to use pdu.pdu_to_tagged_stream()')
        pdu.pdu_to_tagged_stream.__init__(self, *args, **kwargs)

class random_pdu(pdu.random_pdu):
    def __init__(self, *args, **kwargs):
        gr.log.warn('`random_pdu` has moved to gr-pdu and will be removed from gr-blocks soon. Please update to use pdu.random_pdu()')
        pdu.random_pdu.__init__(self, *args, **kwargs)

class socket_pdu(pdu.socket_pdu):
    def __init__(self, *args, **kwargs):
        gr.log.warn('`socket_pdu` has moved to gr-pdu and will be removed from gr-blocks soon. Please update to use pdu.socket_pdu()')
        pdu.socket_pdu.__init__(self, *args, **kwargs)

class tagged_stream_to_pdu(pdu.tagged_stream_to_pdu):
    def __init__(self, *args, **kwargs):
        gr.log.warn('`tagged_stream_to_pdu` has moved to gr-pdu and will be removed from gr-blocks soon. Please update to use pdu.tagged_stream_to_pdu()')
        pdu.tagged_stream_to_pdu.__init__(self, *args, **kwargs)

class tuntap_pdu(pdu.tuntap_pdu):
    def __init__(self, *args, **kwargs):
        gr.log.warn('`tuntap_pdu` has moved to gr-pdu and will be removed from gr-blocks soon. Please update to use pdu.tuntap_pdu()')
        pdu.tuntap_pdu.__init__(self, *args, **kwargs)
