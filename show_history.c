
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 글자 색깔
#ifndef YELLOW
    #define YELLOW "\x1b[38;2;250;250;70m"
#endif
#ifndef BLUE
    #define BLUE "\x1b[38;2;14;100;237m"
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


void print_history(char* data);

int show_history() {

    FILE* fp = fopen("game_history.txt", "r");
    if (fp == NULL) {
        printf("game_history.txt fopen fail in show_history.txt\n");
        return 1;
    }
    
    // Get file's line count
    char buffer[1000];
    int line_count = 0;
    while (fgets(buffer, 1000, fp) != NULL) line_count++;
    rewind(fp);
    
    if (line_count == 0) {
        printf(GRAY "------------------------------\n" RESET);
        printf("기록이 없습니다\n");
        printf(GRAY "------------------------------\n" RESET);
        fclose(fp);
        return 0;
    }
    else if (line_count < 10) {
        
        // Allocate memory
        char** data = (char**)malloc(line_count * sizeof(char*));
        for (int i = 0; i < line_count; i++) {
            data[i] = (char*)malloc(1000);
            fgets(data[i], 1000, fp);
        }
        // Print from latest
        printf("최근 %d개 게임\n", line_count);
        for (int i = line_count - 1; i >= 0; i--) {
            print_history(data[i]);
        }
        printf(GRAY "------------------------------\n" RESET);
        // Free
        for (int i = 0; i < line_count; i++)
            free(data[i]);
        free(data);
    }
    else if (line_count >= 10) {

        // Advance until 10 line left
        for (int i = 0; i < (line_count - 10); i++)
            fgets(buffer, 1000, fp);
        
        // Allocate memory
        char** data = (char**)malloc(10 * sizeof(char*));
        for (int i = 0; i < 10; i++) {
            data[i] = (char*)malloc(1000);
            fgets(data[i], 1000, fp);
        }
        // Print from latest
        printf("\n\n[최근 10개 게임]\n");
        for (int i = 9; i >= 0; i--) {
            print_history(data[i]);
        }
        printf(GRAY "------------------------------\n" RESET);
        // Free
        for (int i = 0; i < 10; i++)
            free(data[i]);
        free(data);
    }
    

    fclose(fp);
    return 0;
}

void print_history(char* data) {


    long long l_time;
    int playmod, number, result, turn, time_sec;
    sscanf(data, "%lld %d %d %d %d %d\n",
        &l_time, &playmod, &number, &result, &turn, &time_sec);
    
    printf(GRAY "------------------------------\n" RESET);
    
    time_t t = (time_t)l_time;
    struct tm* tm_end = localtime(&t);

    printf("%d/%d/%d ", tm_end->tm_year - 100, tm_end->tm_mon, tm_end->tm_mday);
    
    // 싱글 플레이 모드
    if (playmod == 1) {
        printf("싱글 플레이 모드 ");
        printf("[" YELLOW "성공" RESET "]\n");
    }
    // 컴퓨터 대전 모드
    else if (playmod == 2) {
        printf("컴퓨터 대전 모드 ");
        if (result == 1) {
            printf("[" BLUE "승리" RESET "]\n");
        }
        else {
            printf("[" RED "패배" RESET "]\n");
        }
    }
    // 턴 제한 모드
    else {
        printf("턴 제한 모드 ");
        if (result == 1) {
            printf("[" BLUE "성공" RESET "]\n");
        }
        else {
            printf("[" RED "실패" RESET "]\n");
        }
    }

    // 시간
    printf("시간 ");
    if (time_sec >= 3600)
        printf("%d:", time_sec / 3600);
    printf("%d:", (time_sec % 3600) / 60);
    printf("%d ", time_sec % 60);

    // 정답
    printf("정답 %d ", number);
    // 턴
    printf("턴 %d\n", turn);
    return;
}