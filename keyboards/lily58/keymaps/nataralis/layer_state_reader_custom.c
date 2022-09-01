
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_LOWER (1 << 4)
#define L_LOWER_DE (1 << 5)
#define L_RAISE (1 << 6)
#define L_ADJUST (1 << 7)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)
#define L_ADJUST_TRI_DE (L_ADJUST | L_RAISE | L_LOWER_DE)

char layer_state_str[24];

const char *read_layer_state_custom(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_LOWER_DE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
  case L_ADJUST_TRI_DE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
