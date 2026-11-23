#include "game_option.h"

void initialize_options(GameOptions* options) {
    options->number_digit = 3;
    options->hide_ball = false;
    options->hide_strike = false;
}

bool set_number_digit(GameOptions* options, int digit) {
    if (digit != 3 && digit != 4) {
        return false;
    }

    options->number_digit = digit;
    return true;
}

void toggle_hide_ball(GameOptions* options) {
    options->hide_ball = !options->hide_ball;
}

void toggle_hide_strike(GameOptions* options) {
    options->hide_strike = !options->hide_strike;
}

extern int number_digit;
extern bool hide_ball;
extern bool hide_strike;

void load_game_options(GameOptions* options) {
    options->number_digit = number_digit;
    options->hide_ball = hide_ball;
    options->hide_strike = hide_strike;
}

void apply_game_options(const GameOptions* options) {
    number_digit = options->number_digit;
    hide_ball = options->hide_ball;
    hide_strike = options->hide_strike;
}
