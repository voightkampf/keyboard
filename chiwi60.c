// Voight-Kampff 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define NO_DEBUG
#define NO_PRINT

// rules.mk
# Bootloader selection
BOOTLOADER = atmel-dfu

SLEEP_LED_ENABLE = yes // to rules
// rules.mk


enum custom_layers {
    _BASE,        // Base layer
    _LAYER1,      // First layer (MO(1))
    _LAYER2,      // Second layer (MO(2))
    _TRILAYER     // Third layer (MO(1) + MO(2))
};

// Custom keycodes (if needed)
enum custom_keycodes {
    // Add custom keycodes here, if needed
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    // Base Layer
    [_BASE] = LAYOUT_60_ansi(
        KC_GESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        MO(3),      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,
        KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,
        KC_LCTL,    KC_LALT,    KC_LGUI,                                        KC_SPC,                                         KC_RGUI,    KC_RALT,    MO(1),      MO(2)
    ),
    // Fn1 Layer
    [_LAYER1] = LAYOUT_60_ansi(
	    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,
	    KC_CAPS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PSCR,    KC_SCRL,    KC_PAUS,    KC_UP,      _______,    _______,
	    _______,    KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_EJCT,    _______,    KC_PAST,    KC_PSLS,    KC_HOME,    KC_PGUP,    KC_LEFT,    KC_RGHT,                _______,
	    _______,    _______,    _______,    _______,    _______,    _______,    KC_PPLS,    KC_PMNS,    KC_END,     KC_PGDN,    KC_DOWN,    _______,                _______,
	    _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    _______
    ),
    [_LAYER2] = LAYOUT_60_ansi(
	    KC_ESC,     BL_TOGG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
	    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
	    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,
	    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,
	    _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    _______
    ),
    [_TRILAYER] = LAYOUT_60_ansi(
	    QK_BOOTLOADER,      QK_CLEAR_EEPROM,    QK_REBOOT,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
	    _______,            _______,            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
	    _______,            _______,            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,
	    _______,            _______,            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,
	    _______,            _______,            _______,                                        _______,                                        _______,    _______,    _______,    _______
    ),
};


void matrix_scan_user(void) {
    // Update tri-layer: FN_LAYER + CONTROL_LAYER = TRILAYER
    update_tri_layer(_LAYER1, _LAYER2, _TRILAYER);
}




