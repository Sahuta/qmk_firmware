// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    QWERTY = 0,
    KANA_SYMBOLS,
    EISUU_SYMBOLS,
    FUNCTION
};

enum custom_keycodes {
    EISUU = SAFE_RANGE,
    KANA,
    VIM_ESC,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KANA:
            if(record->event.pressed) {
                layer_on(KANA_SYMBOLS);
                tap_code(KC_LANGUAGE_1);
            } else {
                layer_move(QWERTY);
            }
            return false;
        case EISUU:
            if (record->event.pressed) {
                layer_on(EISUU_SYMBOLS);
                tap_code(KC_LNG2);
            } else {
                layer_move(QWERTY);
            }
            return false;
        case VIM_ESC:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)SS_TAP(X_LNG2));
            }else{
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │       │ G │ H │ I │ J │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [QWERTY] = LAYOUT_ortho_4x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(FUNCTION, KC_ENT),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,   KC_RIGHT_BRACKET,
        VIM_ESC,    KC_LALT,    LCTL_T(KC_BSPC),   EISUU,    LSFT_T(KC_SPACE),  KANA,   LGUI_T(KC_DEL), QK_BOOT,  KC_RIGHT_BRACKET
    ),
    [KANA_SYMBOLS] = LAYOUT_ortho_4x10(
        LSFT(KC_1),    LSFT(KC_2),    LSFT(KC_3),    LSFT(KC_4),    LSFT(KC_5),    LSFT(KC_6),    LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),    LSFT(KC_0),
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_SLASH,    LSFT(KC_QUOTE),    KC_QUOTE,    KC_SEMICOLON,    KC_GRAVE,    KC_EQUAL,    KC_MINUS,    KC_COMM,    KC_DOT,    LSFT(KC_SLASH),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [EISUU_SYMBOLS] = LAYOUT_ortho_4x10(
        LSFT(KC_1),    LSFT(KC_2),    LSFT(KC_3),    LSFT(KC_4),    LSFT(KC_5),    LSFT(KC_6),    LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),    LSFT(KC_0),
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_BACKSLASH,    LSFT(KC_LEFT_BRACKET),    LSFT(KC_RIGHT_BRACKET),    LSFT(KC_SEMICOLON),    LSFT(KC_GRAVE),    LSFT(KC_EQUAL),   LSFT(KC_MINUS),    LSFT(KC_COMM),     LSFT(KC_DOT),    LSFT(KC_SLASH),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [FUNCTION] = LAYOUT_ortho_4x10(
        KC_F11,    KC_F12,    KC_F13,    KC_F14,    KC_F15,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_ENT,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_PRINT_SCREEN,    RCS(KC_P),    LGUI(KC_TAB),    KC_TAB,    KC_0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};