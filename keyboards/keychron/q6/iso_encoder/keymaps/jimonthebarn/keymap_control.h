#include "print.h"
#include "keymap.h"

#define KC_CAD LSHFT(KC_F10)

enum MyPresets {
    GAME_MODE = 1,
    CODING_MODE,
    PRESET_COUNT
};

enum MyPresets selectedPreset = GAME_MODE;

void keyboard_post_init_user(void) {
    debug_enable=true;

    switch (selectedPreset) {
        case GAME_MODE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_GAME_MODE);
            break;
        case CODING_MODE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_CODING_MODE);
            break;
        default:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_GAME_MODE);
    }
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
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_GAME_MODE);
            selectedPreset = GAME_MODE;
        break;
        case CODING_MODE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_CODING_MODE);
            selectedPreset = CODING_MODE;
        break;
        default:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_CODING_MODE);
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
                dprintf("Keycode pressed = M8\n");
                return false;
            }
        break;
    }
    return true; // Process other keys normally
}
