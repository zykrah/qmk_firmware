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

void matrix_init_kb(void) {
    gpio_set_pin_output(GP28);  // Caps Lock LED
    gpio_set_pin_output(GP13);  // Scroll Lock LED
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        gpio_write_pin(GP28, led_state.caps_lock);    // Caps Lock LED
        gpio_write_pin(GP13, led_state.scroll_lock);  // Scroll Lock LED
    }
    return res;
}

#ifdef RGB_MATRIX_ENABLE
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
        {  0, 210}, { 16, 196}, { 32, 182}, {  0, 168}, { 16, 154}, { 32, 140}, {  0, 126}, { 16, 112}, { 32,  98}, {  0,  70}, { 16,  56}, { 32,  48}, {  0,  28}, { 16,  14}, { 32,   0},
        { 16,   0}, { 32,   0}, { 48,   0},
        { 64,   0}, { 64,  14}, { 64,  28}, { 64,  42},  { 64,  56}, { 64,  70}, { 64,  84}, { 64,  98}, { 64, 112}, { 64, 126}, { 64, 140}, { 64, 154}, { 64, 168}, { 64, 182}, { 64, 196}, { 64, 210}
    }, {
        // LED Index to Flag
        2, 2, 2,                                        // UNDERGLOW: RIGHT MIDDLE
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,    // UNDERGLOW: TOP
        2, 2, 2,                                        // UNDERGLOW: LEFT MIDDLE
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2  // UNDERGLOW: BOTTOM
    }
};
#endif
