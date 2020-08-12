#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  KC_ATAB,
  KC_SATAB,
  KC_CROSSCOPY,
  KC_CROSSPASTE,
  KC_CROSSCUT,
  KC_TOMAC,
  KC_TOWIN

};

static uint16_t alt_tab_mode_t = 0;

static bool winmode = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_SATAB,                                         KC_ATAB,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_MINUS,                                       KC_CROSSCOPY,    KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_EQUAL,
    LCTL_T(KC_ESCAPE),KC_A,           KC_R,           KC_S,           LT(3,KC_T),     KC_D,                                                                           KC_H,           LT(4,KC_N),     KC_E,           KC_I,           KC_O,           LCTL_T(KC_QUOTE),
    KC_LSHIFT,      LCTL_T(KC_Z),   LALT_T(KC_X),   LGUI_T(KC_C),   KC_V,           KC_B,           KC_UNDS,                                        KC_CROSSPASTE,   KC_K,           KC_M,           RGUI_T(KC_COMMA),RALT_T(KC_DOT), RCTL_T(KC_SLASH),KC_RSHIFT,
    KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LBRACKET,    KC_RBRACKET,                                                                                                    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       TT(6),
                                                                                                    KC_LGUI,        LALT(LCTL(LSFT(KC_LGUI))),LALT(LCTL(KC_LGUI)),KC_LGUI,
                                                                                                                    KC_LALT,        KC_LALT,
                                                                                    KC_BSPACE,      MO(2),          LCTL_T(KC_ESCAPE),LCTL_T(KC_ESCAPE),LT(2,KC_ENTER), LSFT_T(KC_SPACE)
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    LCTL_T(KC_ESCAPE),KC_A,           KC_S,           KC_D,           LT(3,KC_F),     KC_G,                                                                           KC_H,           LT(4,KC_J),     KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT,
    KC_LSHIFT,      LCTL_T(KC_Z),   LALT_T(KC_X),   LGUI_T(KC_C),   KC_V,           KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_N,           KC_M,           RGUI_T(KC_COMMA),RALT_T(KC_DOT), RCTL_T(KC_SLASH),KC_TRANSPARENT,
    KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LBRACKET,    KC_RBRACKET,                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_BSLASH,      KC_PIPE,                                        KC_TRANSPARENT, KC_UP,          KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_MINUS,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_EQUAL,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_UNDS,        KC_GRAVE,                                       KC_TRANSPARENT, KC_TAB,         KC_7,           KC_8,           KC_9,           KC_SLASH,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AMPR,        KC_ASTR,        KC_LABK,        KC_RABK,                                                                                                        KC_0,           KC_COMMA,       KC_DOT,         KC_ASTR,        KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, DYN_REC_START1,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGUP,        LALT(KC_LEFT),  KC_UP,          LALT(KC_RIGHT), KC_HOME,        DYN_REC_STOP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         DYN_MACRO_PLAY1,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CROSSCUT,     LCTL(KC_LEFT),  KC_TAB,         RCTL(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_ergodox_pretty(
    DYN_REC_START2, KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    DYN_REC_STOP,   KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    DYN_MACRO_PLAY2,KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_MS_BTN4,     KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_MS_BTN5,     KC_TRANSPARENT,
                                                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_MS_BTN4,                                     KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_MS_BTN5,                                     KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_PGDOWN,      KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_LCTRL,       KC_TRANSPARENT, KC_ENTER,       KC_SPACE
  ),
  [6] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(1),          KC_TOWIN,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TOMAC, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(5),          KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, RESET,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

void alt_tab_mode(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TOWIN:
            layer_off(6);
            winmode = true;
            return false;
        case KC_TOMAC:
            layer_off(6);
            winmode = false;
            return false;
        case KC_CROSSCOPY:
            if (record -> event.pressed) {
                if (winmode) {
                    register_code(KC_LCTRL);
                    register_code(KC_C);
                    unregister_code(KC_C);
                    unregister_code(KC_LCTRL);
                } else {
                    register_code(KC_LGUI);
                    register_code(KC_C);
                    unregister_code(KC_C);
                    unregister_code(KC_LGUI);
                }
            }
            return false;
        case KC_CROSSPASTE:
            if (record -> event.pressed) {
                if (winmode) {
                    register_code(KC_LCTRL);
                    register_code(KC_V);
                    unregister_code(KC_V);
                    unregister_code(KC_LCTRL);
                } else {
                    register_code(KC_LGUI);
                    register_code(KC_V);
                    unregister_code(KC_V);
                    unregister_code(KC_LGUI);
                }
            }
            return false;
        case KC_CROSSCUT:
            if (record -> event.pressed) {
                if (winmode) {
                    register_code(KC_LCTRL);
                    register_code(KC_X);
                    unregister_code(KC_X);
                    unregister_code(KC_LCTRL);
                } else {
                    register_code(KC_LGUI);
                    register_code(KC_X);
                    unregister_code(KC_X);
                    unregister_code(KC_LGUI);
                }
            }
            return false;
        case KC_ATAB:
            if (record->event.pressed) {

                if (alt_tab_mode_t == 0){
                    // if the timer is > 0 then we are already in alttab mode
                    // if it is 0, then we need to start holding alt
                    register_code(winmode ? KC_LALT : KC_LGUI);
                }

                // reset timer
                alt_tab_mode_t = timer_read();

                // hold alt and tap tab
                register_code(KC_TAB);
                unregister_code(KC_TAB);

            } else {
                // do something when released
            }
            return false;
        case KC_SATAB:
            if (record->event.pressed) {

                if (alt_tab_mode_t == 0){
                    // if the timer is >0 then we are already in alttab mode
                    // if it is 0, then we need to start holding alt
                    register_code(winmode ? KC_LALT : KC_LGUI);
                }

                alt_tab_mode_t = timer_read();
                // hold alt and tap shift + tab
                register_code(KC_LSHIFT);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                unregister_code(KC_LSHIFT);
            } else {
                // do something when released
            }
            return false;
        default:
            if (alt_tab_mode_t > 0){
                // key inturrupt -- release alt
                unregister_code(winmode ? KC_LALT : KC_LGUI);
                alt_tab_mode_t = 0;
                if (keycode == LT(2,KC_ENTER) || keycode == LSFT_T(KC_SPACE) || keycode == KC_BSPACE) {
                    // "confirmation" key pressed
                    return false;
                } else {
                    // window confirmed -- send keycode to active window
                    return true;
                }
            }

    }
    return true;
}

void matrix_scan_user() {
    if (alt_tab_mode_t > 0 && timer_elapsed(alt_tab_mode_t) > 1500) {
        // too much time has elapsed -- release ALT
        alt_tab_mode_t = 0;
        unregister_code(winmode ? KC_LALT : KC_LGUI);
    }
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
