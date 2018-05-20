/**
 * Cuyler's (salembeats)
 * Preonic Layout (keymap.c)
 * 
*/

#include QMK_KEYBOARD_H
#define MIDI_ADVANCED
#include "midi.h"
#include "process_midi.h"
#include <LUFA/Drivers/USB/USB.h>
#include "qmk_midi.h"

enum preonic_layers {
	_QWERTY,
	_LOWER,
	_RAISE,
	NAV_LAYER,
	_ADJUST,
	_NUMPAD
};

// Key aliases for legibility
#define _______ KC_TRNS
#define ___x___ KC_NO

#define DESKMAN LWIN(KC_TAB)
#define LEFTDSK LCTL(LWIN(KC_LEFT))
#define RGHTDSK LCTL(LWIN(KC_RIGHT))

#define WINLEFT LWIN(KC_LEFT)
#define WINUP   LWIN(KC_UP)
#define WINDOWN LWIN(KC_DOWN)
#define WINRGHT LWIN(KC_RIGHT)

#define PREVWIN LALT(KC_ESC)
#define NEXTWIN LALT(LSFT(KC_ESC))

enum preonic_keycodes {
	QWERTY = SAFE_RANGE,
	LOWER,
	RAISE,
	MCC_50,
	MCC_51,
	MCC_52,
	MCC_53,
	MCC_54,
	MCC_55,
	MCC_56,
	MCC_57
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base.

	 *  ┌-----+-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┐
	 *  │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │Tab#P│  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  \  │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │⌃ Esc│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │; Nav│^ Ent│
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │Hyper│Super│ Win │ Alt │  ↓  │ Spc | Spc │  ↑  │ Alt │ Win │Super│Hyper│
	 *  └-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┘
	 */
[_QWERTY] = LAYOUT_preonic_grid( \
	KC_GRV,              KC_1,      KC_2,    KC_3,    KC_4,  KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   KC_MINS,       \
	LT(_NUMPAD, KC_TAB), KC_Q,      KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                   KC_BSLS,       \
	CTL_T(KC_ESC),       KC_A,      KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(NAV_LAYER, KC_SCLN), CTL_T(KC_ENT), \
	KC_LSFT,             KC_Z,      KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                KC_RSFT,       \
	KC_HYPR,             KC_MEH,    KC_LWIN, KC_LALT, LOWER, KC_SPC,  KC_SPC,  RAISE,   KC_RALT, KC_RWIN, KC_MEH,                 KC_HYPR        \
),

/* Enclosing pairs, backspace, functions (full 1-12, number-aligned 1-10). (LOWER)

	 *  ┌-----+-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┐
	 *  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │     │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │     │  {  │  [  │  (  │  <  │  '  │  "  │  >  │  )  │  ]  │  }  │     │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │     │     │  #  │  %  │  /  │     │     │  /  │  %  │  #  │     │     │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │     │     │     │     │>> <<│ Spc |Bkspc|     │     │     │     │     │
	 *  └-----+-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┘
	 */
[_LOWER] = LAYOUT_preonic_grid( \
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
		_______, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT,   KC_QUOT, KC_DQT,  KC_GT,   KC_RPRN, KC_RBRC, KC_RCBR, _______, \
		_______, _______, KC_HASH, KC_PERC, KC_SLSH, _______, _______, KC_SLSH, KC_PERC, KC_HASH, _______, _______, \
		_______, _______, _______, _______, _______, KC_SPC,  KC_BSPC, _______, _______, _______, _______, _______  \
	),

/* Math and logic, numbers, delete, functions extended. (RAISE)

	 *  ┌-----+-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┐
	 *  │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │ F21 │ F22 │ F23 │ F24 │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │     │  *  │  -  │  ?  │  &  │  =  │  =  │  |  │  !  │  +  │  /  │     │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │     │     │  ~  │     │     │     │     │  ^  │  %  │     │     │     │
	 *  ├-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┼-----┤
	 *  │     │     │     │     │     │ Del | Spc │>> <<│     │     │     │     │
	 *  └-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┴-----┘
	 */
[_RAISE] = LAYOUT_preonic_grid ( \
		KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  \
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
		_______, KC_PSLS, KC_PMNS, KC_QUES, KC_AMPR, KC_EQL,  KC_EQL,  KC_PIPE, KC_EXLM, KC_PPLS, KC_PAST, _______, \
		_______, _______, KC_TILD, _______, _______, _______, _______, KC_CIRC, KC_PERC, _______, _______, _______, \
		_______, _______, _______, _______, _______, KC_DEL,  KC_SPC,  _______, _______, _______, _______, _______  \
	),

/* Navigation. (;)
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

/* Settings, standard backspace/delete block, MIDI CCs 50-57 as 'tap buttons'. (LOWER + RAISE)

 * ,-----------------------------------------------------------------------------------.
 * |Reset | -Aud | +Aud |Voice-|Voice+|      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | +Mus | -Mus |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |+MIDI |-MIDI |      | CC50 |      |      | CC51 |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | CC50 | CC51 | CC52 | CC53 |      |      | CC54 | CC55 | CC56 | CC57 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | >><< |             | >><< |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
	RESET,   AU_ON,   AU_OFF,  MUV_DE , MUV_IN,  _______, _______, _______, _______, _______, _______, KC_DEL, \
	_______, MU_ON,   MU_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,  \
	_______, MI_ON,   MI_OFF,  _______, MCC_50,  _______, _______, MCC_51,  _______, _______, _______, _______, \
	_______, MCC_50,  MCC_51,  MCC_52,  MCC_53,  _______, _______, MCC_54,  MCC_55,  MCC_56,  MCC_57,  _______, \
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Numpad, media control, desktop and window control.

 * ,-----------------------------------------------------------------------------------.
 * |      |<- Win|v Win |^ Win | Win->|      |      | Num  |  /   |  *   |  -   | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | >><< |<-Dsk |DskMan| Dsk->|      |      |      |  7   |  8   |  9   |  +   | Vol- |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |PrvWin|NxtWin|      |      |  4   |  5   |  6   |  +   | Mute |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |Enter | Prev |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |PlyTgl| Stop |  0   |  0   |  .   |Enter | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_grid( \
	___x___,             WINLEFT, WINDOWN, WINUP,   WINRGHT, ___x___, ___x___, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_VOLU, \
	LT(_NUMPAD, KC_TAB), LEFTDSK, DESKMAN, RGHTDSK, ___x___, ___x___, ___x___, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_VOLD,  \
	___x___,             ___x___, ___x___, PREVWIN, NEXTWIN, ___x___, ___x___, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_MUTE, \
	___x___,             ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_MPRV, \
	___x___,             ___x___, ___x___, ___x___, ___x___, KC_MPLY, KC_MSTP, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_MNXT  \
)


};

void cc_button_press(uint8_t cc) {
	midi_send_cc(&midi_device, 0, cc, 127);
	midi_send_cc(&midi_device, 0, cc, 0);
}

void send_cc_if_pressed(uint8_t cc, keyrecord_t *record) {
	if(record->event.pressed) {
		cc_button_press(cc);
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
				case MCC_50:
					send_cc_if_pressed(50, record);
					return false;
					break;
				case MCC_51:
					send_cc_if_pressed(51, record);
					return false;
					break;
				case MCC_52:
					send_cc_if_pressed(52, record);
					return false;
					break;
				case MCC_53:
					send_cc_if_pressed(53, record);
					return false;
					break;
				case MCC_54:
					send_cc_if_pressed(54, record);
					return false;
					break;
				case MCC_55:
					send_cc_if_pressed(55, record);
					return false;
					break;
				case MCC_56:
					send_cc_if_pressed(56, record);
					return false;
					break;
				case MCC_57:
					send_cc_if_pressed(57, record);
					return false;
					break;
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
