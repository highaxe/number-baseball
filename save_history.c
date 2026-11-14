#include <stdio.h>

/* 함수 인자
- time_t end_time
게임 종료 시간

- 나머지
result_screen.c와 같음
*/

/*
함수 Return value
1 - 오류
0 - 성공
*/
int save_history(time_t end_time, int playmod, int number, bool result, int turn, int time_sec) {
    
    FILE* fp = fopen("game_history.txt", "a");
    if (fp == NULL) {
        printf("game_history.txt fopen failed\n");
        return 1;
    }

    fprintf(fp, "%lld %d %d %d %d %d\n",
        (long long)end_time, playmod, number, result, turn, time_sec);
    
    fclose(fp);
    return 0;
}