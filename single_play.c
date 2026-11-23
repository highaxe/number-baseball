#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// game_option.c에 선언된 자릿수 변수 참조
extern int number_digit;

//외부 모듈 함수를 선언
void generate_answer(int n, int answer[]);
int is_game_quit(const char *input);
int validate_input(const char *input, int digit_len);
bool judge(int answer, int guess, int* strike, int* ball, bool print_judge);
int result_screen(int playmod, int number, bool result, int turn, int time_sec);
int save_history(time_t end_time, int playmod, int number, bool result, int turn, int time_sec);