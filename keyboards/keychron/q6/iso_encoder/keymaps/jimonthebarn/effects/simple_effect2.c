// enable effect by calling: rgb_matrix_mode(RGB_MATRIX_CUSTOM_simple_effect2);

static uint8_t some_global_state;

static void simple_effect2_complex_init(effect_params_t* params) {
    some_global_state = 1;
}

static bool simple_effect2_complex_run(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 0xff, some_global_state++, 0xff);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool simple_effect2(effect_params_t* params) {
    if (params->init) simple_effect2_complex_init(params);
    return simple_effect2_complex_run(params);
}
