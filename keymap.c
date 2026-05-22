// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "ocean_dream.h"

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,-------------------------------------------.   ,-------------------------------------------.
 * |  `   |  1  |  2  |  3  |  4  |  5  |      |   |      |  6  |  7  |  8  |  9  |  0  |  `   |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * | ESC  |  Q  |  W  |  E  |  R  |  T  |      |   |      |  Y  |  U  |  I  |  O  |  P  | Bspc |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * | Tab  |  A  |  S  |  D  |  F  |  G  | MUTE |   |      |  H  |  J  |  K  |  L  |  ;  |  '   |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * |LShift|  Z  |  X  |  C  |  V  |  B  |      |   |      |  N  |  M  |  ,  |  .  |  /  |RShift|
 * `------------------------------------------/    \------------------------------------------'
 *              | LGUI | LAlt | LCTR | LOWER | /Enter/  \Space\ |RAISE | RCTR | RAlt | RGUI |
 *              `------+------+------+------+/       \       \------+------+------+------'
 */
[_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_ENT,  KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),

/*
 * LOWER — Numbers, symbols, F keys
 */
[_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,  KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/*
 * RAISE — Navigation, media
 */
[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
    _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                   KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______, _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/*
 * ADJUST — RGB, media playback, reset
 */
[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
)
};

// Encoder mappings: left = volume, right = page up/down
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_LOWER]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
};
#endif

// OLED setup
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static uint32_t oled_timer = 0;

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Layer"), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:  oled_write_P(PSTR("BASE "), false); break;
            case _LOWER:   oled_write_P(PSTR("LOWER"), false); break;
            case _RAISE:   oled_write_P(PSTR("RAISE"), false); break;
            case _ADJUST:  oled_write_P(PSTR("ADJST"), false); break;
            default:       oled_write_P(PSTR("?????"), false); break;
        }
    } else {
        if (timer_elapsed32(oled_timer) > 16) {
            oled_timer = timer_read32();
            render_ocean_dream();
        }
    }
    return false;
}

#endif

// Pass ctrl press to Ocean Dream (makes waves go calm)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            is_calm = record->event.pressed;
            break;
    }
    return true;
}// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "ocean_dream.h"

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,-------------------------------------------.   ,-------------------------------------------.
 * |  `   |  1  |  2  |  3  |  4  |  5  |      |   |      |  6  |  7  |  8  |  9  |  0  |  `   |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * | ESC  |  Q  |  W  |  E  |  R  |  T  |      |   |      |  Y  |  U  |  I  |  O  |  P  | Bspc |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * | Tab  |  A  |  S  |  D  |  F  |  G  | MUTE |   |      |  H  |  J  |  K  |  L  |  ;  |  '   |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * |LShift|  Z  |  X  |  C  |  V  |  B  |      |   |      |  N  |  M  |  ,  |  .  |  /  |RShift|
 * `------------------------------------------/    \------------------------------------------'
 *              | LGUI | LAlt | LCTR | LOWER | /Enter/  \Space\ |RAISE | RCTR | RAlt | RGUI |
 *              `------+------+------+------+/       \       \------+------+------+------'
 */
[_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_ENT,  KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),

/*
 * LOWER — Numbers, symbols, F keys
 */
[_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,  KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/*
 * RAISE — Navigation, media
 */
[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
    _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                   KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______, _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/*
 * ADJUST — RGB, media playback, reset
 */
[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
)
};

// Encoder mappings: left = volume, right = page up/down
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_LOWER]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
};
#endif

// OLED setup
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static uint32_t oled_timer = 0;

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Layer"), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:  oled_write_P(PSTR("BASE "), false); break;
            case _LOWER:   oled_write_P(PSTR("LOWER"), false); break;
            case _RAISE:   oled_write_P(PSTR("RAISE"), false); break;
            case _ADJUST:  oled_write_P(PSTR("ADJST"), false); break;
            default:       oled_write_P(PSTR("?????"), false); break;
        }
    } else {
        if (timer_elapsed32(oled_timer) > 16) {
            oled_timer = timer_read32();
            render_ocean_dream();
        }
    }
    return false;
}

#endif

// Pass ctrl press to Ocean Dream (makes waves go calm)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            is_calm = record->event.pressed;
            break;
    }
    return true;
}// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "ocean_dream.h"

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,-------------------------------------------.   ,-------------------------------------------.
 * |  `   |  1  |  2  |  3  |  4  |  5  |      |   |      |  6  |  7  |  8  |  9  |  0  |  `   |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * | ESC  |  Q  |  W  |  E  |  R  |  T  |      |   |      |  Y  |  U  |  I  |  O  |  P  | Bspc |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * | Tab  |  A  |  S  |  D  |  F  |  G  | MUTE |   |      |  H  |  J  |  K  |  L  |  ;  |  '   |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * |LShift|  Z  |  X  |  C  |  V  |  B  |      |   |      |  N  |  M  |  ,  |  .  |  /  |RShift|
 * `------------------------------------------/    \------------------------------------------'
 *              | LGUI | LAlt | LCTR | LOWER | /Enter/  \Space\ |RAISE | RCTR | RAlt | RGUI |
 *              `------+------+------+------+/       \       \------+------+------+------'
 */
[_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_ENT,  KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),

/*
 * LOWER — Numbers, symbols, F keys
 */
[_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,  KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/*
 * RAISE — Navigation, media
 */
[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
    _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                   KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______, _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/*
 * ADJUST — RGB, media playback, reset
 */
[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
)
};

// Encoder mappings: left = volume, right = page up/down
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_LOWER]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
};
#endif

// OLED setup
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static uint32_t oled_timer = 0;

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Layer"), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:  oled_write_P(PSTR("BASE "), false); break;
            case _LOWER:   oled_write_P(PSTR("LOWER"), false); break;
            case _RAISE:   oled_write_P(PSTR("RAISE"), false); break;
            case _ADJUST:  oled_write_P(PSTR("ADJST"), false); break;
            default:       oled_write_P(PSTR("?????"), false); break;
        }
    } else {
        if (timer_elapsed32(oled_timer) > 16) {
            oled_timer = timer_read32();
            render_ocean_dream();
        }
    }
    return false;
}

#endif

// Pass ctrl press to Ocean Dream (makes waves go calm)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            is_calm = record->event.pressed;
            break;
    }
    return true;
}// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "ocean_dream.h"

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,-------------------------------------------.   ,-------------------------------------------.
 * |  `   |  1  |  2  |  3  |  4  |  5  |      |   |      |  6  |  7  |  8  |  9  |  0  |  `   |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * | ESC  |  Q  |  W  |  E  |  R  |  T  |      |   |      |  Y  |  U  |  I  |  O  |  P  | Bspc |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * | Tab  |  A  |  S  |  D  |  F  |  G  | MUTE |   |      |  H  |  J  |  K  |  L  |  ;  |  '   |
 * |------+------+-----+-----+-----+------------|   |------+-----+-----+-----+-----+-----+------|
 * |LShift|  Z  |  X  |  C  |  V  |  B  |      |   |      |  N  |  M  |  ,  |  .  |  /  |RShift|
 * `------------------------------------------/    \------------------------------------------'
 *              | LGUI | LAlt | LCTR | LOWER | /Enter/  \Space\ |RAISE | RCTR | RAlt | RGUI |
 *              `------+------+------+------+/       \       \------+------+------+------'
 */
[_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_ENT,  KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),

/*
 * LOWER — Numbers, symbols, F keys
 */
[_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,  KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/*
 * RAISE — Navigation, media
 */
[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
    _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                   KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______, _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/*
 * ADJUST — RGB, media playback, reset
 */
[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
)
};

// Encoder mappings: left = volume, right = page up/down
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_LOWER]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
};
#endif

// OLED setup
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Master side: show layer info
        oled_write_P(PSTR("Layer"), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:  oled_write_P(PSTR("BASE "), false); break;
            case _LOWER:   oled_write_P(PSTR("LOWER"), false); break;
            case _RAISE:   oled_write_P(PSTR("RAISE"), false); break;
            case _ADJUST:  oled_write_P(PSTR("ADJST"), false); break;
            default:       oled_write_P(PSTR("?????"), false); break;
        }
    } else {
        // Slave side: ocean dream animation
        render_ocean_dream();
    }
    return false;
}
#endif

// Pass ctrl press to Ocean Dream (makes waves go calm)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            is_calm = record->event.pressed;
            break;
    }
    return true;
}
