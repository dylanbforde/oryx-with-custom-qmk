#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};

#define DUAL_FUNC_0 LT(3, KC_F3)
#define DUAL_FUNC_1 LT(3, KC_F15)

static bool w_down = false, a_down = false, s_down = false, d_down = false;

static void socd_press(uint16_t keycode, bool pressed) {
  if (pressed) register_code(keycode);
  else unregister_code(keycode);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    DUAL_FUNC_0,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TO(3),          
    DUAL_FUNC_1,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_PIPE,        
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        MT(MOD_RSFT, KC_QUOTE),
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RALT, KC_SLASH),KC_LEFT_GUI,    
                                                    LT(1, KC_ENTER),KC_TAB,                                         KC_BSPC,        LT(2, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_LABK,        
    KC_LEFT_CTRL,   KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_TILD,        
    KC_LEFT_ALT,    KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_EQUAL,       KC_ENTER,       
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_LEFT,                                  KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN2,     KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TOGGLE_LAYER_COLOR,
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_ENTER,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};





extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {211,255,255}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {211,255,255}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {211,255,255}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {211,255,255}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {169,255,255}, {169,255,255}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {84,250,251}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {129,2,247}, {139,238,233}, {139,238,233}, {139,238,233}, {139,238,233}, {129,2,247}, {211,255,255}, {139,238,233}, {139,238,233}, {129,2,247}, {129,2,247}, {211,255,255}, {211,255,255}, {169,255,255}, {169,255,255} },

    [1] = { {43,3,247}, {211,255,255}, {211,255,255}, {211,255,255}, {211,255,255}, {211,255,255}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {211,255,255}, {211,255,255}, {211,255,255}, {211,255,255}, {211,255,255}, {211,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {43,3,247}, {43,3,247}, {43,3,247}, {131,255,255}, {131,255,255}, {131,255,255}, {43,3,247}, {43,3,247}, {43,3,247}, {131,255,255}, {131,255,255}, {131,255,255}, {43,3,247}, {43,3,247}, {43,3,247}, {43,3,247}, {131,255,255} },

    [2] = { {169,255,255}, {169,255,255}, {169,255,255}, {129,2,247}, {169,255,255}, {169,255,255}, {169,255,255}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {169,255,255}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {124,218,204}, {169,255,255}, {129,2,247}, {129,2,247}, {129,2,247}, {129,2,247}, {169,255,255}, {169,255,255}, {139,238,233}, {139,238,233}, {129,2,247}, {169,255,255}, {169,255,255}, {169,255,255}, {139,238,233}, {139,238,233} },

    [3] = { {126,239,232}, {131,239,232}, {142,239,232}, {155,239,232}, {155,218,204}, {183,218,204}, {193,218,204}, {201,218,204}, {0,0,0}, {229,218,204}, {241,218,204}, {249,218,204}, {253,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {207,255,130}, {188,255,130}, {176,255,130}, {158,255,130}, {144,255,130}, {130,218,204}, {129,218,204}, {124,218,204}, {113,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {84,239,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {96,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {96,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;

    // --- Snap Tap (last-pressed wins) ONLY on layer 3 ("Gaming 3") ---
    if (get_highest_layer(layer_state) == 3) {
        switch (keycode) {
            case KC_A:
                if (pressed) { a_down = true; if (d_down) socd_press(KC_D,false); socd_press(KC_A,true); }
                else         { a_down = false; socd_press(KC_A,false); if (d_down) socd_press(KC_D,true); }
                return false;

            case KC_D:
                if (pressed) { d_down = true; if (a_down) socd_press(KC_A,false); socd_press(KC_D,true); }
                else         { d_down = false; socd_press(KC_D,false); if (a_down) socd_press(KC_A,true); }
                return false;

            case KC_W:
                if (pressed) { w_down = true; if (s_down) socd_press(KC_S,false); socd_press(KC_W,true); }
                else         { w_down = false; socd_press(KC_W,false); if (s_down) socd_press(KC_S,true); }
                return false;

            case KC_S:
                if (pressed) { s_down = true; if (w_down) socd_press(KC_W,false); socd_press(KC_S,true); }
                else         { s_down = false; socd_press(KC_S,false); if (w_down) socd_press(KC_W,true); }
                return false;
        }
        // Don't return here; let other keys continue to the next switch.
    }

    // original dual-function handlers + RGB ---
    switch (keycode) {
        case DUAL_FUNC_0:
            if (record->tap.count > 0) {
                if (record->event.pressed) register_code16(KC_ESCAPE);
                else                       unregister_code16(KC_ESCAPE);
            } else {
                if (record->event.pressed) register_code16(KC_TILD);
                else                       unregister_code16(KC_TILD);
            }
            return false;

        case DUAL_FUNC_1:
            if (record->tap.count > 0) {
                if (record->event.pressed) register_code16(KC_TAB);
                else                       unregister_code16(KC_TAB);
            } else {
                if (record->event.pressed) register_code16(KC_CAPS);
                else                       unregister_code16(KC_CAPS);   // <-- fixed 16
            }
            return false;

        case RGB_SLD:
            if (pressed) { rgblight_mode(1); }
            return false;
    }

    return true;
}

