
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TURNS 10

extern int number_digit;

void generate_answer(int n, int answer[]);
bool judge(int answer, int guess, int* strike, int* ball, bool print_judge);
int result_screen(int playmod, int number, bool result, int turn, int time_sec);

void turn_limit_mode(void) {

    int answer_arr[4];
    int answer = 0;
    int guess;
    int strike, ball;
    int turns_used = 0;
    bool correct = false;

    generate_answer(number_digit, answer_arr);

    for (int i = 0; i < number_digit; i++) {
        answer = answer * 10 + answer_arr[i];
    }

    time_t start_time = time(NULL);

    printf("\n===== 턴 제한 모드 =====\n");
    printf("최대 %d번 안에 정답을 맞혀보세요!\n", MAX_TURNS);

    while (turns_used < MAX_TURNS) {
        printf("\n남은 턴: %d\n", MAX_TURNS - turns_used);
        printf("%d자리 숫자 입력: ", number_digit);


        // 입력
        char input[100];
        scanf("%s", input);
        int ch;
        while ((ch = getchar() != '\n') && ch != EOF);

        // 'q' 입력 시 게임 종료
        if (is_game_quit(input)) {
            return;
        }

        // 유효하지 않은 입력일 시 다시 입력
        if (!validate_input(input, number_digit)) {
            continue;
        }

        int guess = atoi(input);

        turns_used++;

        correct = judge(answer, guess, &strike, &ball, true);
        printf("\n");

        // 정답
        if (correct) {
            break;
        }
    }

    int time_sec = (int)difftime(time(NULL), start_time);

    result_screen(3, answer, correct, turns_used, time_sec);
}