#
# Copyright (c) 2021 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

zephyr_include_directories(.)
target_sources_ifdef(CONFIG_FEM app
			PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fem.c)
target_sources_ifdef(CONFIG_NRF21540_FEM app
			PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/nrf21540.c)
target_sources_ifdef(CONFIG_GENERIC_FEM app
			PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/generic_fem.c)
