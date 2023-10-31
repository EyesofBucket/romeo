#include QMK_KEYBOARD_H

#if __has_include("secrets.h")
# include "secrets.h"
#endif

#if __has_include("macros.h")
# include "macros.h"
#endif

//CUSTOM_KEYCODES
enum custom_keycodes {
    HEARD = SAFE_RANGE,
    TALLY,
    MECH,
    BAR_L,
    BAR_R,
    OBSIDIAN_VIEW
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    break;
    case KC_P7:
        if (record->event.pressed) {
            if (secure_is_unlocked()) {
                SEND_STRING(SECRET_PHRASE);
                secure_lock();
                return false;
            } else {
                return true;
            }
        }
        return true;

    case HEARD:
        if (record->event.pressed) {
            SEND_STRING(MACRO_HEARD);
        }
        return true;

    case TALLY:
        if (record->event.pressed) {
            SEND_STRING(MACRO_TALLY); // selects all and copies
        }
        return true;

    case MECH:
        if (record->event.pressed) {
            SEND_STRING(MACRO_MECH); // selects all and copies
        }
        return true;
    
    case BAR_L:
        if (record->event.pressed) {
            layer_on(1);
        } else {
            layer_off(1);
        }
        return true;

    case BAR_R:
        if (record->event.pressed) {
            layer_on(1);
        } else {
            layer_off(1);
        }
        return true;

    case OBSIDIAN_VIEW:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_DOWN(X_F13));
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_DOWN(X_F14));
        } else {
            SEND_STRING(SS_UP(X_F13) SS_UP(X_LCTL) SS_UP(X_LSFT) SS_UP(X_LALT));
            SEND_STRING(SS_UP(X_F14) SS_UP(X_LCTL) SS_UP(X_LSFT) SS_UP(X_LALT));
        }
        return true;

    default:
        return true;
    }
};

//COMBOS
const uint16_t PROGMEM bar_combo[] = {BAR_L, BAR_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(bar_combo, TO(0))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /* Base Layer
        * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
        * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ Bspc│
        * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
        * │HyEsc │ A │ S │ D │ F │ G │ H │ J │ K │ L │   Enter│
        * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬──────┤
        * │Shift   │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│ ?/Sft│
        * ├────┬───┼───┼───┴───┴───┴───┴───┴───┴┬──┴─┬─┴─┬────┤
        * │Ctrl│Opt│Cmd│          Space         │ Cmd│Opt│ Lwr│
        * └────┴───┴───┴────────────────────────┴────┴───┴────┘
        */
        [_BASE] = LAYOUT_all( \
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
            HY_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT,  \
            KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SF_SLSH, \
            KC_LCTL, KC_LOPT, KC_LCMD,                            SPC_RAI,                   KC_RCMD, KC_ROPT, LOWER    \
        ),


        [1] = LAYOUT_all(
            KC_NO, KC_NO, KC_VOLU, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(3), TO(0), KC_NUM, 
            KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
            KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_BRID, KC_NO, KC_NO, KC_NO, TO(2), KC_NO, KC_NO, KC_NO, 
            KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
        ),

        [2] = LAYOUT_all(
            KC_TRNS, HEARD, TALLY, MECH, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

        [3] = LAYOUT_all(
            KC_TRNS, QK_BOOTLOADER, QK_REBOOT, QK_DEBUG_TOGGLE, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        )
};

layer_state_t layer_state_set_keymap(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}