/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#include <avr/io.h>
#include "stdint.h"
#include "led.h"


void led_set(uint8_t usb_led)
{
    DDRD |= (1 << 6) | (1 << 5) | (1 << 3) | (1 << 0);
    DDRA |= (1 << 7);

    DDRD |= (1 << 6) | (1 << 5) | (1 << 3);

    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        PORTD |= (1 << 3);
    } else {
        PORTD &= ~(1 << 3);
    }

    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        PORTD |= (1 << 5);
    } else {
        PORTD &= ~(1 << 5);    
    }

    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        PORTD |= (1 << 6);
    } else {
        PORTD &= ~(1 << 6);
    }

    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        PORTA &= ~(1 << 7);
    } else {
        PORTA |= (1 << 7);
    }

    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        PORTD &= ~(1 << 0);
    } else {
        PORTD |= (1 << 0);
    }
}