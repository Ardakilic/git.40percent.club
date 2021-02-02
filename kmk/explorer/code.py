#ESP32-S2 Saola WROVER / Raspberry Pi Pico / Adafruit NRF52840 Express
import board
from kmk.keys import KC
from kmk.kmk_keyboard import KMKKeyboard
from kmk.matrix import DiodeOrientation
from kmk.hid import HIDModes

kmkx = KMKKeyboard()

#ESP32-S2 Saola WROVER
#kmkx.col_pins = (board.IO0, board.IO1, board.IO2, board.IO3, board.IO4, board.IO5, board.IO6, board.IO7, board.IO8, board.IO9, board.IO10, board.IO11)
#kmkx.row_pins = (board.IO12, board.IO13, board.IO14, board.IO15)

#Raspberry Pi Pico
#kmkx.col_pins = (board.GP0, board.GP1, board.GP2, board.GP3, board.GP4, board.GP5, board.GP6, board.GP7, board.GP8, board.GP9, board.GP10, board.GP11)
#kmkx.row_pins = (board.GP18, board.GP19, board.GP20, board.GP21)

#Adafruit NRF52840 Express
kmkx.col_pins = (board.RX, board.TX, board.SDA, board.SCL, board.D7, board.D9, board.D10, board.D11, board.D12, board.D13, board.A4, board.A5)
kmkx.row_pins = (board.A0, board.A1, board.A2, board.A3)

kmkx.diode_orientation = DiodeOrientation.COLUMNS

kmkx.debug_enabled = False

kmkx.keymap = [
    [
        KC.ESC,  KC.Q,    KC.W,    KC.E,    KC.R,    KC.T,    KC.Y,    KC.U,    KC.I,    KC.O,    KC.P,    KC.BSPC,
        KC.LT(3, KC.TAB), KC.A,    KC.S,    KC.D,    KC.F,    KC.G,    KC.H,    KC.J,    KC.K,    KC.L,    KC.SCLN, KC.QUOT,
        KC.LSFT, KC.Z,    KC.X,    KC.C,    KC.V,    KC.B,    KC.N,    KC.M,    KC.COMM, KC.DOT,  KC.SLSH, KC.ENT,
        KC.LCTL, KC.LALT, KC.LGUI, KC.APP,  KC.MO(2),KC.SPC,  KC.SPC,  KC.MO(1),KC.LEFT, KC.DOWN, KC.UP,   KC.RGHT,
    ],
    [
        KC.GRV,  KC.N1,   KC.N2,   KC.N3,   KC.N4,   KC.N5,   KC.N6,   KC.N7,   KC.N8,   KC.N9,   KC.N0,   KC.DEL,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.MINS, KC.EQL,  KC.LBRC, KC.RBRC, KC.BSLS,
        KC.TRNS, KC.F11,  KC.F12,  KC.F13,  KC.F14,  KC.F15,  KC.F16,  KC.F17,  KC.F18,  KC.F19,  KC.F20,  KC.TRNS,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.CAPS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.HOME, KC.PGDN, KC.PGUP, KC.END,
    ],
    [
        KC.TILD, KC.EXLM, KC.AT,   KC.HASH, KC.DLR,  KC.PERC, KC.CIRC, KC.AMPR, KC.ASTR, KC.LPRN, KC.RPRN, KC.DEL,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.UNDS, KC.PLUS, KC.LCBR, KC.RCBR, KC.PIPE,
        KC.TRNS, KC.F1,   KC.F2,   KC.F3,   KC.F4,   KC.F5,   KC.F6,   KC.F7,   KC.F8,   KC.F9,   KC.F10,  KC.TRNS,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.CAPS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.HOME, KC.PGDN, KC.PGUP, KC.END,
    ],
    [
        KC.ESC,  KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.PSCR, KC.TRNS,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
        KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
    ],
]

if __name__ == '__main__':
    kmkx.go(hid_type=HIDModes.USB) #Wired USB enable
	#kmkx.go(hid_type=HIDModes.BLE) #BLE enable