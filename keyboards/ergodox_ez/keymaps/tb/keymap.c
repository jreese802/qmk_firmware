#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  // COLEMAK LAYER
  [0] = KEYMAP(
      // left hand
        //top row
      KC_GRAVE,          KC_1,     KC_2,     KC_3,         KC_4,         KC_5,    KC_F17, // f17 is set to "desktop left" in keyboard maestro
      KC_TAB,            KC_Q,     KC_W,     KC_F,         KC_P,         KC_G,    KC_MINUS,
      CTL_T(KC_ESCAPE),  KC_A,     KC_R,     KC_S,         LT(2,KC_T),   KC_D, // note: special ctrl-escape caps key and nav toggle on left index
      KC_LSHIFT,         KC_Z,     KC_X,     KC_C,         KC_V,         KC_B,    OSL(4),
      KC_LCTL,           KC_LALT,  KC_LGUI,  KC_LBRACKET,  KC_RBRACKET,

      /* left thumb cluster
       *      *--* *--*
       *      |0 | |1 |
       *      *--* *--*
       * *--* *--* *--*
       * |  | |  | |2 |
       * |3 | |4 | *--*
       * |  | |  | |5 |
       * *--* *--* *--*
       *
       */
      KC_LGUI, KC_LALT, KC_LALT, KC_BSPACE, MO(1), CTL_T(KC_ESCAPE),

      // right hand
      KC_F18,  KC_6,    KC_7,    KC_8,     KC_9,     KC_0,       KC_MINUS,
      TG(1),   KC_J,    KC_L,    KC_U,     KC_Y,     KC_SCOLON,  KC_EQUAL,
               KC_H,    KC_N,    KC_E,     KC_I,     KC_O,       KC_QUOTE,
      TG(4),   KC_K,    KC_M,    KC_COMMA, KC_DOT,   KC_SLASH,   KC_RSHIFT,
                        KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT,   KC_NO,


      /* right thumb cluster
       * *--* *--*
       * |0 | |1 |
       * *--* *--*
       * *--* *--* *--*
       * |2 | |  | |  |
       * *--* |4 | |5 |
       * |3 | |  | |  |
       * *--* *--* *--*
       *
       */
      MO(1), KC_LGUI, CTL_T(KC_ESCAPE), MO(1), LT(1,KC_ENTER), KC_SPACE),

  [1] = KEYMAP(
      KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
      KC_TAB, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_BSLASH, KC_PIPE,
      CTL_T(KC_ESCAPE),KC_HASH, KC_DLR, KC_LPRN, KC_RPRN,
      KC_MINUS, KC_LSHIFT, KC_PERC, KC_CIRC, KC_LBRACKET, KC_RBRACKET, KC_UNDS, KC_GRAVE,
      KC_RCTRL, KC_AMPR, KC_ASTR, KC_LABK, KC_RABK,

      KC_LALT, KC_LGUI, KC_LSHIFT, KC_BSPACE, KC_TRANSPARENT, CTL_T(KC_ESCAPE),
      KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
      KC_TRANSPARENT, KC_UP, KC_1, KC_2, KC_3, KC_KP_MINUS, KC_F12,
      KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS, KC_EQUAL, KC_TRANSPARENT, KC_AMPR, KC_7, KC_8, KC_9, KC_SLASH, KC_RSHIFT, KC_0, KC_DOT, KC_EQUAL, KC_ASTR, KC_TRANSPARENT, KC_LGUI, KC_LALT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER, KC_SPACE),

  [2] = KEYMAP(
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE, KC_TRANSPARENT, KC_LCTL,

      KC_TRANSPARENT,  KC_TRANSPARENT,  KC_AUDIO_MUTE,   KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  KC_TRANSPARENT,  KC_TRANSPARENT,
      KC_TRANSPARENT,  KC_CUT,          LALT(KC_LEFT),   KC_UP,              LALT(KC_RIGHT),   KC_PGUP,         KC_TRANSPARENT,
      KC_COPY,         KC_LEFT,         KC_DOWN,         KC_RIGHT,           KC_PGDOWN,        KC_TRANSPARENT,
      KC_TRANSPARENT,  KC_PASTE,        LCTL(KC_LEFT),  KC_TAB,             LCTL(KC_RIGHT),  KC_TRANSPARENT,  KC_TRANSPARENT,
      KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,     KC_TRANSPARENT,

      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_ENTER, KC_SPACE),

  [3] = KEYMAP(
      KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
      KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,
      KC_TRANSPARENT, CTL_T(KC_ESCAPE),KC_EXLM, KC_AT, KC_HASH, KC_DLR,
      KC_PERC, KC_TRANSPARENT, KC_MINUS, KC_KP_PLUS, KC_LBRACKET, KC_RBRACKET, KC_CIRC, KC_TRANSPARENT, KC_TRANSPARENT, KC_SLASH, KC_ASTR, KC_LABK, KC_RABK, KC_LALT, KC_LGUI, KC_LSHIFT, KC_BSPACE, KC_TRANSPARENT, CTL_T(KC_ESCAPE),KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRANSPARENT, KC_TRANSPARENT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLASH, KC_CIRC, KC_KP_ASTERISK, KC_LPRN, KC_RPRN, KC_MINUS, KC_EQUAL, KC_TRANSPARENT, KC_LCBR, KC_RCBR, KC_SCOLON, KC_COLN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_COMMA, KC_KP_DOT, KC_SLASH, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER, KC_SPACE),

  [4] = KEYMAP(
      LALT(LCTL(KC_DELETE)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_ESCAPE)),KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LSFT(KC_TAB)), LGUI(KC_TAB), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LSFT(KC_LBRACKET)),LGUI(LSFT(KC_RBRACKET)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_LBRACKET),LGUI(KC_RBRACKET),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
