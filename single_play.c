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
    int turn = 0;   //게임 턴 수
    char input[20]; //사용자 입력을 저장할 문자 배열

    generate_answer(number_digit, answer_arr);  //정답 난수 생성(FR_003), 자릿수와 정답 배열을 인자로 전달
    for (int i = 0; i < number_digit; i++) {
        answer = answer * 10 + answer_arr[i];
    }                                           // 예를 들어 [1, 2, 3, 4]이면 1234로 변환

    // 게임 시작 시각 기록
    time_t start_time = time(NULL);

    printf("\n===== 싱글 플레이 모드 =====\n");
    printf("1~9 사이의 서로 다른 %d자리 숫자를 맞혀보세요 (중도 포기: q)\n", number_digit);

    while (1) {
        printf("\n[%d턴] %d자리 숫자 입력: ", turn + 1, number_digit);

        if (scanf("%s", input) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        // 중도 포기 판정, 유효성 검증보다 먼저 실행함
        if (is_game_quit(input)) {
            return;
        }

        // 입력 유효성 검증, 실패 시 턴 수 증가 없이 재입력
        if (!validate_input(input, number_digit)) {
            continue; // turn++ 안하고 while 루프 처음으로 돌아감
        }

        // 유효한 입력이면 턴 수 증가
        turn++;
    }




}