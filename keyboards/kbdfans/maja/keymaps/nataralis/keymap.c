#include QMK_KEYBOARD_H

#include "keymap_german.h"

#define CC_SSPC LT(_SPECIAL, KC_SPC)
#define CC_FNCT MO(_FUNCTION)
#define CC_ADIA XP(X(LOW_ADIA), X(CAP_ADIA))
#define CC_ODIA XP(X(LOW_ODIA), X(CAP_ODIA))
#define CC_UDIA XP(X(LOW_UDIA), X(CAP_UDIA))
#define CC_SS XP(X(LOW_SS), X(CAP_SS))
#define CC_EURO X(EURO)
#define CC_BOMB X(EMOJI_BOMB)

enum layer_number {
	_QWERTY = 0,
  _DVORAK,
  _DVORAK_DE,
  _SPECIAL,
  _FUNCTION
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  DVOR_DE,
//SPECIAL,
//FNCT,
  NEW_SAFE_RANGE
};

enum unicode_names {
  LOW_ADIA,
  CAP_ADIA,
  LOW_ODIA,
  CAP_ODIA,
  LOW_UDIA,
  CAP_UDIA,
  LOW_SS,
  CAP_SS,
  EURO,
  EMOJI_BOMB
};

const uint32_t PROGMEM unicode_map[] = {
  [LOW_ADIA] = 0x00E4, // ä
  [CAP_ADIA] = 0x00C4, // Ä
  [LOW_ODIA] = 0x00F6, // ö
  [CAP_ODIA] = 0x00D6, // Ö
  [LOW_UDIA] = 0x00FC, // ü
  [CAP_UDIA] = 0x00DC, // Ü
  [LOW_SS] = 0x00DF, // ß
  [CAP_SS] = 0x1E9E, // ẞ
  [EURO] = 0x20AC, // €
  [EMOJI_BOMB] = 0x1F4A5 // 💥
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MPLY,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MNXT,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_MPRV,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    CC_FNCT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
    KC_LGUI,          KC_LALT, KC_SPC,           KC_RALT,          CC_SSPC,          KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_DVORAK] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC, KC_MPLY,
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS, KC_MNXT,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,  KC_MPRV,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    CC_FNCT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, KC_UP,
    KC_LGUI,          KC_LALT, KC_SPC,           KC_RALT,          CC_SSPC,          KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_DVORAK_DE] = LAYOUT(
    KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC, KC_MPLY,
    KC_TAB,  DE_ODIA, DE_COMM, DE_DOT,  DE_P,    DE_Y,    DE_F,    DE_G,    DE_C,    DE_R,    DE_L,    DE_UDIA, DE_PLUS, DE_HASH, KC_MNXT,
    KC_LCTL, DE_A,    DE_O,    DE_E,    DE_U,    DE_I,    DE_D,    DE_H,    DE_T,    DE_N,    DE_S,    DE_ADIA,          KC_ENT,  KC_MPRV,
    KC_LSFT, DE_MINS, DE_Q,    DE_J,    DE_K,    DE_X,    CC_FNCT, DE_B,    DE_M,    DE_W,    DE_V,    DE_Z,    KC_RSFT, KC_UP,
    KC_LGUI,          KC_LALT, KC_SPC,           KC_RALT,          CC_SSPC,          KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_SPECIAL] = LAYOUT(
    KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU, CC_EURO, CC_BOMB, _______, _______, _______, _______, _______, CC_SS,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CC_UDIA, _______, _______, _______,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, CC_ODIA, CC_ADIA,          _______, _______,
    _______, DE_LABK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______,          _______,          _______,          _______,                   _______, _______, _______
  ),

  [_FUNCTION] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,   _______,
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,   _______,
    _______, RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST, _______,
    _______, UC_MOD,  QWERTY,  DVORAK,  DVOR_DE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______,          _______,          _______,          _______,                   _______, _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case QWERTY: // Switch the default layer to _QWERTY
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case DVORAK: // Switch the default layer to _DVORAK
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
    case DVOR_DE: // Switch the default layer to _DVORAK_DE
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK_DE);
      }
      return false;
    /*
    case SPECIAL: // Switch layer to _SPECIAL while key is pressed
      if (record->event.pressed) {
        layer_on(_SPECIAL);
      } else {
        layer_off(_SPECIAL);
      }
      return false;
    case FNCT: // Switch layer to _FUNCTION while key is pressed
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
    */
    default:
      return true;
  }
  return true;
}