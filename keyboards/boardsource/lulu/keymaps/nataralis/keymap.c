// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_german.h"

#define CC_ADIA XP(X(LOW_ADIA), X(CAP_ADIA))
#define CC_ODIA XP(X(LOW_ODIA), X(CAP_ODIA))
#define CC_UDIA XP(X(LOW_UDIA), X(CAP_UDIA))
#define CC_SS XP(X(LOW_SS), X(CAP_SS))
#define CC_EURO X(EURO)
#define CC_BOMB X(EMOJI_BOMB)

#define ADJUST_US ((1UL << _LOWER) | (1UL << _RAISE))
#define ADJUST_DE ((1UL << _LOWER_DE) | (1UL << _RAISE))

enum layer_number {
  _QWERTY = 0,
  _QWERTZ_DE,
  _DVORAK,
  _DVORAK_DE,
  _LOWER,
  _LOWER_DE,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  QWER_DE,
  DVORAK,
  DVOR_DE,
  LOWER,
  LOW_DE,
  RAISE,
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
  [EMOJI_BOMB] = 0x1F4A5, // 💥
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   -  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |   '  |
  * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|RCTRL |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_BSPC, KC_RCTL
  ),
  /* QWERTZ DE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   ß  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |   Ü  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |   Ä  |
  * |------+------+------+------+------+------|   +   |    |   #   |------+------+------+------+------+------|
  * |LShift|   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RALT |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_QWERTZ_DE] = LAYOUT(
    KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                      DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,
    KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                      DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA,
    KC_LCTL, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                      DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA,
    KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_PLUS, DE_HASH, DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
                               KC_LGUI, KC_LALT, LOW_DE,  KC_SPC,  KC_ENT,  RAISE,   KC_BSPC, KC_RALT
  ),
  /* DVORAK
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |   /  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |LCTRL |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |   -  |
  * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
  * |LShift|   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|RCTRL |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_DVORAK] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LBRC, KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                               KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_BSPC, KC_RCTL
  ),
  /* DVORAK DE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   ß  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | Tab  |   Ö  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |   Ü  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |LCTRL |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |   Ä  |
  * |------+------+------+------+------+------|   +   |    |   #   |------+------+------+------+------+------|
  * |LShift|   -  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LAlt |LOW DE| /Space  /       \Enter \  |RAISE |BackSP| RAlt |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_DVORAK_DE] = LAYOUT(
    KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                      DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,
    KC_TAB,  DE_ODIA, DE_COMM, DE_DOT,  DE_P,    DE_Y,                      DE_F,    DE_G,    DE_C,    DE_R,    DE_L,    DE_UDIA,
    KC_LCTL, DE_A,    DE_O,    DE_E,    DE_U,    DE_I,                      DE_D,    DE_H,    DE_T,    DE_N,    DE_S,    DE_ADIA,
    KC_LSFT, DE_MINS, DE_Q,    DE_J,    DE_K,    DE_X,    DE_PLUS, DE_HASH, DE_B,    DE_M,    DE_W,    DE_V,    DE_Z,    KC_RSFT,
                               KC_LGUI, KC_LALT, LOW_DE,  KC_SPC,  KC_ENT,  RAISE,   KC_BSPC, KC_RALT
  ),
  /* LOWER
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |   `  | Mute | Vol- | Vol+ |   €  | Bomb |                    |      |      | Prev | Play | Next |   ß  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |   Ö  |      |      |   =  |      |                    |  F1  |  F2  |  F3  |  F4  |      |   Ü  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |   \  |      |-------.    ,-------|  F5  |  F6  |  F7  |  F8  |   Ö  |   Ä  |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------|    |-------|  F9  | F10  | F11  | F12  |      | Caps |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |      |      | /       /       \      \  |      |      | RAlt |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_LOWER] = LAYOUT(
    KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU, CC_EURO, CC_BOMB,                   _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, CC_SS,
    _______, CC_ODIA, _______, _______, KC_EQL,  _______,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, CC_UDIA,
    _______, _______, _______, _______, KC_BSLS, _______,                   KC_F5,   KC_F6,   KC_F7,   KC_F8,   CC_ODIA, CC_ADIA,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_CAPS,
                               _______, _______, _______, _______, _______, _______, _______, KC_RALT
  ),
  /* LOWER DE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |   ^  | Mute | Vol- | Vol+ |      |      |                    |      |      | Prev | Play | Next |   ´  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                    |  F1  |  F2  |  F3  |  F4  |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------.    ,-------|  F5  |  F6  |  F7  |  F8  |      |RCTRL |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |   <  |      |      |      |      |-------|    |-------|  F9  | F10  | F11  | F12  |      | Caps |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |      |      | /       /       \      \  |      |      |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_LOWER_DE] = LAYOUT(
    DE_CIRC, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,                   _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, DE_ACUT,
    _______, _______, _______, _______, _______, _______,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_RCTL,
    _______, DE_LABK, _______, _______, _______, _______, _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_CAPS,
                               _______, _______, _______, _______, _______, _______, _______, _______
  ),
  /* RAISE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |   `  | Mute | Vol- | Vol+ |   €  | Bomb |                    | Home |Insert| Prev | Play | Next |   ß  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |   Ö  |   7  |   8  |   9  |      |                    | End  |Delete|  Up  |      |      |   Ü  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |   4  |   5  |   6  |   .  |-------.    ,-------| PGUP | Left | Down |Right |   Ö  |   Ä  |
  * |------+------+------+------+------+------| NUMLK |    |PRTSCRN|------+------+------+------+------+------|
  * |      |      |   1  |   2  |   3  |   0  |-------|    |-------| PGDN |      |      |      |      |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |      |      | /       /       \      \  |      |      |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_RAISE] = LAYOUT(
    _______, KC_MUTE, KC_VOLD, KC_VOLU, CC_EURO, CC_BOMB,                   KC_HOME, KC_INS,  KC_MPRV, KC_MPLY, KC_MNXT, CC_SS,
    _______, CC_ODIA, KC_P7,   KC_P8,   KC_P9,   _______,                   KC_END,  KC_DEL,  KC_UP,   _______, _______, CC_UDIA,
    _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT,                   KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, CC_ODIA, CC_ADIA,
    _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_P0,   KC_NUM,  KC_PSCR, KC_PGDN, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
  ),
  /* ADJUST
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |UCMode|      |      |      |      |      |                    |RGBTOG|RGBHUI|RGBSAI|RGBVAI|RGBSPI|      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                    |RGBMOD|RGBHUD|RGBSAD|RGBVAD|RGBSPD|      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |QWERTZ|QWERTY|      |-------.    ,-------|      |Dvorak|DvorDE|      |      |      |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |      |      | /       /       \      \  |      |      |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_ADJUST] = LAYOUT(
    UC_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, QWER_DE, QWERTY,  XXXXXXX,                   XXXXXXX, DVORAK,  DVOR_DE, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  if (((state & ADJUST_US) == ADJUST_US) || ((state & ADJUST_DE) == ADJUST_DE)) {
    state = state | (1UL << _ADJUST);
  } else {
    state = state & ~(1UL << _ADJUST);
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case QWERTY: // Switch the default layer to _QWERTY
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case QWER_DE: // Switch the default layer to _QWERTZ_DE
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTZ_DE);
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
    case LOWER: // Switch layer to _LOWER while key is pressed
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
    case LOW_DE: // Switch layer to _LOWER_DE while key is pressed
      if (record->event.pressed) {
        layer_on(_LOWER_DE);
      } else {
        layer_off(_LOWER_DE);
      }
      return false;
    case RAISE: // Switch layer to _RAISE while key is pressed
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
    default:
      return true;
  }
  return true;
}