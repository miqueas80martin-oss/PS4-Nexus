# SPDX-License-Identifier: GPL-2.0-or-later

add_library(mobile STATIC
    mobile_graphics.cpp
)

target_link_libraries(mobile PUBLIC core common)