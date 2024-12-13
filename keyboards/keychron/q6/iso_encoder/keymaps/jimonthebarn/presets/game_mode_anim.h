#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "../ledmap.h"

static bool GAME_MODE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // set base color
    rgb_matrix_set_color_all(RGB_PURPLE);

    // set accents
    rgb_matrix_set_color(toLedIdx("ESC"), RGB_YELLOW);
    rgb_matrix_set_color(toLedIdx("W"), RGB_YELLOW);
    rgb_matrix_set_color(toLedIdx("A"), RGB_YELLOW);
    rgb_matrix_set_color(toLedIdx("S"), RGB_YELLOW);
    rgb_matrix_set_color(toLedIdx("D"), RGB_YELLOW);

    // always on
    rgb_matrix_set_color(toLedIdx("CIRCLE"), RGB_RED);
    rgb_matrix_set_color(toLedIdx("TRIANGLE"), RGB_SPRINGGREEN);
    rgb_matrix_set_color(toLedIdx("SQUARE"), RGB_MAGENTA);
    rgb_matrix_set_color(toLedIdx("CROSS"), RGB_BLUE);

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
