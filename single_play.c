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

void single_play_mode(void) {
    int answer_arr[4] = {0};
    int answer = 0;

    generate_answer(number_digit, answer_arr);  //정답 난수 생성(FR_003), 자릿수와 정답 배열을 인자로 전달
    for (int i = 0; i < number_digit; i++) {
        answer = answer * 10 + answer_arr[i];
    }                                           // 예를 들어 [1, 2, 3, 4]이면 1234로 변환

    // 게임 시작 시각 기록
    time_t start_time = time(NULL);

}