#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_MSG msg.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_RECORD record.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_LE_OOB_REC le_oob_rec.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_LE_OOB_REC_PARSER le_oob_rec_parser.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_TEXT_RECORD text_rec.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_URI_MSG uri_msg.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_URI_REC uri_rec.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_CH_REC ch.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_CH_MSG ch_msg.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_PARSER msg_parser.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_PARSER msg_parser_local.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_PAYLOAD_TYPE_COMMON payload_type_common.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_PARSER record_parser.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_TNEP_RECORD tnep_rec.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_CH_PARSER ch_rec_parser.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_LAUNCHAPP_MSG launchapp_msg.c)
zephyr_library_sources_ifdef(CONFIG_NFC_NDEF_LAUNCHAPP_REC launchapp_rec.c)
