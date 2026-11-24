#include <stdio.h>
#include <stdbool.h>

int number_digit = 3;
bool hide_ball = false;
bool hide_strike = false;

void game_option(void) {
    int choice;
    int digit;

    // 화면 아래에 메시지를 출력
    /* printno
    0 - 오류 없음
    아래 순서별로 1 ~ 7
    */
    int printno = 0;
    char* wrong_input = "잘못된 입력입니다.\n";
    char* digit_change = "자릿수가 변경되었습니다.\n";
    char* digit_limit = "3 또는 4만 선택할 수 있습니다.\n";
    char* option_limit = "스트라이크와 볼을 동시에 숨길 수 없습니다.\n";
    char* wrong_number = "잘못된 메뉴 번호입니다.\n";
    char* strike_change = "스트라이크 옵션이 변경되었습니다.\n";
    char* ball_change = "볼 옵션이 변경되었습니다.\n";

    while (1) {
        printf("\n===== 게임 옵션 =====\n");
        printf("현재 자릿수: %d\n", number_digit);
        printf("볼 숨기기: %s\n", hide_ball ? "ON" : "OFF");
        printf("스트라이크 숨기기: %s\n", hide_strike ? "ON" : "OFF");
        printf("=====================\n");
        printf("1. 자릿수 변경\n");
        printf("2. 볼 숨기기 전환\n");
        printf("3. 스트라이크 숨기기 전환\n");
        printf("0. 메인 메뉴로 돌아가기\n\n");

        // 메시지 출력
        if (printno == 1) printf("%s", wrong_input);
        else if (printno == 2) printf("%s", digit_change);
        else if (printno == 3) printf("%s", digit_limit);
        else if (printno == 4) printf("%s", option_limit);
        else if (printno == 5) printf("%s", wrong_number);
        else if (printno == 6) printf("%s", strike_change);
        else if (printno == 7) printf("%s", ball_change);

        // 초기화
        printno = 0;

        printf("선택: ");

        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printno = 1;
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
                printno = 1;
                continue;
            }

            if (digit == 3 || digit == 4) {
                number_digit = digit;
                printno = 2;
            }
            else {
                printno = 3;
            }
        }
        else if (choice == 2) {
            if (hide_ball == false && hide_strike == true) {
                printno = 4;
            }
            else {
                hide_ball = !hide_ball;
                printno = 7;
            }
        }
        else if (choice == 3) {
            if (hide_ball == true && hide_strike == false) {
                printno = 4;
            }
            else {
                hide_strike = !hide_strike;
                printno = 6;
            }
        }
        else {
            printno = 5;
        }
    }
}
