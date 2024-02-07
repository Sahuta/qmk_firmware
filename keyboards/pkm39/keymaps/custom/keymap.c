// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KANA_LAYER= SAFE_RANGE,
    EISUU_LAYER,
    VIM_ESC,
};

bool is_kana_key_active = false;
bool is_eisuu_key_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KANA_LAYER: // かなキーのキーコードに置き換えてください
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    // キーをタップした場合の処理（かなキーを入力）
                    if (!is_kana_key_active) {
                        register_code(KC_LNG1); // かなキーを入力するキーコードに置き換えてください
                        is_kana_key_active = true;
                    }
                } else {
                    // キーを長押ししている間の処理（かなキーを入力してレイヤーを切り替える）
                    register_code(KC_LNG1); // かなキーを入力するキーコードに置き換えてください
                    layer_on(1); // レイヤー1をアクティベート
                    is_kana_key_active = true;
                }
            } else {
                // キーが離されたときの処理
                unregister_code(KC_LNG1); // かなキーのリリース
                layer_off(1); // レイヤー1を非アクティベート
                is_kana_key_active = false;
            }
            break;
        case EISUU_LAYER:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    if (!is_eisuu_key_active) {
                        register_code(KC_LNG2);
                        is_eisuu_key_active = true;
                    }
                } else {
                    // キーを長押ししている間の処理（かなキーを入力してレイヤーを切り替える）
                    register_code(KC_LNG2); 
                    layer_on(2); // レイヤー2をアクティベート
                    is_eisuu_key_active = true;
                }
            } else {
                // キーが離されたときの処理
                unregister_code(KC_LNG2);
                layer_off(2);
                is_eisuu_key_active = false;
            }
            break;
        case VIM_ESC:
            if (record->event.pressed) {
                register_code(KC_LNG2);
                register_code(KC_ESC);
                unregister_code(KC_ESC);
                unregister_code(KC_LNG2);
            }
            break;
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
    [0] = LAYOUT_ortho_4x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(3, KC_ENT),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,    KC_LEFT_BRACKET,
        VIM_ESC,    KC_LALT,    LCTL_T(KC_BSPC),    EISUU_LAYER,    LSFT_T(KC_SPACE),  KANA_LAYER,     LGUI_T(KC_DEL), QK_BOOT,  KC_RIGHT_BRACKET
    ),
    [1] = LAYOUT_ortho_4x10(
        LSFT(KC_1),    LSFT(KC_2),    LSFT(KC_3),    LSFT(KC_4),    LSFT(KC_5),    LSFT(KC_6),    LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),    LSFT(KC_0),
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_SLASH,    LSFT(KC_QUOTE),    KC_QUOTE,    KC_SEMICOLON,    KC_GRAVE,    KC_EQUAL,    KC_MINUS,    KC_COMM,    KC_DOT,    LSFT(KC_SLASH),
        KC_ESC,    KC_LALT,    LCTL_T(KC_BSPC),    LT(2, KC_LNG2),    LSFT_T(KC_SPACE),  LT(1, KC_LNG1),    LGUI_T(KC_DEL),  KC_TAB,  KC_RIGHT_BRACKET
    ),
    [2] = LAYOUT_ortho_4x10(
        LSFT(KC_1),    LSFT(KC_2),    LSFT(KC_3),    LSFT(KC_4),    LSFT(KC_5),    LSFT(KC_6),    LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),    LSFT(KC_0),
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_BACKSLASH,    LSFT(KC_LEFT_BRACKET),    LSFT(KC_RIGHT_BRACKET),    LSFT(KC_SEMICOLON),    LSFT(KC_GRAVE),    LSFT(KC_EQUAL),   LSFT(KC_MINUS),    LSFT(KC_COMM),     LSFT(KC_DOT),    LSFT(KC_SLASH),
        KC_ESC,    KC_LALT,    LCTL_T(KC_BSPC),    LT(2, KC_LNG2),    LSFT_T(KC_SPACE),  LT(1, KC_LNG1),    LGUI_T(KC_DEL),  KC_TAB,  KC_RIGHT_BRACKET
    ),
    [3] = LAYOUT_ortho_4x10(
        KC_F11,    KC_F12,    KC_F13,    KC_F14,    KC_F15,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_ENT,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_PRINT_SCREEN,    RCS(KC_P),    LGUI(KC_TAB),    KC_TAB,    KC_0,
        KC_ESC,    KC_LALT,    LCTL_T(KC_BSPC),    LT(2, KC_LNG2),    LSFT_T(KC_SPACE),  LT(1, KC_LNG1), KC_DEL, KC_TAB,  KC_RIGHT_BRACKET
    )
};
