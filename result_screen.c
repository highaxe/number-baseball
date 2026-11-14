#include <stdio.h>
#define YELLOW "\x1b[38;2;250;250;70m"
#define GRAY "\x1b[38;2;250;250;70m"
#define RED "\x1b[38;2;250;70;70m"
#define RESET "\033[0m"

/* 함수 인자
- int playmod
1 - 싱글 플레이 모드
2 - 컴퓨터 대전 모드
3 - 턴 제한 모드

- bool result
0 - 패배/실패
1 - 승리/성공

- int turn
턴 수

- int time_sec
게임 걸린 시간(초)
*/

/* 함수 Return value
1 - 오류
0 - 문제 없음
*/

/* <화면 출력 예시>

------------------------------
[성공]

싱글 플레이 모드

10턴

3분 30초

[Enter] 메뉴로 돌아가기
------------------------------

*/
int result_screen(int playmod, bool result, int turn, int time_sec) {


    printf("------------------------------\n");
    
    // 싱글 플레이 모드
    if (playmod == 1) {
        printf("[" YELLOW "성공" RESET "]\n\n");
        printf("싱글 플레이 모드\n\n");
    }
    // 컴퓨터 대전 모드
    else if (playmod == 2) {
        // 승리
        if (result == 1) {
            printf("[" YELLOW "승리" RESET "]\n\n");
        }
        // 패배
        else {
            printf("[" RED "패배" RESET "]\n\n");
        }
        printf("컴퓨터 대전 모드\n\n");
    }
    // 턴 제한 모드
    else if (playmod == 3) {
        // 성공
        if (result == 1) {
            printf("[" YELLOW "성공" RESET "]\n\n");
        }
        // 실패
        else {
            printf("[" RED "실패" RESET "]\n\n");
        }
        printf("턴 제한 모드\n\n");
    }
    else {
        printf(RED "유효하지 않은 playmod 변수값\n" RESET);
        return 1;
    }

    // 턴
    printf("%d턴\n\n", turn);

    // 시간
    if (time_sec >= 3600)
        printf("%d시간 ", time_sec / 3600);
    if (time_sec >= 60)
        printf("%d분 ", (time_sec % 3600) / 60);
    printf("%d초\n\n", time_sec % 60);

    printf("[Enter] 메뉴로 돌아가기\n");
    printf("------------------------------\n");

    // Enter 입력
    while (getchar() != '\n');

    return 0;

}