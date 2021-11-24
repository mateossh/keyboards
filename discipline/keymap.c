#include QMK_KEYBOARD_H

#define ESC_MOD LT(_UTILS, KC_ESC)

enum my_keycodes {
  LAY_QWE = SAFE_RANGE,
  LAY_COL,
  LAY_MAC,
};


enum layer_names {
  _QWERTY,
  _UTILS,
  _MAC,
  _COLEMAK,
};

// NOTE: https://docs.qmk.fm/#/feature_layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // NOTE: qwerty Windows layout
  [_QWERTY] = LAYOUT_65_ansi(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_GRV,
      ESC_MOD, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,            KC_PGUP,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_PGDN,
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                 KC_RALT, MO(_UTILS), KC_RCTL,  KC_LEFT, KC_DOWN,  KC_RIGHT),

  // NOTE: functional layer
  [_UTILS] = LAYOUT_65_ansi(
     /* esc      1        2        3        4       5       6       7       8       9         0        -         =     bkspc       `~  */
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,    KC_PSCR,
     /*  tab      Q       W        E        R        T      Y        U      I        O        P        [         ]        \       delete*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,  KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_TRNS, KC_TRNS, LAY_QWE, LAY_COL,   KC_TRNS,   KC_DEL,
     /*  caps     A       S        D        F        G      H        J      K        L        ;        '        enter             pg up*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,KC_TRNS, KC_TRNS,  KC_INS,            KC_HOME,
     /* shift             Z         X        C       V       B       N      M        ,        .        /        shift     up      pg dn*/
      KC_LSFT,          KC_VOLD, KC_MUTE, KC_VOLU,KC_TRNS,KC_MPRV, KC_MPLY, KC_MNXT,KC_TRNS, KC_TRNS, KC_TRNS,  KC_RSFT, KC_VOLU, KC_END,
     /* ctrl     win      alt                              space                    alt      fn       ctrl      left     down     right*/
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_TRNS,                KC_RALT, KC_TRNS, KC_RCTL,  KC_TRNS, KC_VOLD,  KC_TRNS),

  // NOTE: qwerty mac layout
  [_MAC] = LAYOUT_65_ansi(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_GRV,
      ESC_MOD, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,            KC_PGUP,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_PGDN,
      KC_LCTL, KC_LALT, KC_LGUI,                          KC_SPC,                 KC_RALT, MO(_UTILS), KC_RCTL,  KC_LEFT, KC_DOWN,  KC_RIGHT),

  // NOTE: colemak windows
  [_COLEMAK] = LAYOUT_65_ansi(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,   KC_J,   KC_L,   KC_U,   KC_Y,    KC_SCLN,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_GRV,
      ESC_MOD, KC_A,    KC_R,    KC_S,    KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,    KC_O, KC_QUOT,  KC_ENT,            KC_PGUP,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_PGDN,
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                 KC_RALT, MO(_UTILS), KC_RCTL,  KC_LEFT, KC_DOWN,  KC_RIGHT),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAY_QWE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return true;
    case LAY_COL:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return true;
    default:
      return true; // Process all other keycodes normally
  }
}
