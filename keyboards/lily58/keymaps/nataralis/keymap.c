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
  *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|RCTRL |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_QWERTZ_DE] = LAYOUT(
    KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                      DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,
    KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                      DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA,
    KC_LCTL, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                      DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA,
    KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_PLUS, DE_HASH, DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
                               KC_LGUI, KC_LALT, LOW_DE,  KC_SPC,  KC_ENT,  RAISE,   KC_BSPC, KC_RCTL
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
  *                   |      |      |      | /       /       \      \  |      |      |RCTRL |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_LOWER_DE] = LAYOUT(
    DE_CIRC, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,                   _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, DE_ACUT,
    _______, _______, _______, _______, _______, _______,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_RCTL,
    _______, DE_LABK, _______, _______, _______, _______, _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_CAPS,
                               _______, _______, _______, _______, _______, _______, _______, KC_RCTRL
  ),
  /* RAISE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |   `  | Mute | Vol- | Vol+ |   €  | Bomb |                    |      |      | Prev | Play | Next |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | Home | End  |   7  |   8  |   9  |      |                    |      |      |  Up  |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |Insert| PGUP |   4  |   5  |   6  |   .  |-------.    ,-------|      | Left | Down |Right |      |      |
  * |------+------+------+------+------+------| NUMLK |    |PRTSCRN|------+------+------+------+------+------|
  * |Delete| PGDN |   1  |   2  |   3  |   0  |-------|    |-------|      |      |      |      |      |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |      |      | /       /       \      \  |      |      |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_RAISE] = LAYOUT(
    KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU, CC_EURO, CC_BOMB,                   _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
    KC_HOME, KC_END,  KC_P7,   KC_P8,   KC_P9,   _______,                   _______, _______, KC_UP,   _______, _______, _______,
    KC_INS,  KC_PGUP, KC_P4,   KC_P5,   KC_P6,   KC_PDOT,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    KC_DEL,  KC_PGDN, KC_P1,   KC_P2,   KC_P3,   KC_P0,   KC_NUM,  KC_PSCR, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
  ),
  /* ADJUST
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |UCMode|      |      |      |      |      |                    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
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
    UC_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, QWER_DE, QWERTY,  XXXXXXX,                   XXXXXXX, DVORAK,  DVOR_DE, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______, _______
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  if (((state & ADJUST_US) == ADJUST_US) || ((state & ADJUST_DE) == ADJUST_DE)) {
    state = state | (1UL << _ADJUST);
  } else {
    state = state & ~(1UL << _ADJUST);
  }
  return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if master
  } else {
    return OLED_ROTATION_270;
  }
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state_custom(void);
const char *read_host_led_state_custom(void);

// settings
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

// advanced settings
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

// timers
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

// current frame
uint8_t current_frame = 0;

// status variables
int   current_wpm = 0;
led_t led_usb_state;
//bool  master_oled_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

// logic
static void render_luna(int LUNA_X, int LUNA_Y) {
  // Sit
  static const char PROGMEM sit[2][ANIM_SIZE] = {
    { // 'sit1', 32x22px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    { // 'sit2', 32x22px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }
  };

  // Walk
  static const char PROGMEM walk[2][ANIM_SIZE] = {
    { // 'walk1', 32x22px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    { // 'walk2', 32x22px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    }
  };

  // Run
  static const char PROGMEM run[2][ANIM_SIZE] = {
    { // 'run1', 32x22px
      0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    { // 'run2', 32x22px
      0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    }
  };

  // Bark
  static const char PROGMEM bark[2][ANIM_SIZE] = {
    { // 'bark1', 32x22px
      0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    { // 'bark2', 32x22px
      0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    }
  };

  // Sneak
  static const char PROGMEM sneak[2][ANIM_SIZE] = {
    { // 'sneak1', 32x22px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
    },

    { // 'sneak2', 32x22px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    }
  };

  // animation
  void animate_luna(void) {
    // jump
    if (isJumping || !showedJump) {
      // clear
      oled_set_cursor(LUNA_X, LUNA_Y + 2);
      oled_write("     ", false);

      oled_set_cursor(LUNA_X, LUNA_Y - 1);

      showedJump = true;
    } else {
      // clear
      oled_set_cursor(LUNA_X, LUNA_Y - 1);
      oled_write("     ", false);

      oled_set_cursor(LUNA_X, LUNA_Y);
    }

    // switch frame
    current_frame = (current_frame + 1) % 2;

    // current status
    if (led_usb_state.caps_lock) {
      oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);
    } else if (isSneaking) {
      oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);
    } else if (current_wpm <= MIN_WALK_SPEED) {
      oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);
    } else if (current_wpm <= MIN_RUN_SPEED) {
      oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);
    } else {
      oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
    }
  }

  // this fixes the screen on and off bug
  if (current_wpm > 0) {
    oled_on();
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
      anim_timer = timer_read32();
      animate_luna();
    }
    anim_sleep = timer_read32();
  } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
      oled_off();
  } else if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
    anim_timer = timer_read32();
    animate_luna();
  }
}

static void print_oled_master(void) {
  // Default layer state reader
  oled_set_cursor(0,0);
  switch (get_highest_layer(default_layer_state)) {
    case _QWERTY:
      oled_write_ln("Layout: QWERTY", false);
      break;
    case _QWERTZ_DE:
      oled_write_ln("Layout: QWERTZ_DE", false);
    case _DVORAK:
      oled_write_ln("Layout: Dvorak", false);
      break;
    case _DVORAK_DE:
      oled_write_ln("Layout: Dvorak_DE", false);
  }

  // Layer state reader
  oled_set_cursor(0,1);
  oled_write_ln(read_layer_state_custom(), false);

  // LED state reader
  oled_set_cursor(0,2);
  oled_write_ln(read_host_led_state_custom(), false);
}

static void print_oled_offhand(void) {
  // WPM counter
  uint8_t n = get_current_wpm();
  char wpm_counter[4];
  wpm_counter[3] = '\0';
  wpm_counter[2] = '0' + n % 10;
  wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
  wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
  oled_set_cursor(0,0);
  oled_write(wpm_counter, false);
  oled_set_cursor(0,1);
  oled_write_P(PSTR("WPM"), false);
  
  // Keyboard pet render
  render_luna(0,13);
}

bool oled_task_user(void) {
  // Keyboard pet variables
  current_wpm = get_current_wpm();
  led_usb_state = host_keyboard_led_state();

  if (is_keyboard_master()) {
    //master_oled_state = is_oled_on();
    print_oled_master();
  } else {
    print_oled_offhand();
  }
  return false;
}
#endif // OLED_ENABLE

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
#ifdef OLED_ENABLE
  if (record->event.pressed) {
    anim_sleep = timer_read32();
  }
#endif
  return true;
}