// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY = 0,
    _KANA_SYMBOLS,
    _EISUU_SYMBOLS,
    _FUNCTION,
    _MACROS,
    _GREEK,
    _DEVICE
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EISUU,
    KANA,
    VIM_ESC,
    ALPHA,
    BETA,
    GAMMA,
    DELTA,
    EPSILON,
    ZETA,
    ETA,
    THETA,
    IOTA,
    KAPPA,
    LAMBDA,
    MU,
    NU,
    XI,
    OMICRON,
    PI,
    RHO,
    SIGMA,
    TAU,
    UPSILON,
    PHI,
    CHI,
    PSI,
    OMEGA,
    INLINE,
    BLOCK,
    GATHER,
    FRAC,
    SQRT,
    LR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │       │ G │ H │ I │ J │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_QWERTY] = LAYOUT_ortho_4x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(_FUNCTION, KC_ENT),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,   KC_LEFT_BRACKET,
        VIM_ESC,    KC_LALT,    LCTL_T(KC_BSPC),   EISUU,    LSFT_T(KC_SPACE),  KANA,   LGUI_T(KC_DEL), KC_TAB,  KC_RIGHT_BRACKET
    ),
    [_KANA_SYMBOLS] = LAYOUT_ortho_4x10(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_BACKSLASH,    LSFT(KC_LEFT_BRACKET),    LSFT(KC_RIGHT_BRACKET),    LSFT(KC_6),  LSFT(KC_4),    LSFT(KC_3),    KC_MINUS,    KC_QUOTE,    KC_SEMICOLON,    KC_SLASH,
        LSFT(KC_1),    LSFT(KC_COMM),    LSFT(KC_DOT),   KC_EQUAL,    KC_GRAVE,    LSFT(KC_EQUAL),    LSFT(KC_MINUS),    LSFT(KC_BACKSLASH),    LSFT(KC_SEMICOLON),    LSFT(KC_SLASH),
        KC_TRNS, KC_TRNS, KC_TRNS, MO(_MACROS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_GREEK)
    ),
    [_EISUU_SYMBOLS] = LAYOUT_ortho_4x10(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_BACKSLASH,    LSFT(KC_LEFT_BRACKET),    LSFT(KC_RIGHT_BRACKET),    LSFT(KC_6),  LSFT(KC_4),    LSFT(KC_3),    KC_MINUS,    KC_QUOTE,    KC_SEMICOLON,    KC_SLASH,
        LSFT(KC_1),    LSFT(KC_COMM),    LSFT(KC_DOT),   KC_EQUAL,    KC_GRAVE,    LSFT(KC_EQUAL),    LSFT(KC_MINUS),    LSFT(KC_BACKSLASH),    LSFT(KC_SEMICOLON),    LSFT(KC_SLASH),
        MO(_GREEK), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  MO(_MACROS), KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FUNCTION] = LAYOUT_ortho_4x10(
        KC_F11,    KC_F12,    KC_F13,    KC_F14,    KC_F15,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_ENT,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_PRINT_SCREEN,    RCS(KC_P),    LGUI(KC_TAB),    KC_TAB,    KC_0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_DEVICE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_MACROS] = LAYOUT_ortho_4x10(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        SQRT, FRAC, GATHER, INLINE, BLOCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, LR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_GREEK] = LAYOUT_ortho_4x10(
        KC_TRNS,KC_TRNS, EPSILON, RHO, TAU, UPSILON, THETA, IOTA, OMICRON, PI,
        ALPHA, SIGMA, DELTA, PHI, GAMMA, ETA, XI, KAPPA, LAMBDA, KC_TRNS,
        ZETA, CHI, PSI, OMEGA, BETA, NU, MU, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_DEVICE] = LAYOUT_ortho_4x10(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_CLEAR_EEPROM, QK_BOOT
    )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                layer_move(_QWERTY);
            }
            return false;
            break;
        case KANA:
            if(record->event.pressed) {
                layer_on(_KANA_SYMBOLS);
                tap_code(KC_LANGUAGE_1);
            } else {
                layer_move(_QWERTY);
            }
            return false;
            break;
        case EISUU:
            if (record->event.pressed) {
                layer_on(_EISUU_SYMBOLS);
                tap_code(KC_LANGUAGE_2);
            } else {
                layer_move(_QWERTY);
            }
            return false;
            break;
        case VIM_ESC:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)SS_TAP(X_LANGUAGE_2));
            }else{
            }
            return false;
            break;
        case ALPHA:
            if (record->event.pressed) {
                SEND_STRING("\\alpha");
            } else {
            }
            return false;
            break;
        case BETA:
            if (record->event.pressed) {
                SEND_STRING("\\beta");
            } else {
            }
            return false;
            break;
        case GAMMA:
            if (record->event.pressed) {
                SEND_STRING("\\gamma");
            } else {
            }
            return false;
            break;
        case DELTA:
            if (record->event.pressed) {
                SEND_STRING("\\delta");
            } else {
            }
            return false;
            break;
        case EPSILON:
            if (record->event.pressed) {
                SEND_STRING("\\epsilon");
            } else {
            }
            return false;
            break;
        case ZETA:
            if (record->event.pressed) {
                SEND_STRING("\\zeta");
            } else {
            }
            return false;
            break;
        case ETA:
            if (record->event.pressed) {
                SEND_STRING("\\eta");
            } else {
            }
            return false;
            break;
        case THETA:  
            if (record->event.pressed) {
                SEND_STRING("\\theta");
            } else {
            }
            return false;
            break;
        case IOTA:
            if (record->event.pressed) {
                SEND_STRING("\\iota");
            } else {
            }
            return false;
            break;
        case KAPPA:
            if (record->event.pressed) {
                SEND_STRING("\\kappa");
            } else {
            }
            return false;
            break;
        case LAMBDA:
            if (record->event.pressed) {
                SEND_STRING("\\lambda");
            } else {
            }
            return false;
            break;
        case MU:
            if (record->event.pressed) {
                SEND_STRING("\\mu");
            } else {
            }
            return false;
            break;
        case NU:
            if (record->event.pressed) {
                SEND_STRING("\\nu");
            } else {
            }
            return false;
            break;
        case XI:    
            if (record->event.pressed) {
                SEND_STRING("\\xi");
            } else {
            }
            return false;
            break; 
        case OMICRON:
            if (record->event.pressed) {
                SEND_STRING("\\omicron");
            } else {
            }
            return false;
            break;
        case PI:
            if (record->event.pressed) {
                SEND_STRING("\\pi");
            } else {
            }
            return false;
            break;
        case RHO:
            if (record->event.pressed) {
                SEND_STRING("\\rho");
            } else {
            }
            return false;
            break;
        case SIGMA:
            if (record->event.pressed) {
                SEND_STRING("\\sigma");
            } else {
            }
            return false;
            break;
        case TAU:  
            if (record->event.pressed) {
                SEND_STRING("\\tau");
            } else {
            }
            return false;
            break;
        case UPSILON:
            if (record->event.pressed) {
                SEND_STRING("\\upsilon");
            } else {
            }
            return false;
            break;
        case PHI:
            if (record->event.pressed) {
                SEND_STRING("\\phi");
            } else {
            }
            return false;
            break;
        case CHI:
            if (record->event.pressed) {
                SEND_STRING("\\chi");
            } else {
            }
            return false;
            break;
        case PSI:
            if (record->event.pressed) {
                SEND_STRING("\\psi");
            } else {
            }
            return false;
            break;
        case OMEGA:
            if (record->event.pressed) {
                SEND_STRING("\\omega");
            } else {
            }
            return false;
            break;
        case INLINE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LANGUAGE_2)"$$"SS_TAP(X_LEFT));
            } else {
            }
            return false;
            break;
        case BLOCK:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LANGUAGE_2)"$$"SS_TAP(X_ENT)"\\begin{aligned}"SS_TAP(X_ENT)SS_TAP(X_ENT)"\\end{aligned}"SS_TAP(X_ENT)"$$"SS_TAP(X_UP)SS_TAP(X_UP));
            } else {
            }
            return false;
            break;
        case GATHER:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LANGUAGE_2)"$$"SS_TAP(X_ENT)"\\begin{gather}"SS_TAP(X_ENT)SS_TAP(X_ENT)"\\end{gather}"SS_TAP(X_ENT)"$$"SS_TAP(X_UP)SS_TAP(X_UP));
            } else {
            }
            return false;
            break;
        case FRAC:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LANGUAGE_2)"\\frac{}{}"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            } else {
            }
            return false;
        case SQRT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LANGUAGE_2)"\\sqrt{}"SS_TAP(X_LEFT));
            } else {
            }
            return false;
            break;
        case LR:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LANGUAGE_2)"\\left\\right"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            } else {
            }
            return false;
            break;
    }
    return true;
}
