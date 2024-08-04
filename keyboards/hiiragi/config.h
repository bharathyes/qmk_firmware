// Copyright 2024 Bharath (@Bharath)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

// OLED
// #define OLED_IC OLED_IC_SH1106
// #define I2C_DRIVER I2CD1
// #define I2C1_SDA_PIN GP10
// #define I2C1_SCL_PIN GP11
// #define OLED_DISPLAY_128X64



#undef RGBLED_NUM

#define GRAVE_ESC_GUI_OVERRIDE

// enables QK_MAKE
#define ENABLE_COMPILE_KEYCODE

// TAP HOLD
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2  			// TT layer shift momentary OR toggle ON/OFF if tapped thrice
#define QUICK_TAP_TERM 0
// #define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

// #define HOLD_ON_OTHER_KEY_PRESS
//  conflicts with permissive hold

// exploring
// #define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD


#define ONESHOT_TAP_TOGGLE 2 	/* tapping said times holds key until tapped once again */
#define ONESHOT_TIMEOUT 2500 	/* time (in ms) before the one shot key is released */

/*
	Issues with MOD TAP
	Explore later
	https://docs.qmk.fm/#/feature_auto_shift?id=retro-shift
*/
#define AUTO_SHIFT_TIMEOUT 160
#define NO_AUTO_SHIFT_SPECIAL
#define RETRO_SHIFT	500		// to enable auto shift for tap mod keys too

// CAPS WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 4000
#define CAPS_WORD_INVERT_ON_SHIFT		// continue on shift key


#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 340
#define LEADER_NO_TIMEOUT


// Dynamic Macro Recording
#define DYNAMIC_MACRO_USER_CALL		// stop recording without reset key
#define DYNAMIC_MACRO_NO_NESTING    // prevents recording recursive macros
									//  PS: macro 1 in macro2 and vice versa is still possible



// #define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
// #define UNICODE_KEY_LNX

#define COMBO_TERM 35
#define COMBO_VARIABLE_LEN
#define COMBO_ONLY_FROM_LAYER 0


// RGB LED settings

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL

#define WS2812_DI_PIN GP16
#define RGBLIGHT_LED_COUNT 1

#define RGBLIGHT_LIMIT_VAL 70
#define RGBLIGHT_DEFAULT_VAL 40
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_SLEEP
