import board

from kmk.keys import KC
from kmk.kmk_keyboard import KMKKeyboard
from kmk.matrix import DiodeOrientation

keyboard = KMKKeyboard()

keyboard.col_pins = (board.LED2_R, board.LED2_G, board.LED2_B)
keyboard.row_pins = (board.SW1, board.P1_10)

keyboard.diode_orientation = DiodeOrientation.COLUMNS

keyboard.debug_enabled = False


keyboard.keymap = [
    [
        KC.A,   KC.NO,    KC.NO,    KC.NO,    KC.NO,    KC.NO,
    ],
]

if __name__ == '__main__':
    keyboard.go()