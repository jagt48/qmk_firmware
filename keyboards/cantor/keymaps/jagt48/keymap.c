// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
enum layer
{
    _BASE = 0,
    _NAV,
    _NUMSYM,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ Y │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_GRAVE, KC_Q,               KC_W,              KC_F,               KC_P,                KC_B,                                              KC_J, KC_L,               KC_U,               KC_Y,               KC_QUOTE,           KC_MINS,
        KC_MINS,  MT(MOD_LGUI, KC_A), MT(MOD_LALT,KC_R), MT(MOD_LCTL, KC_S), MT(MOD_LSFT, KC_T),  KC_G,                                              KC_M, MT(MOD_RSFT, KC_N), MT(MOD_RCTL, KC_E), MT(MOD_RALT, KC_I), MT(MOD_RGUI, KC_O), KC_SCLN,
        KC_LSFT,  KC_Z,               KC_X,              KC_C,               KC_D,                KC_V,                                              KC_K, KC_H,               KC_COMM,            KC_DOT,             KC_SLSH,            KC_RSFT,
                                                                            LT(_MEDIA, KC_ESC),  LT(_NAV, KC_TAB), LT(_NUMSYM, KC_SPC),              LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC), LT(_FUN,KC_DEL)
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                            _______,    KC_PSTE,    KC_COPY,    KC_CUT,    KC_PSCR, _______,
        _______, _______, _______, _______, _______, _______,                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,  CW_TOGG, _______,
        _______, _______, _______, _______, _______, _______,                            KC_INS,     KC_PGDN,    KC_PGUP,    KC_HOME,   KC_END, _______,
                                _______, _______, _______,                               _______, _______, _______
    ),
    [_NUMSYM] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,                 KC_5,                KC_6,    KC_7,               KC_8, KC_9, KC_0,    KC_EQL,
        _______, KC_EXLM, KC_AT,   KC_HASH, MT(MOD_LSFT, KC_DLR), KC_PERC,             KC_CIRC, MT(MOD_RSFT, KC_4), KC_5, KC_6, KC_MINS,  _______,
        _______, _______, _______, _______, KC_LBRC,              KC_LCBR,             KC_RCBR, KC_1,               KC_2, KC_3, KC_EQL, _______,
                                   _______, _______,              _______,             _______, KC_0, _______
    ),
    [_MEDIA] = LAYOUT_split_3x6_3(
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                              _______,              _______,            _______,    _______, _______, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                              KC_MPRV,    KC_KB_VOLUME_DOWN,    KC_KB_VOLUME_UP,    KC_MNXT, _______, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                              KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                _______, _______, _______,                              KC_MSTP, KC_MPLY, KC_MUTE
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        _______, KC_LBRC,    KC_7,    KC_8,    KC_9,    KC_RBRC,                        _______,    _______,    _______,    _______,    _______, _______,
        _______, KC_SCLN,    KC_4,    KC_5,    KC_6,    KC_EQL,                         _______,    _______,    _______,    _______,    _______, _______,
        _______, KC_GRV,     KC_1,    KC_2,    KC_3,    KC_BSLS,                        _______,    _______,    _______,    _______,    _______, _______,
                                        KC_DOT, KC_0, KC_MINS,                          _______, _______, _______
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        _______, KC_LCBR,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RCBR,               _______,    _______,    _______,    _______,    _______, _______,
        _______, KC_COLN,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_PLUS,               _______,    _______,    _______,    _______,    _______, _______,
        _______, KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_PIPE,               _______,    _______,    _______,    _______,    _______, _______,
                                KC_LPRN, KC_RPRN,  KC_UNDS,                             _______, _______, _______
    ),
    [_FUN] = LAYOUT_split_3x6_3(
        _______, KC_F12,    KC_F7,    KC_F8,    KC_F9,    KC_B,                               _______,    _______,    _______,    _______,    _______, _______,
        _______, KC_F11,    KC_F4,    KC_F5,    KC_F6,    KC_G,                               _______,    _______,    _______,    _______,    _______, _______,
        _______, KC_F10,    KC_F1,    KC_F2,    KC_F3,    KC_V,                               _______,    _______,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                _______, _______, _______,                               _______, _______, _______
    )
};

