#ifndef TURN_LIMIT_H
#define TURN_LIMIT_H

#include <stdbool.h>

#define MAX_TURNS 10

typedef struct {
    int turns_used;
    bool finished;
    bool success;
} TurnLimit;

void initialize_turn_limit(TurnLimit* game);
int get_remaining_turns(const TurnLimit* game);
void process_turn(TurnLimit* game, bool valid, bool correct);

#endif