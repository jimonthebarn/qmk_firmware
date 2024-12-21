#include "print.h"
#include "keymap.h"

enum MyPresets {
    GAME_MODE = 1,
    CODING_MODE,
    PRESET_COUNT
};

enum MyPresets selectedPreset = GAME_MODE;

void set_matrix_mode(uint8_t mode) {
    rgb_matrix_mode(mode);
}

void set_preset(enum MyPresets preset) {
    switch (preset) {
        case GAME_MODE:
            set_matrix_mode(RGB_MATRIX_CUSTOM_GAME_MODE);
            selectedPreset = GAME_MODE;
        break;
        case CODING_MODE:
            set_matrix_mode(RGB_MATRIX_CUSTOM_CODING_MODE);
            selectedPreset = CODING_MODE;
        break;
        default:
            set_matrix_mode(RGB_MATRIX_CUSTOM_GAME_MODE);
            selectedPreset = CODING_MODE;
    }
}

void keyboard_post_init_user(void) {
    debug_enable=true;
    set_preset(selectedPreset);
}

void custom_preset_cycle(void) {
    if (selectedPreset+1 == PRESET_COUNT) {
        selectedPreset = 1;
    } else {
        selectedPreset = (enum MyPresets)(selectedPreset + 1);
    }
    dprintf("Switching to preset = %u\n", selectedPreset);
    switch (selectedPreset) {
        case GAME_MODE:
            set_matrix_mode(RGB_MATRIX_CUSTOM_GAME_MODE);
            selectedPreset = GAME_MODE;
        break;
        case CODING_MODE:
            set_matrix_mode(RGB_MATRIX_CUSTOM_CODING_MODE);
            selectedPreset = CODING_MODE;
        break;
        default:
            set_matrix_mode(RGB_MATRIX_CUSTOM_CODING_MODE);
            selectedPreset = CODING_MODE;
    }
}

void toggle_teams_mic(void) {
    SEND_STRING(SS_LCTL(SS_LSFT("m")));
}

void initiate_idea_build(void) {
    register_code(KC_LSFT);
    tap_code(KC_F10);
    unregister_code(KC_LSFT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case MO(MAC_FN):
        case MO(WIN_FN):
            if (record->event.pressed) {
                // teporarily set custom preset
                set_matrix_mode(RGB_MATRIX_CUSTOM_FUNCTION_MODE);
            } else {
                // restore previous preset
                set_preset(selectedPreset);
            }
        break;
        case PRESETS:
            if (record->event.pressed) {
                custom_preset_cycle();
                return false;
            }
        break;
        case M0:
            if (record->event.pressed) {
                toggle_teams_mic();
                return false;
            }
        break;
        case M1:
            if (record->event.pressed) {
                initiate_idea_build();
                return false;
            }
        break;
        case M2:
            if (record->event.pressed) {
                dprintf("Keycode pressed = M2\n");
                return false;
            }
        break;
        case M3:
            if (record->event.pressed) {
                dprintf("Keycode pressed = M3\n");
                return false;
            }
        break;
        case M4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("h")));
                return false;
            }
        break;
        case M5:
            if (record->event.pressed) {
                dprintf("Keycode pressed = M5\n");
                return false;
            }
        break;
        case M6:
            if (record->event.pressed) {
                dprintf("Keycode pressed = M6\n");
                return false;
            }
        break;
        case M7:
            if (record->event.pressed) {
                dprintf("Keycode pressed = M7\n");
                return false;
            }
        break;
        case M8:
            if (record->event.pressed) {
                dprintf("Going into hibernate.\n");
                SEND_STRING("shutdown /h\n");
                return false;
            }
        break;
    }
    return true; // Process other keys normally
}
