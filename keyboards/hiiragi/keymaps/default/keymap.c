// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"


enum layer_number {
  _COLEMAK = 0,
  _QWERTY,
  _KEYPAD,
  _LOWER,
  _RAISE,
  _ADJUST,
};



// layer aliases
#define mo_lower        MO(_LOWER)
#define tg_lower        TG(_LOWER)
#define mo_raise        MO(_RAISE)
#define tg_raise        TG(_RAISE)
#define mo_tg_raise     TT(_RAISE)
#define l_shft          OSM(MOD_LSFT)
#define colemak_base    DF(_COLEMAK)
#define qwerty_base     DF(_QWERTY)


// custom layer combos
#define kp_tab          LT(_KEYPAD, KC_TAB)
#define kp_toggle       TG(_KEYPAD)
#define lowers_bs       LT(_LOWER, KC_BSPC)
#define ent_sft         LSFT_T(KC_ENT)


// custom keybinds
#define esc             KC_ESC
#define pipe            S(KC_BSLS)
#define tilde           S(KC_GRV)
#define underscore      S(KC_MINUS)
#define ctrl_esc        LCTL_T(KC_ESC)
#define l_flower        S(KC_LBRC)
#define r_flower        S(KC_RBRC)

// intellij IDE keybinds
// #define toggle_line_breakpoint  C(KC_F8)
// #define toggle_tmp_breakpoint   C(S(A(KC_F8)))

// debugging intellij keybinds
// #define d_evaluate_expr        S(A(KC_8))
// #define appn_debug             C(KC_F9)


// qmk keycodes
#define tgl_boot        QK_BOOT     // put into bootloader mode for flashing
#define reset_kb        QK_RBT      // reset keeb. does NOT put in bootloader

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    // ---------- COLEMAK --------------------------- //

    [_COLEMAK] = LAYOUT_ortho_4x10(
        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                       KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,
        LGUI_T(KC_A),   LALT_T(KC_R),   LSFT_T(KC_S),   LCTL_T(KC_T),   MEH_T(KC_G),                HYPR_T(KC_M),   LCTL_T(KC_N),   LSFT_T(KC_E),   LALT_T(KC_I),   LGUI_T(KC_O),
        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                       KC_K,           KC_H,           KC_COMM,        KC_DOT,         KC_SLSH,
        XXXXXXX,        esc,            mo_lower,       KC_SPC,         kp_tab,                     QK_LEAD,        ent_sft,        mo_raise,       KC_BSPC,        XXXXXXX
    ),


    // ---------- QWERTY --------------------------- //

    [_QWERTY] = LAYOUT_ortho_4x10(
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
        LGUI_T(KC_A),   LALT_T(KC_S),   LSFT_T(KC_D),   LCTL_T(KC_F),   MEH_T(KC_G),                    HYPR_T(KC_H),   LCTL_T(KC_J),   LSFT_T(KC_K),   LALT_T(KC_L),   LGUI_T(KC_N),
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
        XXXXXXX,        esc,            mo_lower,       KC_SPC,         kp_tab,                         QK_LEAD,        ent_sft,        mo_raise,       KC_BSPC,        XXXXXXX
    ),


    // ---------- SYMBOLS & Function keys --------------------------- //

    [_LOWER] = LAYOUT_ortho_4x10(
        KC_AMPR,            KC_ASTR,            KC_LPRN,            KC_RPRN,            KC_BSPC,                    KC_LBRC,    KC_F7,          KC_F8,              KC_F9,      pipe,
        LGUI_T(KC_EXLM),    LALT_T(KC_AT),      LSFT_T(KC_HASH),    CTL_T(KC_DLR),      MEH_T(KC_PERC),             KC_RBRC,    CTL_T(KC_F4),   LSFT_T(KC_F5),      KC_F6,      l_flower,
        KC_MINUS,           underscore,         KC_EQL,             KC_BSLS,            pipe,                       KC_SLSH,    KC_F1,          KC_F2,              KC_F3,      r_flower,
        XXXXXXX,            _______,            _______,            _______,            _______,                    _______,    _______,        _______,            _______,    XXXXXXX
    ),


    // ---------- Navigations and Mouse keys --------------------------- //

    [_RAISE] = LAYOUT_ortho_4x10(
        KC_MS_L,     KC_MS_D,     KC_MS_U,      KC_MS_R,       KC_BTN1,                     KC_PGUP,       KC_HOME,       KC_UP,         KC_END,        KC_MS_WH_UP,
        KC_LGUI,     KC_LALT,     KC_LSFT,      KC_LCTL,       KC_FIND,                     KC_PGDN,       KC_LEFT,       KC_DOWN,       KC_RIGHT,      KC_MS_WH_DOWN,
        KC_UNDO,     KC_CUT,      KC_COPY,      XXXXXXX,       KC_PASTE,                    XXXXXXX,       KC_BTN1,       XXXXXXX,       KC_BTN2,       XXXXXXX,
        XXXXXXX, _______, _______, _______, _______,  _______, _______,  _______, _______, XXXXXXX
    ),


    // ---------- Keyboard adjustments --------------------------- //

    [_ADJUST] = LAYOUT_ortho_4x10(
        XXXXXXX,     XXXXXXX,       XXXXXXX,      XXXXXXX,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,     tg_lower,      tg_raise,     kp_toggle, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,     qwerty_base,   colemak_base, XXXXXXX,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______, _______,  _______, _______, XXXXXXX
    ),


    // ---------- Num / KEYPAD  & Media controls --------------------------- //

    [_KEYPAD] = LAYOUT_ortho_4x10(
        KC_MUTE,     KC_MPRV,       KC_MPLY,    KC_MNXT,    KC_VOLU,                   KC_PSLS,     KC_7,       KC_8,       KC_9,       KC_PAST,
        KC_LGUI,     KC_LALT,       KC_LSFT,    KC_LCTL,    KC_VOLD,                   XXXXXXX,     KC_4,       KC_5,       KC_6,       KC_PMNS,
        tgl_boot,    reset_kb,      XXXXXXX,    XXXXXXX,    XXXXXXX,                   KC_0,        KC_1,       KC_2,       KC_3,       KC_PPLS,
        XXXXXXX,    _______,        lowers_bs,  KC_SPC,     _______,                   _______,     ent_sft,     mo_raise,    _______,    XXXXXXX
    ),
};


#ifdef LEADER_ENABLE

void leader_start_user(void) {
    // Do something when the leader key is pressed
}


// TODO: correct intelliJ action keymaps
void leader_end_user(void) {
    // ESC
    if (leader_sequence_one_key(KC_ESC))
        tap_code16(KC_PAUSE);
    // O K
    else if (leader_sequence_two_keys(KC_O, KC_K))
        SEND_STRING("Okay.");
    // P U
    else if (leader_sequence_two_keys(KC_P, KC_U))
        SEND_STRING("bharathyes");
    // P G
    else if (leader_sequence_two_keys(KC_P, KC_G))
        SEND_STRING("bharathyes.in@gmail.com");
    // P
    else if (leader_sequence_two_keys(KC_P, KC_O))
        SEND_STRING("bharathyes@outlook.com");
    // W E
    else if (leader_sequence_two_keys(KC_W, KC_E))
        SEND_STRING("bharathyes@techconative.com");
    // D U
    else if (leader_sequence_two_keys(KC_D, KC_U))
        SEND_STRING("bsrinivasan");
    // D E
    else if (leader_sequence_two_keys(KC_D, KC_E))
        SEND_STRING("bsrinivasan@dalet.com");
    // D D G
    else if (leader_sequence_three_keys(KC_D, KC_D, KC_G))
        SEND_STRING("https://start.duckduckgo.com\n");
    // G M (open Git IntelliJ)
    else if (leader_sequence_two_keys(KC_G, KC_M))
        tap_code16(LCTL(LSFT(LALT(KC_GRAVE))));
    // I D  (run menu IntelliJ)
    else if (leader_sequence_two_keys(KC_I, KC_D))
        SEND_STRING(SS_LALT(SS_LSFT("d")));
    // I R (start in debug)
    else if (leader_sequence_two_keys(KC_I, KC_R))
        SEND_STRING(SS_LALT(SS_LSFT("x")));
    // I C  (run select menu)
    else if (leader_sequence_two_keys(KC_I, KC_C))
        tap_code16(LALT(LSFT(KC_F10)));
    // I X  (debug select menu)
    else if (leader_sequence_two_keys(KC_I, KC_X))
        tap_code16(LALT(LSFT(KC_F9)));
    // I S (stop application)
    else if (leader_sequence_two_keys(KC_I, KC_S))
        tap_code16(LCTL(KC_F2));
    // I D M  (mute debug points)
    else if (leader_sequence_three_keys(KC_I, KC_D, KC_M))
        tap_code16(LCTL(LALT(LSFT(KC_F12))));
    // C H S  (hot swap code)
    else if (leader_sequence_three_keys(KC_C, KC_H, KC_S))
        tap_code16(LCTL(LSFT(KC_F9)));
    // P I
    else if (leader_sequence_two_keys(KC_P, KC_I))
        SEND_STRING("qw@4134");
    // F I
    else if (leader_sequence_two_keys(KC_F, KC_I))
        SEND_STRING("qWa@413A");
}


#endif /* LEADER */

layer_state_t layer_state_set_user(layer_state_t state) {

    // switch (get_highest_layer(state)) {
    //     case 0:
    //         rgblight_setrgb(RGB_ORANGE);
    //         break;
    //     default:
    //         rgblight_setrgb(RGB_CHARTREUSE);
    //         break;
    // }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



// PERMISSIVE HOLD MODE
//  ref: https://docs.qmk.fm/#/tap_hold?id=permissive-hold

// provide granular decision hold vs tap per key
// TRUE - prefer HOLD ; FALSE - TAP (default)
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
        case LT(_KEYPAD, KC_TAB):
        case LT(_LOWER, KC_BSPC):
        case LSFT_T(KC_ENT):
            return true;
        default:
            return false;
    }
}

// extend the tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ENT):
            return TAPPING_TERM + 250;
        case mo_tg_raise:
            return 70;
        default:
            return TAPPING_TERM;
    }
}




/*
 * CUSTOM MACROS method
 * ---------------------
 * 1. Interrupt or extend key events.
 * 2. Add custom key codes.
 *  REF : https://docs.qmk.fm/#/custom_quantum_functions?id=example-process_record_user-implementation
 *
 *  ALSO : dynamic macros recording without reset key.
 *   Press the corresponding macro key to stop recording
 *  ref: https://docusaurus.qmk.fm/feature_dynamic_macros#dynamic_macro_user_call
 */


// SAFE_RANGE assigns a unique number everytime
/* enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR
};
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // stop dynamic macro recording without reset key.
    // WIP : keymap.c:424:10: error: implicit declaration of function 'process_record_dynamic_macro'; did you mean 'process_dynamic_macro'?
    // uint16_t macro_kc = (keycode == lowers_bs ? DM_RSTP : keycode);
    // if (!process_record_dynamic_macro(macro_kc, record)) {
    //     return false;
    // }


  // if (record->event.pressed) {
  //   #ifdef OLED_ENABLE
  //   set_keylog(keycode, record);
  //   #endif
  //   // set_timelog();
  // }

    // Mod Tap intercepted. Modded tap behaviour limitation override.
    //  ref: https://docusaurus.qmk.fm/mod_tap#intercepting-mod-taps
  switch (keycode) {
    case LGUI_T(KC_EXLM):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_EXLM);
            return false;
        }
        break;
    case LALT_T(KC_AT):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_AT);
            return false;
        }
        break;
    case LSFT_T(KC_HASH):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_HASH);
            return false;
        }
        break;
    case CTL_T(KC_DLR):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_DLR);
            return false;
        }
        break;
    case MEH_T(KC_PERC):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_PERC);
            return false;
        }
        break;
    // case FOO:
    //   if (record->event.pressed) {
    //     // Do something when pressed
    //   } else {
    //     // Do something else when release
    //   }
    //   return false; // Skip all further processing of this key
    // case KC_ENTER:
    //   // Play a tone when enter is pressed
    //   if (record->event.pressed) {
    //     PLAY_SONG(tone_qwerty);
    //   }
    //   return true; // Let QMK send the enter press/release events
  }
  return true; // Process all other keycodes normally
}



// DEBUG RGB LED (layer switching doesn't happen. Just glows green. Brightness changes reflects.)
// https://docs.qmk.fm/features/rgblight

// const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_RED}
// );


// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, RGB_ORANGE}
// );

// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_PURPLE}
// );

// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_GREEN}
// );

// const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_RED}
// );

// const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, RGB_CHARTREUSE}
// );

// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     // bottom most takes precedence
//     my_capslock_layer,
//     my_layer1_layer,
//     my_layer2_layer,
//     my_layer3_layer,
//     my_layer4_layer,
//     my_layer5_layer
// );

// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, _COLEMAK));
//     return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
//     rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
//     rgblight_set_layer_state(5, layer_state_cmp(state, _KEYPAD));
//     return state;
// }
