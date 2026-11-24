#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void single_play_mode(void);
void turn_limit_mode(void);
void game_option(void);
int show_history();

void menu(){
    char input[20];

    while(1){
        printf("\n====================================\n");
        printf("          OSS 숫자야구 게임          \n");
        printf("====================================\n");
        printf("1. 싱글 플레이\n");
        printf("2. 컴퓨터 대전\n");
        printf("3. 턴 제한 모드\n");
        printf("4. 전적 조회\n");
        printf("5. 옵션\n");
        printf("6. 종료\n");
        printf("====================================\n");
        printf("메뉴를 선택하세요: ");

        if(scanf("%s", input)!=1)continue;
        
        //6번이나 "exit" 입력 시 종료
        if(strcmp(input, "6") == 0 || strcmp(input, "exit") == 0){
            printf("프로그램을 종료합니다\n");
            break;
        }

        // \n 제거
        char ch;
        while ((ch = getchar() != '\n') && ch != EOF);
        
        //번호에 따른 함수 호출
        if(strcmp(input, "1") == 0){
            //싱글플레이
            single_play_mode();
        } else if(strcmp(input, "2") == 0){
            //컴퓨터대전
        } else if(strcmp(input, "3") == 0){
            turn_limit_mode();
        } else if(strcmp(input, "4") == 0){
            //전적조회
            show_history();
        } else if(strcmp(input, "5") == 0){
            //옵션
            game_option();
        } else{
            //그 밖의 값
            printf("잘못된 입력입니다. 올바른 메뉴 번호를 입력해주세요.\n");
        }
    }
}