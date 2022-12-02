#include QMK_KEYBOARD_H



//#pragma region CUSTOM_KEYCODES
enum custom_keycodes {
    HEARD = SAFE_RANGE,
    TALLY,
    BAR_L,
    BAR_R,
    OBSIDIAN_VIEW
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_P7:
        if (record->event.pressed) {
            if (secure_is_unlocked()) {
                SEND_STRING("secret\n");
                secure_lock();
                return false;
            } else {
                return true;
            }
        }
        return true;

    case HEARD:
        if (record->event.pressed) {
            SEND_STRING("Did you ever hear the tragedy of Darth Plagueis the Wise?\n\nI thought not.\n\nIt's not a story the Jedi would tell you.\n\nIt's a Sith legend.\n\nDarth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life...\n\nHe had such a knowledge of the dark side that he could even keep the ones he cared about from dying.\n\nThe dark side of the Force is a pathway to many abilities some consider to be unnatural.\n\nHe became so powerful... the only thing he was afraid of was losing his power, which eventually, of course, he did.\n\nUnfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep.\n\nIronic, he could save others from death, but not himself.");
        }
        return true;

    case TALLY:
        if (record->event.pressed) {
            SEND_STRING("Own a musket for home defense, since that's what the founding fathers intended.\nFour ruffians break into my house.\n\n\"What the devil?\"\n\nAs I grab my powdered wig and Kentucky rifle.\nBlow a golf ball sized hole through the first man, he's dead on the spot.\nDraw my pistol on the second man, miss him entirely because it's smoothbore and nails the neighbors dog.\nI have to resort to the cannon mounted at the top of the stairs loaded with grape shot,\n\n\"Tally ho lads\"\n\nthe grape shot shreds two men in the blast, the sound and extra shrapnel set off car alarms.\nFix bayonet and charge the last terrified rapscallion.\nHe Bleeds out waiting on the police to arrive since triangular bayonet wounds are impossible to stitch up.\n\nJust as the founding fathers intended."); // selects all and copies
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
//#pragma endregion CUSTOM_KEYCODES

//#pragma region COMBOS
const uint16_t PROGMEM bar_combo[] = {BAR_L, BAR_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(bar_combo, TO(0))
};
//#pragma endregion COMBOS

//#pragma region KEYMAPS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        
        //#pragma region 0_BASE_LAYER
        [0] = LAYOUT_all(
            KC_TAB, KC_F13, KC_F14, KC_F15, KC_F16, KC_HOME, KC_PGUP, KC_P7, KC_P8, KC_P9, KC_P0, KC_BSPC,
            KC_INS, KC_F17, KC_F18, KC_F19, KC_F20, OBSIDIAN_VIEW, KC_PGDN, KC_P4, KC_P5, KC_P6, KC_PENT,
            KC_LSFT, KC_LALT, KC_F21, KC_F22, KC_F23, KC_F24, LCA(KC_DEL), LGUI(KC_L), KC_P1, KC_P2, KC_P3, KC_RSFT,
            KC_LCTL, KC_LGUI, KC_NO, BAR_L, SECURE_REQUEST, BAR_R, KC_NO, KC_APP, KC_RCTL
        ),
        //#pragma endregion 0_BASE_LAYER

        //#pragma region BAR_SELECTOR_LAYER
        [1] = LAYOUT_all(
            KC_NO, KC_NO, KC_VOLU, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(3), TO(0), KC_NUM, 
            KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
            KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_BRID, KC_NO, KC_NO, KC_NO, TO(2), KC_NO, KC_NO, KC_NO, 
            KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
        ),
        //#pragma endregion BAR_SELECTOR_LAYER

        //#pragma region 1_MACRO_LAYER
        [2] = LAYOUT_all(
            KC_TRNS, HEARD, TALLY, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
        //#pragma endregion 1_MACRO_LAYER

        //#pragma region 9_QMK_DEV_LAYER
        [3] = LAYOUT_all(
            KC_TRNS, QK_BOOTLOADER, QK_REBOOT, QK_DEBUG_TOGGLE, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        )
        //#pragma endregion 9_QMK_DEV_LAYER
};
//#pragma endregion KEYMAPS

/* LAYER TEMPLATE
        //#pragma region #_LAYER
        [#] = LAYOUT_all(
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        )
        //#pragma endregion #_LAYER
*/