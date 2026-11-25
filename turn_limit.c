
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TURNS 10

extern int number_digit;

void generate_answer(int n, int answer[]);
bool judge(int answer, int guess, int* strike, int* ball, bool print_judge);
int result_screen(int playmod, int number, bool result, int turn, int time_sec);
int save_history(time_t end_time, int playmod, int number, bool result, int turn, int time_sec);

void turn_limit_mode(void) {

    int answer = 0;
    int turns_used = 0;
    bool correct = false;

    // 정답 숫자 생성
    generate_answer(number_digit, &answer);

    // 시작 시간
    time_t start_time = time(NULL);

    printf("\n===== 턴 제한 모드 =====\n");
    printf("최대 %d번 안에 정답을 맞혀보세요!\n", MAX_TURNS);

    // 턴
    while (turns_used < MAX_TURNS) {

        // 디버그 모드 정답 표시
        if (debug == true) printf("[디버그] 정답: %d\n", answer);
        
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

        turns_used++;

        // 판정
        int guess = atoi(input);
        correct = judge(answer, guess, NULL, NULL, true);
        printf("\n");

        // 정답
        if (correct) {
            break;
        }
    }

    // 플레이 시간
    int end_time = time(NULL);
    int time_sec = (int)difftime(end_time, start_time);

    // 결과 저장
    save_history(end_time, 3, answer, correct, turns_used, time_sec);

    // 결과 화면
    result_screen(3, answer, correct, turns_used, time_sec);
}