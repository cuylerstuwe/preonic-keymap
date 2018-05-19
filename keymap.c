/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  NAV_LAYER
};

// Key aliases for legibility
#define _______ KC_TRNS
#define ___x___ KC_NO

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer (Qwerty)

   *  ┌-----+-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┐
   *  │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  \  │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │⌃ Esc│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │; Nav│^ Ent│
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │ ⇧ ( │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │ ⇧ ) │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │  [  │  {  │ Win │ Alt │  ↓  │ Spc |Bkspc│  ↑  │ Alt │ Win │  }  │  ]  │
   *  └-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┘
   */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,         KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   KC_MINS, \
  KC_TAB,         KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                   KC_BSLS,  \
  CTL_T(KC_ESC),  KC_A,      KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(NAV_LAYER, KC_SCLN), CTL_T(KC_ENT), \
  KC_LSPO,        KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                KC_RSPC,  \
  KC_LBRC,        KC_LCBR,   KC_LWIN, KC_LALT, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_RWIN, KC_RALT, KC_RCBR,                KC_RBRC  \
),

/* Numeric layer (LOWER)

   *  ┌-----+-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┐
   *  │     │     │     │     │     │     │     │     │     │     │     │     │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │  #  │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │  -  │  =  │  `  │  \  │  :  │     │     │  ,  │  .  │  /  │     │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┴-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │     │     │     │>> <<│ Backspace │     │     │     │     │     │
   *  └-----+-----┴-----┴-----┴-----┴-----------┴-----┴-----┴-----┴-----┴-----┘
   */
[_LOWER] = LAYOUT_preonic_grid( \
    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    LGUI(KC_GRV), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  S(KC_3), \
    _______,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______,      KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_COLN, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, _______, \
    _______,      _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______, _______, _______, _______, _______ \
  ),

/* Symbol layer (UPPER)

   *  ┌-----+-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┐
   *  │     │     │     │     │     │     │     │     │     │     │     │     │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │ F11 │ F12 │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │  #  │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  '  │  "  │     │ \
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤  |-- Mostly shifted version
   *  │     │  _  │  +  │  ~  │  |  │  :  │     │     │  ,  │  .  │  /  │     │ /    of lower layer
   *  ├-----┼-----┼-----┼-----┼-----┼-----┴-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │     │     │     │     │  Delete   │>> <<│     │     │     │     │
   *  └-----┴-----┴-----┴-----┴-----┴-----------┴-----┴-----┴-----┴-----┴-----┘
   */
[_RAISE] = LAYOUT_preonic_grid ( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, \
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,     S(KC_3), \
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), KC_QUOT, S(KC_QUOT), _______, \
    _______, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, KC_COLN, _______, _______, KC_COMM, KC_DOT,  KC_SLSH,    _______, \
    _______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, _______, _______, _______,    _______ \
  ),

/* Navigation layer (;)
   *
   *  ┌-----+-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┐
   *  │     │     │     │     │     │     │     │     │     │     │     │     │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │     │     │     │     │     │     │     │     │     │     │     │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │>> <<│     │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │     │     │     │     │     │     │     │     │     │     │     │
   *  ├-----┼-----┼-----┼-----┼-----┼-----┴-----┼-----┼-----┼-----┼-----┼-----┤
   *  │     │     │     │     │     │           │     │     │     │     │     │
   *  └-----┴-----┴-----┴-----┴-----┴-----------┴-----┴-----┴-----┴-----┴-----┘
   */
  [NAV_LAYER] = LAYOUT_preonic_grid( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                _______, \
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                ___x___, \
    _______, ___x___, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, LT(NAV_LAYER, KC_SCLN), _______, \
    _______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                _______, \
    _______, _______, _______, _______, ___x___, ___x___, ___x___, ___x___, _______, _______, _______,                _______  \
  ),

/* Adjust (Lower + Raise)

 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};
