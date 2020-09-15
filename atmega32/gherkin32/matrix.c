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

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"

#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{

    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

/* Column pin configuration
 * col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29
 * pin: B0, B2, B4, B6, D0, D3, D6, C0, C2, C4, B1, B3, B5, B7, D1, D5, D7, C1, C3, C5, A0, A1, A2, A3, A4, A5, A6, A7, C7, C6
 */
 
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRA  &= ~0b11111111;
    PORTA |=  0b11111111;
    DDRB  &= ~0b11111111;
    PORTB |=  0b11111111;
    DDRC  &= ~0b11111111;
    PORTC |=  0b11111111;
    DDRD  &= ~0b11101011;
    PORTD |=  0b11101011;
}

static matrix_row_t read_cols(void)
{
    return 
	(PINB&(1<<0) ? 0 : (1UL<<0)) |
	(PINB&(1<<2) ? 0 : (1UL<<1)) |
	(PINB&(1<<4) ? 0 : (1UL<<2)) |
	(PINB&(1<<6) ? 0 : (1UL<<3)) |
	(PIND&(1<<0) ? 0 : (1UL<<4)) |
	(PIND&(1<<3) ? 0 : (1UL<<5)) |
	(PIND&(1<<6) ? 0 : (1UL<<6)) |
	(PINC&(1<<0) ? 0 : (1UL<<7)) |
	(PINC&(1<<2) ? 0 : (1UL<<8)) |
	(PINC&(1<<4) ? 0 : (1UL<<9)) |
	(PINB&(1<<1) ? 0 : (1UL<<10)) |
	(PINB&(1<<3) ? 0 : (1UL<<11)) |
	(PINB&(1<<5) ? 0 : (1UL<<12)) |
	(PINB&(1<<7) ? 0 : (1UL<<13)) |
	(PIND&(1<<1) ? 0 : (1UL<<14)) |
	(PIND&(1<<5) ? 0 : (1UL<<15)) |
	(PIND&(1<<7) ? 0 : (1UL<<16)) |
	(PINC&(1<<1) ? 0 : (1UL<<17)) |
	(PINC&(1<<3) ? 0 : (1UL<<18)) |
	(PINC&(1<<5) ? 0 : (1UL<<19)) |
	(PINA&(1<<0) ? 0 : (1UL<<20)) |
	(PINA&(1<<1) ? 0 : (1UL<<21)) |
	(PINA&(1<<2) ? 0 : (1UL<<22)) |
	(PINA&(1<<3) ? 0 : (1UL<<23)) |
	(PINA&(1<<4) ? 0 : (1UL<<24)) |
	(PINA&(1<<5) ? 0 : (1UL<<25)) |
	(PINA&(1<<6) ? 0 : (1UL<<26)) |
	(PINA&(1<<7) ? 0 : (1UL<<27)) |
	(PINC&(1<<7) ? 0 : (1UL<<28)) |
	(PINC&(1<<6) ? 0 : (1UL<<29));
}

/* Row pin configuration
 * row: 0   1   2   3   4 
 * pin: B6, B2, B3, B1, F7
 */
 
static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
}

static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
}
