/*
Copyright 2024 Zykrah

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "quantum.h"


// Code for Caps Locks indicator
#if defined(RGB_MATRIX_ENABLE)

bool rgb_matrix_indicators_user(void) {
    led_t led_state = host_keyboard_led_state();
    uint8_t b = 0xFF;

#if defined(CAPS_LOCK_LED_INDEX_1) && defined(CAPS_LOCK_LED_INDEX_2)
    if (led_state.caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX_1, b, b, b);
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX_2, b, b, b);
    } else {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX_1, 0, 0, 0);
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX_2, 0, 0, 0);
    }
#endif

#ifdef SCROLL_LOCK_LED_INDEX
    if (led_state.scroll_lock) {
        rgb_matrix_set_color(SCROLL_LOCK_LED_INDEX, b, b, b);
    } else {
        rgb_matrix_set_color(SCROLL_LOCK_LED_INDEX, 0, 0, 0);
    }
    return false;
#endif
}

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
    }, {
        // LED Index to Physical Position |
        // 0..224: 0, 14, 28, 42, 56, 70, 84, 98, 112, 126, 140, 154, 168, 182, 196, 210, 224
        // 0..64: 0, 16, 32, 48, 64
        { 48, 210}, { 32, 210}, { 16, 210},
        {  0, 210}, { 16, 196}, {0,0}, { 32, 182}, {  0, 168}, { 16, 154}, { 32, 140}, {  0, 126}, { 16, 112}, { 32,  98}, {  0,  70}, { 16,  56}, { 32,  48}, {  0,  28}, { 16,  14}, { 32,   0},
        { 16,   0}, { 32,   0}, {0,0}, {0,0}, { 48,   0},
        { 64,   0}, { 64,  14}, { 64,  28}, { 64,  42},  { 64,  56}, { 64,  70}, { 64,  84}, { 64,  98}, { 64, 112}, { 64, 126}, { 64, 140}, { 64, 154}, { 64, 168}, { 64, 182}, { 64, 196}, { 64, 210}
    }, {
        // LED Index to Flag
        2, 2, 2,                                        // UNDERGLOW: RIGHT MIDDLE
        2, 2, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // UNDERGLOW: TOP
        2, 2, 8, 8, 2,                                  // UNDERGLOW: LEFT MIDDLE
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2  // UNDERGLOW: BOTTOM
    }
};

#endif
