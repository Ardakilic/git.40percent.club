#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

KEYMAP(
    Q,      W,      E,      R,      T,      Y,      U,      I,      O,      P, \
    A,      S,      D,      F,      G,      H,      J,      K,      L,      ESC, \
    FN6,    FN7,    FN2,    FN3,    FN4,    FN8,    FN10,   FN1,    FN0,    FN5
),

KEYMAP(
    1,      2,      3,      4,      5,      6,      7,      8,      9,      0, \
    F1,     F2,     F3,     F4,     F5,     F6,     F7,     F8,     F9,     F10, \
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   DEL,    TRNS,   TRNS
),

KEYMAP(
    FN11,   FN12,   FN13,   FN14,   FN15,   FN16,   FN17,   FN18,   FN19,   FN20, \
    F11,    F12,    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   GRV, \
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS
),

KEYMAP(
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   MINS,   EQL,    LBRC,   RBRC,   BSLS, \
    TAB,    TRNS,   CAPS,   TRNS,   TRNS,   COMM,   DOT,    SLSH,   SCLN,   QUOT, \
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   LEFT,   DOWN,   UP,     RGHT
),

KEYMAP(
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   FN21,   FN22,   FN23,   FN24,   FN25, \
    TAB,    TRNS,   CAPS,   TRNS,   TRNS,   FN26,   FN27,   FN28,   FN29,   FN30, \
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   HOME,   PGDN,   PGUP,   END
),

KEYMAP(
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   PSCR, \
    TRNS,   TRNS,   CAPS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS, \
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS
),
};

const action_t PROGMEM fn_actions[] = {
	[0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
	[1] = ACTION_LAYER_TAP_KEY(2, KC_BSPACE),
	[2] = ACTION_LAYER_TAP_KEY(3, KC_C),
	[3] = ACTION_LAYER_TAP_KEY(4, KC_V),
	[4] = ACTION_LAYER_TAP_KEY(5, KC_B),
	[5] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
	[6] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_Z),
	[7] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_X),
	[8] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_N),
	[10] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_M),
	[11] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
	[12] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
	[13] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
	[14] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
	[15] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
	[16] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
	[17] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
	[18] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
	[19] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
	[20] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
	[21] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
	[22] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),
	[23] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
	[24] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
	[25] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
	[26] = ACTION_MODS_KEY(MOD_LSFT, KC_COMM),
	[27] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT),
	[28] = ACTION_MODS_KEY(MOD_LSFT, KC_SLSH),
	[29] = ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),
	[30] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),
};

