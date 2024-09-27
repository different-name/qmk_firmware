#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Base layer
    * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
    * │   =    │  1  │  2  │  3  │  4  │  5  │LEFT │                          │RIGHT│  6  │  7  │  8  │  9  │  0  │   -    │
    * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
    * │ Del    │  Q  │  W  │  E  │  R  │  T  │ L1  │                          │ L1  │  Y  │  U  │  I  │  O  │  P  │   \    │
    * ├────────┼─────┼─────┼─────┼─────┼─────┤     │                          │     ├─────┼─────┼─────┼─────┼─────┼────────┤
    * │ BkSp   │  A  │  S  │  D  │  F  │  G  ├─────┤                          ├─────┤  H  │  J  │  K  │  L  │;/L2 │' / Cmd │
    * ├────────┼─────┼─────┼─────┼─────┼─────┤     │                          │     ├─────┼─────┼─────┼─────┼─────┼────────┤
    * │ LShift │  Z  │  X  │  C  │  V  │  B  │Hyper│┌─────┬─────┐┌─────┬─────┐│ Meh │  N  │  M  │  ,  │  .  │//Ctl│ RShift │
    * └──┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘│ App │LGui ││ Alt │CtlEsc└─────┴─────┼─────┼─────┼─────┼─────┼─────┬──┘
    *    │`/L1 │ '"  │AltShf  ←  │  →  │      ┌─────┼─────┼─────┤├─────┼─────┼─────┐      │  ↑  │  ↓  │  [  │  ]  │ ~L1 │
    *    └─────┴─────┴─────┴─────┴─────┘      │     │     │Home ││PgUp │     │     │      └─────┴─────┴─────┴─────┴─────┘
    *                                         │Bksp │Bksp ├─────┤├─────┤ Tab │Enter│
    *                                         │     │     │ End ││PgDn │     │     │
    *                                         └─────┴─────┴─────┘└─────┴─────┴─────┘
    */
    [BASE] = LAYOUT_ergodox(
        // left board
        KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,          KC_LEFT,
        KC_DEL,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,          TG(SYMB),
        KC_BSPC,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
        KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,          ALL_T(KC_NO),
        LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RGHT,
                                                                       ALT_T(KC_APP), KC_LGUI,
                                                                                      KC_HOME,
                                                              KC_SPC,  KC_BSPC,       KC_END,
        // right board
        KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,              KC_MINS,
        TG(SYMB),     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_BSLS,
                      KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
        MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
                               KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,           TT(SYMB),
        KC_LALT,      CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,      KC_TAB,  KC_ENT
    ),

    /* Keymap 1: Symbol layer
    * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
    * │        │ F1  │ F2  │ F3  │ F4  │ F5  │     │                          │     │ F6  │ F7  │ F8  │ F9  │ F10 │  F11   │
    * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
    * │        │  !  │  @  │  {  │  }  │  |  │     │                          │     │  ↑  │  7  │  8  │  9  │  *  │  F12   │
    * ├────────┼─────┼─────┼─────┼─────┼─────┤     │                          │     ├─────┼─────┼─────┼─────┼─────┼────────┤
    * │        │  #  │  $  │  (  │  )  │  `  ├─────┤                          ├─────┤  ↓  │  4  │  5  │  6  │  +  │        │
    * ├────────┼─────┼─────┼─────┼─────┼─────┤     │                          │     ├─────┼─────┼─────┼─────┼─────┼────────┤
    * │        │  %  │  ^  │  [  │  ]  │  ~  │     │┌─────┬─────┐┌─────┬─────┐│     │  &  │  1  │  2  │  3  │  \  │        │
    * └──┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘│     │     ││     │     │└─────┴─────┼─────┼─────┼─────┼─────┼─────┬──┘
    *    │EEPRM│     │     │     │     │      ┌─────┼─────┼─────┤├─────┼─────┼─────┐      │     │  .  │  0  │  =  │     │
    *    └─────┴─────┴─────┴─────┴─────┘      │     │     │     ││     │     │     │      └─────┴─────┴─────┴─────┴─────┘
    *                                         │     │     ├─────┤├─────┤     │     │
    *                                         │     │     │     ││     │     │     │
    *                                         └─────┴─────┴─────┘└─────┴─────┴─────┘
    */
    [SYMB] = LAYOUT_ergodox(
        // left board
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
        KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
        KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
        EE_CLR,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right board
        KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
                 KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
        KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                          KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* Keymap 2: Media and mouse layer
    * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
    * │        │     │     │     │     │     │     │                          │     │     │     │     │     │     │        │
    * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
    * │        │     │     │ Ms↑ │     │     │     │                          │     │     │     │     │     │     │        │
    * ├────────┼─────┼─────┼─────┼─────┼─────┤     │                          │     ├─────┼─────┼─────┼─────┼─────┼────────┤
    * │        │     │ Ms← │ Ms↓ │ Ms→ │     ├─────┤                          ├─────┤     │     │     │     │     │  Play  │
    * ├────────┼─────┼─────┼─────┼─────┼─────┤     │                          │     ├─────┼─────┼─────┼─────┼─────┼────────┤
    * │        │     │     │     │     │     │     │┌─────┬─────┐┌─────┬─────┐│     │     │     │Prev │Next │     │        │
    * └──┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘│     │     ││     │     │└─────┴─────┼─────┼─────┼─────┼─────┼─────┬──┘
    *    │     │     │     │Rclk │Lclk │      ┌─────┼─────┼─────┤├─────┼─────┼─────┐      │VolUp│VolDn│Mute │     │     │
    *    └─────┴─────┴─────┴─────┴─────┘      │     │     │     ││     │     │Brwsr│      └─────┴─────┴─────┴─────┴─────┘
    *                                         │     │     ├─────┤├─────┤     │Back │
    *                                         │     │     │     ││     │     │     │
    *                                         └─────┴─────┴─────┘└─────┴─────┴─────┘
    */
    [MDIA] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1,

                                                    KC_TRNS, KC_TRNS,
                                                            KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                        KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_WBAK
    ),
};
// clang-format on
