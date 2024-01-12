#include QMK_KEYBOARD_H

#define TAB_NXT LGUI(KC_TAB)
#define TAB_PRV SGUI(KC_TAB)
// WIP
enum layers {
    _DEFAULT = 0,
    _GAMING,
    _SYMBOLS,
    _NAVIGATION,
    _ADJUST
};

enum custom_keycodes {
    FLDR_UP = SAFE_RANGE,
    DCSTRNG,
    X_OR_CT,
    C_OR_CP,
    V_OR_PT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [_DEFAULT] = LAYOUT(
          KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
          KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
          KC_LSFT, KC_Z,    X_OR_CT, C_OR_CP, V_OR_PT, KC_B,    OSM(MOD_MEH), OSM(MOD_HYPR), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               OSM(MOD_LALT), KC_LGUI, MO(2),   LT(2,KC_SPC), LT(3,KC_ENT),  MO(3),   KC_BSPC, KC_RGUI
      ),
      [_GAMING] = LAYOUT(
          KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TG(1),
          KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
          KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,             KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
	                                   KC_LALT, KC_LALT, KC_SPC, KC_SPC,               KC_ENT, XXXXXXX, KC_BSPC, KC_RGUI
      ),
      [_SYMBOLS] = LAYOUT(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
          _______, KC_GRV,  KC_LT,   KC_GT,   KC_DQUO, KC_UNDS,                              KC_AMPR, KC_LBRC, KC_RBRC, XXXXXXX, KC_PERC, XXXXXXX,
          _______, KC_EXLM, KC_PMNS, KC_PLUS, KC_EQL,  KC_HASH,                              KC_PIPE, KC_LPRN, KC_RPRN, KC_COLN, KC_AT,   XXXXXXX,
          _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, XXXXXXX, _______,            _______, KC_TILD, KC_LCBR, KC_RCBR, KC_DLR,  KC_QUES, _______,
                                     _______, _______, _______, _______,       LT(4,KC_ENT), MO(4),   _______, _______
      ),
      [_NAVIGATION] = LAYOUT(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
          _______, XXXXXXX, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX,                              XXXXXXX, TAB_PRV, TAB_NXT, XXXXXXX, XXXXXXX, XXXXXXX,
          _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,            _______, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX, XXXXXXX, _______,
                                     _______, _______, MO(4),   LT(4,KC_SPC),       _______, _______, _______, _______
      ),
      [_ADJUST] = LAYOUT(
          QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               NK_TOGG, TO(1),   CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, RGB_SPI, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, RGB_SPD, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                                     _______, _______, _______, _______,             _______, _______, _______, _______
      )
};

// combos
const uint16_t PROGMEM bracket_left[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM bracket_right[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM paren_left[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM paren_right[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM brace_left[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM brace_right[] = {KC_COMMA, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO(bracket_left, KC_LBRC),
    COMBO(bracket_right, KC_RBRC),
    COMBO(paren_left, KC_LPRN),
    COMBO(paren_right, KC_RPRN),
    COMBO(brace_left, KC_LCBR),
    COMBO(brace_right, KC_RCBR),
};

// copy, paste timer
static uint16_t xcv_timer;
bool xcv_is_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // macros
  case FLDR_UP:
    if (record->event.pressed) {
      SEND_STRING("../");
    }
    return false;
  case DCSTRNG:
    if (record->event.pressed) {
      SEND_STRING("\"\"\"");
    }
    return false;
  // cut, copy, paste
  case X_OR_CT:
    if (record->tap.count && record->event.pressed) {
        tap_code16(KC_X);
    } else if (record->event.pressed) {
        tap_code16(C(KC_X)); 
    }
    return false;
  case C_OR_CP:
    if (record->tap.count && record->event.pressed) {
        tap_code16(KC_C);
    } else if (record->event.pressed) {
        tap_code16(C(KC_C)); 
        HSV hsv = {0, 255, 128};
        rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
        xcv_timer = timer_read();
        xcv_is_on = true;
    }
    return false;
  case V_OR_PT:
    if (record->tap.count && record->event.pressed) {
        tap_code16(KC_V);
    } else if (record->event.pressed) {
        tap_code16(C(KC_V)); 
    }
    return false;
  }
  if (xcv_is_on & (timer_elapsed(xcv_timer) >= 1000)) {
    rgb_matrix_sethsv_noeeprom(0, 0, 0);
    xcv_is_on = false;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { 
  switch (keycode) {
  case X_OR_CT:
  case C_OR_CP:
  case V_OR_PT:
    return TAPPING_TERM + 1000;
  default:
    return TAPPING_TERM;
  }
}
