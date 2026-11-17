#include <stdio.h>
#include <stdbool.h>

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

//menu.c에 선언된 변수를 가져오기
extern int number_digit;
extern bool hide_ball;
extern bool hide_strike;

/*
int answer;
정답 숫자

int guess;
플레이어or컴퓨터가 입력한 추측 숫자 (예를 들어 345)

int* strike
계산된 스트라이크 개수를 저장할 변수의 주소 

int* ball
계산된 볼 개수를 저장할 변수의 주소 

bool print_judge
false - 화면 출력 안 함 (컴퓨터 AI 내부 추론 계산용)
true  - 판정 결과를 화면에 출력함 (hide_strike, hide_ball 옵션 반영)
*/

/* 함수 Return value
false - 오답 (스트라이크 개수 < number_digit)
true  - 정답 (스트라이크 개수 == number_digit)

*/

bool judge(int answer, int guess, int* strike, int* ball, bool print_judge) {   //answer을 345라고 생각해보자
    int ans_arr[10] = {0};          //정답 배열을 [0,0,0]으로 초기화
    int guess_arr[10] = {0};           //추측 배열을 [0,0,0]으로 초기화

    int temp_ans = answer;
    int temp_guess = guess;

    // answer와 guess를 자릿수만큼 배열로 분리하는 과정
    for (int i = number_digit - 1; i >= 0; i--) {
        ans_arr[i] = temp_ans % 10;           //number_digit이 3이라 치면 ans_arr[2] = 345 % 10이므로 ans_arr[2] = 5...이후 ans_arr[1]과 0은 각각 4와 3이 됨.
        temp_ans = temp_ans / 10;

        guess_arr[i] = temp_guess % 10;
        temp_guess = temp_guess / 10;
    }


    return false;
}



