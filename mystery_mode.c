#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int number_digit;
extern bool debug;

void generate_answer(int digit, int* answer);
int is_game_quit(const char* input);
int validate_input(const char* input, int digit_len);
bool judge(int answer, int guess, int* strike, int* ball, bool print_judge);

void mystery_mode(void) {
    int rule;
    int answer, guess;
    int strike, ball;
    int turn = 1;
    int ban_number;
    int fix_position;
    int fix_number;
    int valid;
    char input[20];

    generate_answer(number_digit, &answer);

    printf("\n===== 미스터리 모드 =====\n");
    printf("중도 포기: q\n");

    while (1) {
        rule = rand() % 5;

        printf("\n===== %d턴 =====\n", turn);

        if (debug) {
            printf("[디버그] 정답: %d\n", answer);
            printf("[디버그] 규칙 번호: %d\n", rule);
        }

        if (rule == 0) {
            printf("제한 없음\n");
        }
        else if (rule == 1) {
            printf("볼 봉인\n");
        }
        else if (rule == 2) {
            printf("스트라이크 봉인\n");
        }
        else if (rule == 3) {
            ban_number = rand() % 9 + 1;
            printf("숫자 금지\n");
            printf("숫자 %d를 사용할 수 없습니다.\n", ban_number);
        }
        else if (rule == 4) {
            fix_position = rand() % number_digit;
            fix_number = rand() % 9 + 1;

            printf("위치 고정\n");
            printf("%d번째 숫자는 %d여야 합니다.\n",
                   fix_position + 1, fix_number);
        }

        while (1) {
            printf("%d자리 숫자 입력: ", number_digit);

            if (scanf("%19s", input) != 1) {
                return;
            }

            if (is_game_quit(input)) {
                return;
            }

            if (!validate_input(input, number_digit)) {
                continue;
            }

            if (rule == 3) {
                valid = 1;

                for (int i = 0; i < number_digit; i++) {
                    if (input[i] - '0' == ban_number) {
                        valid = 0;
                        break;
                    }
                }

                if (valid == 0) {
                    printf("금지된 숫자가 포함되어 있습니다.\n");
                    continue;
                }
            }

            if (rule == 4) {
                if (input[fix_position] - '0' != fix_number) {
                    printf("고정된 위치의 숫자가 올바르지 않습니다.\n");
                    continue;
                }
            }

            break;
        }

        guess = atoi(input);

        bool correct = judge(answer, guess, &strike, &ball, false);

        if (rule == 1) {
            printf("%dS ?B\n", strike);
        }
        else if (rule == 2) {
            printf("?S %dB\n", ball);
        }
        else if (strike == 0 && ball == 0) {
            printf("OUT\n");
        }
        else {
            printf("%dS %dB\n", strike, ball);
        }

        if (correct) {
            printf("\n정답입니다!\n");
            printf("정답: %d\n", answer);
            printf("소요 턴: %d\n", turn);
            return;
        }

        turn++;
    }
}

void mystery_info(void) {
    printf("\n===== 미스터리 모드 설명 =====\n");
    printf("매 턴마다 무작위 제한 규칙이 적용되는 숫자야구입니다.\n");

    printf("\n[제한 규칙 종류]\n");
    printf("1. 제한 없음: 일반 숫자야구와 동일합니다.\n");
    printf("2. 볼 봉인: 볼의 개수가 공개되지 않습니다.\n");
    printf("3. 스트라이크 봉인: 스트라이크의 개수가 공개되지 않습니다.\n");
    printf("4. 숫자 금지: 지정된 숫자를 사용할 수 없습니다.\n");
    printf("5. 위치 고정: 지정된 위치에 지정된 숫자를 입력해야 합니다.\n");

    printf("\n각 규칙은 모두 똑같은 확률로 적용됩니다.\n");
    printf("제한 규칙을 위반하면 다시 입력해야 합니다.\n");
    printf("잘못된 입력은 턴을 소모하지 않습니다.\n");
    printf("정답을 맞히면 게임이 종료됩니다.\n");
    printf("=============================\n");
}

void mystery_menu(void) {
    int choice;

    while (1) {
        printf("\n===== 미스터리 모드 =====\n");
        printf("1. 플레이\n");
        printf("2. 모드 설명\n");
        printf("0. 메인 메뉴로 돌아가기\n");
        printf("선택: ");

        if (scanf("%d", &choice) != 1) {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF);

            if (ch == EOF) {
                return;
            }

            printf("잘못된 입력입니다.\n");
            continue;
        }

        if (choice == 1) {
            mystery_mode();
        }
        else if (choice == 2) {
            mystery_info();
        }
        else if (choice == 0) {
            return;
        }
        else {
            printf("잘못된 메뉴 번호입니다.\n");
        }
    }
}