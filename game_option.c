#include <stdio.h>
#include "game_option.h"

int number_digit = 3;
bool hide_ball = false;
bool hide_strike = false;

void game_option(void) {
    int choice;
    int digit;

    while (1) {
        printf("\n===== 게임 옵션 =====\n");
        printf("현재 자릿수: %d\n", number_digit);
        printf("볼 숨기기: %s\n", hide_ball ? "ON" : "OFF");
        printf("스트라이크 숨기기: %s\n", hide_strike ? "ON" : "OFF");
        printf("=====================\n");
        printf("1. 자릿수 변경\n");
        printf("2. 볼 숨기기 전환\n");
        printf("3. 스트라이크 숨기기 전환\n");
        printf("0. 메인 메뉴로 돌아가기\n");
        printf("선택: ");

        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("잘못된 입력입니다.\n");
            continue;
        }

        if (choice == 0) {
            return;
        }
        else if (choice == 1) {
            printf("자릿수 입력 (3 또는 4): ");

            if (scanf("%d", &digit) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("잘못된 입력입니다.\n");
                continue;
            }

            if (digit == 3 || digit == 4) {
                number_digit = digit;
                printf("자릿수가 %d로 변경되었습니다.\n", number_digit);
            }
            else {
                printf("3 또는 4만 선택할 수 있습니다.\n");
            }
        }
        else if (choice == 2) {
            hide_ball = !hide_ball;
        }
        else if (choice == 3) {
            hide_strike = !hide_strike;
        }
        else {
            printf("잘못된 메뉴 번호입니다.\n");
        }
    }
}
