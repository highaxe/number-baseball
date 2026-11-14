#include <stdio.h>

// 글자 색깔
#ifndef YELLOW
    #define YELLOW "\x1b[38;2;250;250;70m"
#endif
#ifndef RED
    #define RED "\x1b[38;2;250;70;70m"
#endif
#ifndef GRAY
    #define GRAY "\033[90m"
#endif
#ifndef RESET
    #define RESET "\033[0m"
#endif

/* 함수 인자
- int playmod
1 - 싱글 플레이 모드
2 - 컴퓨터 대전 모드
3 - 턴 제한 모드

- int number
정답 숫자

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

정답 345

10턴

3분 30초

[Enter] 메뉴로 돌아가기
------------------------------

*/
int result_screen(int playmod, int number, bool result, int turn, int time_sec) {


    printf(GRAY "------------------------------\n" RESET);
    
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

    // 정답 숫자
    printf("정답 %d\n\n", number);

    // 턴
    printf("%d턴\n\n", turn);

    // 시간
    if (time_sec >= 3600)
        printf("%d시간 ", time_sec / 3600);
    if (time_sec >= 60)
        printf("%d분 ", (time_sec % 3600) / 60);
    printf("%d초\n\n", time_sec % 60);

    printf("[Enter] 메뉴로 돌아가기\n");
    printf(GRAY "------------------------------\n" RESET);

    // Enter 입력
    while (getchar() != '\n');

    return 0;

}