/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY = 0,
    _NAV,
    _SYMBOLS,
    _NUMBERS,
    _FUNCTION
};


enum custom_keycodes {
    VSCLIP = SAFE_RANGE,
    VSSAVE,
    SHIFTG,
    SHIFTEN,
    C_ARROW
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VSCLIP:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LGUI("acw") SS_LALT("j"));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case VSSAVE:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LGUI("s"));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case SHIFTG:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LSFT("g"));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case SHIFTEN:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LSFT("\n"));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case C_ARROW:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("->");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    
    return true;
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------.                          ,-----------------------------------------------------.
                    KC_TAB,    KC_Q,    KC_W,    KC_E,              KC_R,    KC_T ,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|---------------------+--------+--------+--------+------------------+---------|                          |--------+--------+--------+--------+--------+--------|
      MT(MOD_LGUI, KC_ESC),    KC_A,    KC_S,    KC_D,MT(MOD_LALT, KC_F),    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, LT(3, KC_QUOT),
  //|---------------------+--------+--------+--------+------------------+---------|                          |--------+--------+--------+--------+--------+--------|
                   KC_LCTL,    KC_Z,    KC_X,    KC_C,              KC_V,    KC_B ,                               KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  //|---------------------+--------+--------+--------+------------------+---------+--------|        |--------+--------+--------+--------+--------+--------+--------|
                                                                 KC_ENT ,   OSL(1), OSM(MOD_LSFT),     KC_SPC,  OSL(2), KC_BSLS
                                                   //`-------------------------------------'        `--------------------------'

  ),


    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,  VSCLIP, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,                      KC_END , KC_PGUP,   KC_UP, KC_PGDN, KC_TRNS, KC_DEL ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS,  VSSAVE, KC_LPRN, KC_RPRN, KC_LALT,                      KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT, KC_TILD, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS,                      KC_TRNS, KC_PAST,  KC_EQL, KC_PLUS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
                                      
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_PERC, KC_EXLM, KC_HASH, C_ARROW,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_AT  , KC_DLR , KC_AMPR, KC_PMNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_CIRC, KC_UNDS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          SHIFTEN, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS,    KC_7,    KC_8,    KC_9, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS,    KC_4,    KC_5,    KC_6,  SHIFTG,                      KC_SLSH, KC_DOT , KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS,    KC_1,    KC_2,    KC_3, KC_GRV ,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_0   , KC_TRNS,    KC_TRNS, OSL(_FUNCTION), KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
    [_FUNCTION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS,KC_F7,   KC_F8,   KC_F9, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+-----+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS,KC_F4,   KC_F5,   KC_F6, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+-----+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS,KC_F1,   KC_F2,   KC_F3, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_F10 , KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
};


#ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (!is_keyboard_master()) {
//         return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//     }

//     return rotation;
// }


char wpm_str[32];

// WPM-responsive animation stuff here
#define IDLE_FRAMES 2
#define IDLE_SPEED 25 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 30 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#define ANIM_FRAME_IDLE_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 512 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

enum animation_stage_t {
    AS_IDLE,
    AS_OTHER
};

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        0,  0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16,  8,  8,  4,  4,  4,  8, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24,100,130,  2,  2,  2,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 56,  4,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        },
        {
        0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16,  8,  4,  2,  2,  4, 24, 96,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 60,194,  1,  1,  2,  2,  4,  4,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 96, 96,  0,129,130,130,132,  8, 16, 32, 64,128,  0,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 25,  6,  0,  0,  0,  0,  0,  0,  0, 24, 24, 24, 27,  3,  0, 64,160, 34, 36, 20, 18, 18, 18, 11,  8,  8,  8,  8,  5,  5,  9,  9, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        },
    };
    static const char PROGMEM prep[][ANIM_SIZE] = {
        {
        0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,129,128,128,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,225, 26,  6,  9, 49, 53,  1,138,124,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0, 24,  6,  5,152,153,132,195,124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  4,  4,  4,  4,  2,  2,  2,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        }
    };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
        0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,248,248,248,248,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,129,128,128,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,  1,  2,  4,  8, 16, 32, 67,135,  7,  1,  0,184,188,190,159, 95, 95, 79, 76, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0, 24,  6,  5,152,153,132, 67,124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1, 61,124,252,252,252,252,252, 60, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32,  16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        },
        {
        0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,225, 26,  6,  9, 49, 53,  1,138,124,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  4,  4,  4,  4,  2,  2,  2,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32,  16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,122,122,121,121,121,121, 57, 49,  2,  2,  4,  4,  8,  8,  8,8,8,7,0,  0,  0,  48,  60,  124,  124,  126,  126,  126,  126,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        },
    };

    //assumes 1 frame prep stage
    int animation_phase(void) {
        int res = AS_OTHER;
        if(get_current_wpm() <=IDLE_SPEED){
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
            res = AS_IDLE;
         }
         else if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
             oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
         }
         else if(get_current_wpm() >=TAP_SPEED){
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
         return res;
    }

    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}




bool oled_task_user() {
    if (!is_keyboard_master()){
      // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("Default\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYMBOLS:
                oled_write_P(PSTR("Symbol\n"), false);
                break;
            case _NUMBERS:
                oled_write_P(PSTR("Numbers\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }
        oled_write_P(PSTR("\nUser: N HOANG"), false);
    }
    else {
        render_anim();
        oled_set_cursor(0,0);
        sprintf(wpm_str, "WPM:%03d", get_current_wpm());
        oled_write(wpm_str, false);

    }
    
    return false;
}

#endif


//     [2] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
//                                       //`--------------------------'  `--------------------------'
//   )