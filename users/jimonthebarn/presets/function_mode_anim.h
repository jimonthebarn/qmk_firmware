#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "../ledmap.h"

#define RGB_ACCENT_COLOR        0x03, 0x1B, 0xFF

static bool FUNCTION_MODE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // disable all
    rgb_matrix_set_color_all(RGB_OFF);

    // enable LED on available function keys
    rgb_matrix_set_color(toLedIdx("ESC"), RGB_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("LIGHTS"), RGB_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("MUTE"), RGB_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("FN"), RGB_ACCENT_COLOR);

    // always on
    rgb_matrix_set_color(toLedIdx("CIRCLE"), RGB_RED);
    rgb_matrix_set_color(toLedIdx("TRIANGLE"), RGB_SPRINGGREEN);
    rgb_matrix_set_color(toLedIdx("SQUARE"), RGB_MAGENTA);
    rgb_matrix_set_color(toLedIdx("CROSS"), RGB_BLUE);

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
