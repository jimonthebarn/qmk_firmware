#ifndef KEYMAP_CONTROL_H
#define KEYMAP_CONTROL_H

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef struct {
    const char* key;
    int value;
} KeycodeMap;

KeycodeMap key_to_led_index[] = {
    {"ESC", 0}, {"F1", 1}, {"F2", 2}, {"F3", 3}, {"F4", 4}, {"F5", 5}, {"F6", 6}, {"F7", 7}, {"F8", 8}, {"F9", 9}, {"F10", 10}, {"F11", 11}, {"F12", 12}, {"PRINT", 13}, {"MUTE", 14}, {"LIGHTS", 15}, {"CIRCLE", 16}, {"TRIANGLE", 17}, {"SQUARE", 18}, {"CROSS", 19},
    {"GRV", 20}, {"1", 21}, {"2", 22}, {"3", 23}, {"4", 24}, {"5", 25}, {"6", 26}, {"7", 27}, {"8", 28}, {"9", 29}, {"0", 30}, {"MINS", 31}, {"EQL", 32}, {"BSPC", 33}, {"INS", 34}, {"HOME", 35}, {"PGUP", 36}, {"NUM", 37}, {"NUM_DIV", 38}, {"NUM_MULT", 39}, {"NUM_MINUS", 40},
    {"TAB", 41}, {"Q", 42}, {"W", 43}, {"E", 44}, {"R", 45}, {"T", 46}, {"Z", 47}, {"U", 48}, {"I", 49}, {"O", 50}, {"P", 51}, {"Ü", 52}, {"+", 53}, {"DEL", 54},   {"END", 55},   {"PGDOWN", 56},{"NUM_7", 57}, {"NUM_8", 58}, {"NUM_9", 59},
    {"CAPS", 60}, {"A", 61}, {"S", 62}, {"D", 63}, {"F", 64}, {"G", 65}, {"H", 66}, {"J", 67}, {"K", 68}, {"L", 69}, {"Ö", 70}, {"Ä", 71}, {"#", 72}, {"ENTER", 73}, {"NUM_4", 74}, {"NUM_5", 75}, {"NUM_6", 76}, {"NUM_PLUS", 77},
    {"LSHIFT", 78}, {"NUBS", 79}, {"Y", 80}, {"X", 81}, {"C", 82}, {"V", 83}, {"B", 84}, {"N", 85}, {"M", 86}, {"SEMI", 87}, {"DOT", 88}, {"UNDER", 89}, {"RSHIFT", 90}, {"UP", 91}, {"NUM_1", 92}, {"NUM_2", 93}, {"NUM_3", 94},
    {"LCTRL", 95}, {"LWIN", 96}, {"LALT", 97}, {"SPACE", 98}, {"ALTGR", 99}, {"RWIN", 100}, {"FN", 101}, {"RCTRL", 102}, {"LEFT", 103}, {"DOWN", 104}, {"RIGHT", 105}, {"NUM_0", 106}, {"NUM_DOT", 107}, {"NUM_ENTER", 108},
};

int toLedIdx(const char* key) {
    for (int i = 0; key_to_led_index[i].key != NULL; i++) {
        if (strcmp(key, key_to_led_index[i].key) == 0) {
            return key_to_led_index[i].value;
        }
    }
    return 0;
}

#endif //RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#endif //KEYMAP_CONTROL_H