#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "../ledmap.h"

#define RGB_CODING_BASE_COLOR        0xFF, 0x48, 0x08
#define RGB_CODING_ACCENT_COLOR        0x03, 0x1B, 0xFF

static bool CODING_MODE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // set base color
    rgb_matrix_set_color_all(RGB_CODING_BASE_COLOR);

    // set accents
    rgb_matrix_set_color(toLedIdx("ESC"), RGB_CODING_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("7"), RGB_CODING_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("8"), RGB_CODING_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("9"), RGB_CODING_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("0"), RGB_CODING_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("MINS"), RGB_CODING_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("NUBS"), RGB_CODING_ACCENT_COLOR);
    rgb_matrix_set_color(toLedIdx("+"), RGB_CODING_ACCENT_COLOR);

    //always on
    rgb_matrix_set_color(toLedIdx("CIRCLE"), RGB_RED);
    rgb_matrix_set_color(toLedIdx("TRIANGLE"), RGB_SPRINGGREEN);
    rgb_matrix_set_color(toLedIdx("SQUARE"), RGB_MAGENTA);
    rgb_matrix_set_color(toLedIdx("CROSS"), RGB_BLUE);

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
