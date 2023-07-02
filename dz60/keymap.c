#include QMK_KEYBOARD_H

#define ESC_MOD LT(_UTILS, KC_ESC)

enum my_keycodes {
	LAY_QWE = SAFE_RANGE,
  LAY_COL,
	LAY_GAM,
	APSGLDE, // apex legends super glide
};

enum layer_names {
	_QWERTY,
  _COLEMAK,
	_GAMING,
	_UTILS,
	_LED,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*
    ,-----------------------------------------------------------------------------------------.
    |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
    |-----------------------------------------------------------------------------------------+
    |   Tab  |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
    |-----------------------------------------------------------------------------------------+
    |  Esc/L1  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   Enter    |
    |-----------------------------------------------------------------------------------------+
    |    Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Shift     |
    |-----------------------------------------------------------------------------------------+
    |  Ctrl |  Win  |  Alt  |               Space              |  Alt  |  L2  |  L1  |  Ctrl  |
    `-----------------------------------------------------------------------------------------'
    */

	[_QWERTY] = LAYOUT(
		QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_NO,   KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		ESC_MOD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,     KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, KC_NO,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, MO(_LED), KC_NO, MO(_UTILS),   KC_RCTL
	),

	[_COLEMAK] = LAYOUT(
		QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_NO,   KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,   KC_U,    KC_Y,     KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,
		ESC_MOD, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,   KC_E,    KC_I,     KC_O, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, KC_NO,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, MO(_LED), KC_NO, MO(_UTILS),   KC_RCTL
	),

	[_GAMING] = LAYOUT(
		QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,   KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_NO,
		KC_LCTL, APSGLDE, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, MO(_LED),   KC_NO,   MO(_UTILS),   KC_RCTL
	),

	[_UTILS] = LAYOUT(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,
		KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[_LED] = LAYOUT(
		KC_TRNS, LAY_QWE, LAY_COL, LAY_GAM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LAY_QWE:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
			}
			return true;
		case LAY_GAM:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_GAMING);
				// do something when pressed
			} else {
				// do something when released
			}
			return true; // Let QMK send the press/release events
		case APSGLDE:
			if (record->event.pressed) {
				SEND_STRING(SS_TAP(X_SPC) SS_DELAY(5) "c");
			}
			return true;
		default:
			return true; // Process all other keycodes normally
	}
}
