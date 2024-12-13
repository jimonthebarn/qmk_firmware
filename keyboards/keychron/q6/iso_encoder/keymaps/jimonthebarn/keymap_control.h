enum effects {
    GAME_MODE = 1,
};

void keyboard_post_init_user(void) {
    enum effects selectedEffect = GAME_MODE;
    switch (selectedEffect) {
        case GAME_MODE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_GAME_MODE);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A:
            if (record->event.pressed) {
                // Do something when the "A" key is pressed
                //rgblight_toggle();  // Example: Toggle RGB lighting
            } else {
                // Do something when the "A" key is released
            }
            break;

        case KC_B:
            if (record->event.pressed) {
                // Do something when the "B" key is pressed
            }
            break;

        default:
            break;
    }
    return true; // Process all other keycodes normally
}
