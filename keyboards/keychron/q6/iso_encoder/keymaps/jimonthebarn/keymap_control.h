#include "print.h"

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool ctrl_held = false;
    static bool shift_held = false;

    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            ctrl_held = record->event.pressed;
        break;

        case KC_LSFT:
        case KC_RSFT:
            shift_held = record->event.pressed;
        break;

        case KC_X:
            if (record->event.pressed && ctrl_held && shift_held) {
                custom_preset_cycle();
                return false; // Prevent further processing of KC_X
            }
        break;
    }
    return true; // Process other keys normally
}
