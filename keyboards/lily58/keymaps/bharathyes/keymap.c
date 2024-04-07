#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _KEYPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Grave/ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  BSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  -   |
 * |------+------+------+------+------+------|   BS  |    |  DEL  |------+------+------+------+------+------|
 * |LShift|   Z  |  X   |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |  =   a
 |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  QK_GESC,        KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  LT( _KEYPAD, KC_TAB),  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  OSM(MOD_LCTL),  LGUI_T(KC_A),   LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), MEH_T(KC_G),  HYPR_T(KC_M), LCTL_T(KC_N), LSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),    KC_MINS,
  OSM(MOD_LSFT),  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, QK_LEAD,  KC_DEL,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                        LALT_T(KC_ENT), KC_LGUI, MO(_LOWER), KC_SPC, LSFT_T(KC_ENT), MO(_RAISE), KC_BSPC, TT( _KEYPAD)
),
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

/* [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI
),*/
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                  KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
   _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  MO(_ADJUST), _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    | PGUP | HOME |  Up  |  END |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| PGDN | Left | Down |Right |      | PSCR |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_PGUP, KC_HOME, KC_UP,    KC_END,    KC_MS_WH_UP,   KC_BTN1,
  KC_F1,  LGUI_T(KC_F2), LALT_T(KC_F3), LSFT_T(KC_F4), LCTL_T(KC_F5),   KC_F6,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,   KC_MS_WH_DOWN, KC_PSCR,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, MO(_ADJUST),  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,
  QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_MAKE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),
  /* KEYPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_KEYPAD] = LAYOUT(
  KC_PAUSE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                   XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PAST, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                   KC_BSPC, KC_4,    KC_5,    KC_6,    KC_PMNS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_PPLS, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};



/*

Features to explore


// for thumb cluster
MT(MOD_LSFT, KC_BSPC) for backspace on tap and shift on hold;
LT(_FUN, KC_ENT) for enter on tap and switching to the _FUN layer on hold;
LT(_SYB, KC_SPC) for space on tap and switching to the _SYB layer on hold.


// TAP DANCE GUIDE
https://docs.qmk.fm/#/feature_tap_dance
https://thomasbaart.nl/2018/12/13/qmk-basics-tap-dance/


// RESET and BOOTLOADER
https://docs.qmk.fm/#/ref_functions?id=resetting-the-keyboard


// LEADER key
https://docs.qmk.fm/#/feature_leader_key
#define ENABLE_COMPILE_KEYCODE


// AUDIO
https://docs.qmk.fm/#/feature_audio

*/


//**************** UNICODE *********************//


#ifdef UNICODE_COMMON

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    THUMBUP
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [THUMBUP]   =   0x1F44D, // 
};

#endif


//**************** LEADER *********************//

#ifdef LEADER_ENABLE

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_ESC)) {
        tap_code16(KC_PAUSE);
    } else if (leader_sequence_two_keys(KC_O, KC_K)) {
        SEND_STRING("Okay.");
    }  else if (leader_sequence_two_keys(KC_P, KC_U)) {
        SEND_STRING("bharathyes");
    } else if (leader_sequence_two_keys(KC_P, KC_G)) {
        SEND_STRING("bharathyes.in@gmail.com");
    } else if (leader_sequence_two_keys(KC_P, KC_O)) {
        SEND_STRING("bharathyes@outlook.com");
    } else if (leader_sequence_two_keys(KC_W, KC_E)) {
        SEND_STRING("bharathyes@techconative.com");
    } else if (leader_sequence_two_keys(KC_D, KC_U)) {
        SEND_STRING("bsrinivasan");
    } else if (leader_sequence_two_keys(KC_D, KC_E)) {
        SEND_STRING("bsrinivasan@dalet.com");
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_G)) {
        SEND_STRING("https://start.duckduckgo.com\n");
    } else if (leader_sequence_two_keys(KC_G, KC_M)) {
        // open git menu - intellij
        tap_code16(LCTL(LSFT(LALT(KC_GRAVE))));
    } else if (leader_sequence_two_keys(KC_I, KC_D)) {
        // start application in run - intellij
        SEND_STRING(SS_LALT(SS_LSFT("d")));
    } else if (leader_sequence_two_keys(KC_I, KC_R)) {
        // start application in debug - intellij
        SEND_STRING(SS_LALT(SS_LSFT("x")));
    } else if (leader_sequence_two_keys(KC_I, KC_C)) {
        // run select menu - intellij
        tap_code16(LALT(LSFT(KC_F10)));
    } else if (leader_sequence_two_keys(KC_I, KC_X)) {
        // debug select menu - intellij
        tap_code16(LALT(LSFT(KC_F9)));
    } else if (leader_sequence_two_keys(KC_I, KC_S)) {
        // stop application
        tap_code16(LCTL(KC_F2));
    } else if (leader_sequence_three_keys(KC_I, KC_D, KC_M)) {
        // mute debug points 
        tap_code16(LCTL(LALT(LSFT(KC_F12))));
    } else if (leader_sequence_three_keys(KC_C, KC_H, KC_S)) {
        // hot swap - code
        tap_code16(LCTL(LSFT(KC_F9)));
    } else if (leader_sequence_two_keys(KC_P, KC_I)) {
        SEND_STRING("qw@4134");
    }  else if (leader_sequence_two_keys(KC_F, KC_I)) {
        SEND_STRING("qWa@413A");
    }
}


#endif /* LEADER */


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

/*  Send 'delete' when 'Shift+Backspace' is pressed.
    https://docs.qmk.fm/#/feature_key_overrides?id=simple-example
*/
// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &delete_key_override,
//     NULL // Null terminate the array of overrides!
// };


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_BSPC):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}