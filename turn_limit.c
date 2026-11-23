#include "turn_limit.h"

void initialize_turn_limit(TurnLimit* game) {
    game->turns_used = 0;
    game->finished = false;
    game->success = false;
}

int get_remaining_turns(const TurnLimit* game) {
    return MAX_TURNS - game->turns_used;
}

void process_turn(TurnLimit* game, bool valid, bool correct) {
    if (game->finished || !valid) {
        return;
    }

    game->turns_used++;

    if (correct) {
        game->success = true;
        game->finished = true;
    }
    else if (game->turns_used >= MAX_TURNS) {
        game->success = false;
        game->finished = true;
    }
}