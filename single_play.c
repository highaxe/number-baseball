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

    int answer = 0;                 //정답 숫자(정수형)
    int turn = 0;                   //게임 턴 수
    char input[20];                 //사용자 입력을 저장할 문자 배열

    generate_answer(number_digit, &answer);  //정답 난수 생성(FR_003)

    time_t start_time = time(NULL);   // 게임 시작 시각 기록

    printf("\n===== 싱글 플레이 모드 =====\n");
    printf("1~9 사이의 서로 다른 %d자리 숫자를 맞혀보세요 (중도 포기: q)\n", number_digit);

    while (1) {
        printf("\n[%d턴] %d자리 숫자 입력: ", turn + 1, number_digit);

        if (scanf("%s", input) != 1) {  //사용자에게 숫자로 쓰인 문자열 스캔, 정상적으로 글자 입력 받지 못했을 경우 예외처리
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

        // 스트라이크/볼 판정 및 정답 탈출
        int guess = atoi(input);    //입력받은 문자열을 정수로 변환
         
        bool correct = judge(answer, guess, NULL, NULL, true);      //싱글 플레이는 항상 판정 결과 출력해야해서 print_judge를 true로 설정
        printf("\n");

        if (correct) {
            break;              //정답이면 while 루프 탈출
        }
    }

    // 루프 탈출 후(정답을 맞춘 경우) 게임 종료 처리
    
    time_t end_time = time(NULL);                           // 게임 종료 시각 기록
    int time_sec = (int)difftime(end_time, start_time);     //플레이 타임 계산

    // result_screen 내부 getchar()가 앞선 엔터키('\n')를 먹고 바로 넘어가는 현상 방지
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    // 전적 저장 및 결과 화면 출력
    // playmod: 1 (싱글 플레이), result: true (승리)
    save_history(end_time, 1, answer, true, turn, time_sec);
    result_screen(1, answer, true, turn, time_sec); 



}