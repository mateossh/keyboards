// https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/corvec/tapdance.c


enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_SINGLE_TAP = 4,
  UNKNOWN_TAPS = 5
};

typedef struct {
  bool is_pressed_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  }
  if (state->count == 2) {
    if (state->interrupted) {
      return DOUBLE_SINGLE_TAP;
    } else if (!state->pressed) {
      return DOUBLE_TAP;
    }
  }
  return UNKNOWN_TAPS;
}

/**
 * lalt / left bracket / left curly brace
 */

static tap lalt_state = {
  .is_pressed_action = true,
  .state = 0
};

void lalt_finished(qk_tap_dance_state_t *state, void *user_data) {
  lalt_state.state = cur_dance(state);
  switch(lalt_state.state) {
    case SINGLE_TAP: register_code(KC_LBRC); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_LBRC); break;
    // fallback to alt because it's the priamry purpose of this key
    case DOUBLE_SINGLE_TAP: register_code(KC_LALT); break;
  }
}
void lalt_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch(lalt_state.state) {
    case SINGLE_TAP: unregister_code(KC_LBRC); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: unregister_code(KC_LBRC); unregister_code(KC_LSFT); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_LALT); break;
  }
  lalt_state.state = 0;
}

/**
 * ralt / right bracket / right curly brace
 */

static tap ralt_state = {
  .is_pressed_action = true,
  .state = 0
};

void ralt_finished(qk_tap_dance_state_t *state, void *user_data) {
  ralt_state.state = cur_dance(state);
  switch(ralt_state.state) {
    case SINGLE_TAP: register_code(KC_RBRC); break;
    case SINGLE_HOLD: register_code(KC_RALT); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_RBRC); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_LALT); break;
  }
}
void ralt_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch(ralt_state.state) {
    case SINGLE_TAP: unregister_code(KC_RBRC); break;
    case SINGLE_HOLD: unregister_code(KC_RALT); break;
    case DOUBLE_TAP: unregister_code(KC_RBRC); unregister_code(KC_LSFT); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_LALT); break;
  }
  ralt_state.state = 0;
}

enum {
  TD_LBRC_LALT_LCBR = 0,
  TD_RBRC_RALT_RCBR
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_LALT_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lalt_finished, lalt_reset),
  [TD_RBRC_RALT_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ralt_finished, ralt_reset)
};
