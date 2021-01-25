#PB-GHERKIN on a ESP32-S2 SAOLA WROVER
import board
from kmk.keys import KC
from kmk.kmk_keyboard import KMKKeyboard
from kmk.matrix import DiodeOrientation
from kmk.matrix import intify_coordinate as ic
from kmk.hid import HIDModes

gherkin = KMKKeyboard()

gherkin.col_pins = (board.IO1, board.IO2, board.IO3, board.IO4, board.IO5, board.IO6)
gherkin.row_pins = (board.IO7, board.IO8, board.IO9, board.IO10, board.IO11)

#Rotate gherkin so USB on Right Side. Not needed if USB on Left Side.
#gherkin.col_pins = tuple(reversed(gherkin.col_pins))
#gherkin.row_pins = tuple(reversed(gherkin.row_pins))

gherkin.diode_orientation = DiodeOrientation.COLUMNS

#coord_mapping to rearrange keys for PB_Gherkin PCB upside-down, not needed if PCB right side up.
#gherkin.coord_mapping = []
#gherkin.coord_mapping.extend(ic(1, x) for x in range(2, 6))
#gherkin.coord_mapping.extend(ic(0, x) for x in range(6))
#gherkin.coord_mapping.extend(ic(3, x) for x in range(4, 6))
#gherkin.coord_mapping.extend(ic(2, x) for x in range(6))
#gherkin.coord_mapping.extend(ic(1, x) for x in range(2))
#gherkin.coord_mapping.extend(ic(4, x) for x in range(6))
#gherkin.coord_mapping.extend(ic(3, x) for x in range(4))

gherkin.debug_enabled = False

gherkin.keymap = [
    [
        KC.Q,    KC.W,    KC.E,    KC.R,    KC.T,    KC.Y,    KC.U,    KC.I,    KC.O,    KC.P,
        KC.A,    KC.S,    KC.D,    KC.F,    KC.G,    KC.H,    KC.J,    KC.K,    KC.L,    KC.ESC,
        KC.MT(KC.Z, KC.LCTRL), KC.MT(KC.X, KC.LALT), KC.LT(3, KC.C), KC.LT(4, KC.V), KC.LT(2, KC.BSPC),
        KC.LT(1, KC.SPC),  KC.LT(5, KC.B), KC.MT(KC.N, KC.RALT), KC.MT(KC.M, KC.RCTRL), KC.MT(KC.ENT, KC.RSFT),
    ],
    [
        KC.N1,   KC.N2,   KC.N3,   KC.N4,   KC.N5,   KC.N6,   KC.N7,   KC.N8,   KC.N9,   KC.N0,
        KC.F1,   KC.F2,   KC.F3,   KC.F4,   KC.F5,   KC.F6,   KC.F7,   KC.F8,   KC.F9,   KC.F10,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.DEL,  KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
    ],
    [
        KC.EXLM, KC.AT,   KC.HASH, KC.DLR,  KC.PERC, KC.CIRC, KC.AMPR, KC.ASTR, KC.LPRN, KC.RPRN,
        KC.F11,  KC.F12,  KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.GRV,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
    ],
    [
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.MINS, KC.EQL,  KC.LBRC, KC.RBRC, KC.BSLS,
        KC.TAB,  KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.COMM, KC.DOT,  KC.SLSH, KC.SCLN, KC.QUOT,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.LEFT, KC.DOWN, KC.UP,   KC.RGHT,
    ],
    [
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.UNDS, KC.PLUS, KC.LCBR, KC.RCBR, KC.PIPE,
        KC.TAB,  KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.LABK, KC.RABK, KC.QUES, KC.COLN, KC.DQUO,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.HOME, KC.PGDN, KC.PGUP, KC.END,
    ],
    [
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
    ],
]

if __name__ == '__main__':
    gherkin.go(hid_type=HIDModes.USB) #Wired USB enable
    #gherkin.go(hid_type=HIDModes.BLE) #BLE enable