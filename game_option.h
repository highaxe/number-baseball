#ifndef GAME_OPTIONS_H
#define GAME_OPTIONS_H

#include <stdbool.h>

typedef struct {
    int number_digit;
    bool hide_ball;
    bool hide_strike;
} GameOptions;

void initialize_options(GameOptions* options);
bool set_number_digit(GameOptions* options, int digit);
void toggle_hide_ball(GameOptions* options);
void toggle_hide_strike(GameOptions* options);

void load_game_options(GameOptions* options);
void apply_game_options(const GameOptions* options);
#endif