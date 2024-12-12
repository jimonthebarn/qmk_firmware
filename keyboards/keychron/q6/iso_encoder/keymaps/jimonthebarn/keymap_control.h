
enum effects {
    //Custom Gradient control keycode
    SIMPLE_EFFECT = 1,
    SIMPLE_EFFECT_2 = 2,
};

void keyboard_post_init_user(void){
    //user_config.raw = eeconfig_read_user();
    enum effects chosenEffect = SIMPLE_EFFECT;
    switch (chosenEffect) {
        case SIMPLE_EFFECT:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_simple_effect);
            break;
        case SIMPLE_EFFECT_2:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_simple_effect2);
            break;
    }
}


