#include QMK_KEYBOARD_H

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum layer_number {
  _QWERTY = 0,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  DE_AE,
  DE_OE,
  DE_UE,
  DE_ESZT,
  EURO,
  NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RCTRL
),
/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   :  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_DVORAK] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  KC_LCTRL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, KC_LBRC,  KC_RBRC,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RCTRL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  | Mute | Vol- | Vol+ |   €  |      |                    |      |      | Prev | Play | Next |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |-------.    ,-------|      |   Ä  |   Ö  |   Ü  |   ß  |   \  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU, EURO,    _______,                   _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_EQL,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_CAPS, _______, _______, _______, _______, _______,                   _______, DE_AE,   DE_OE,   DE_UE,   DE_ESZT, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  | Mute | Vol- | Vol+ | Home | End  |                    |      |      | Prev | Play | Next |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   7  |   8  |   9  |Insert| PGUP |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |Delete| PGDN |-------.    ,-------|      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------| NUMLK |    |PRTSCRN|------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   0  |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU, KC_HOME, KC_END,                      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
  _______, KC_P7,   KC_P8,   KC_P9,   KC_INS,  KC_PGUP,                     _______, _______, KC_UP,   _______, _______, _______,
  _______, KC_P4,   KC_P5,   KC_P6,   KC_DEL,  KC_PGDN,                     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, KC_P1,   KC_P2,   KC_P3,   KC_P0,   _______,  KC_NUM,  KC_PSCR,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |Dvorak|      |-------.    ,-------|      |QWERTY|      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DVORAK,  XXXXXXX,                   XXXXXXX, QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void tap_key(uint16_t keycode) {
  register_code(keycode);
  unregister_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK); // Switch the default layer to Dvorak
      }
      return false;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY); // Switch the default layer to QWERTY
      }
      return false;
    case DE_AE:
      if (record->event.pressed) {
        uint8_t temp_mod = get_mods();
        clear_mods();
        register_code(KC_LALT);
        if (temp_mod & MODS_SHIFT_MASK) {
          tap_key(KC_P1); tap_key(KC_P4); tap_key(KC_P2); // Ä
        } else {
          tap_key(KC_P1); tap_key(KC_P3); tap_key(KC_P2); // ä
        }
        unregister_code(KC_LALT);
      }
      return false;
    case DE_OE:
      if (record->event.pressed) {
        uint8_t temp_mod = get_mods();
        clear_mods();
        register_code(KC_LALT);
        if (temp_mod & MODS_SHIFT_MASK) {
          tap_key(KC_P1); tap_key(KC_P5); tap_key(KC_P3); // Ö
        } else {
          tap_key(KC_P1); tap_key(KC_P4); tap_key(KC_P8); // ö
        }
        unregister_code(KC_LALT);
      }
      return false;
    case DE_UE:
      if (record->event.pressed) {
        uint8_t temp_mod = get_mods();
        clear_mods();
        register_code(KC_LALT);
        if (temp_mod & MODS_SHIFT_MASK) {
          tap_key(KC_P1); tap_key(KC_P5); tap_key(KC_P4); // Ü
        } else {
          tap_key(KC_P1); tap_key(KC_P2); tap_key(KC_P9); // ü
        }
        unregister_code(KC_LALT);
      }
      return false;
    case DE_ESZT:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_key(KC_P2); tap_key(KC_P2); tap_key(KC_P5); // ß
        unregister_code(KC_LALT);
      }
      return false;
    case EURO:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_key(KC_P0); tap_key(KC_P1); tap_key(KC_P2); tap_key(KC_P8); // €
        unregister_code(KC_LALT);
      }
      return false;
    default:
      return true;
  }
  return true;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state_custom(void);
const char *read_logo(void);
const char *read_host_led_state(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state_custom(), false);
    oled_write_ln(read_host_led_state(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE