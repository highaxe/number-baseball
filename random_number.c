#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int initialized = 0;

void generate_answer(int digit, int* answer) {

    if(initialized == 0) {
        srand((unsigned int)time(NULL));
        initialized = 1;
    }

    // 정답 생성
    *answer = 0;
    for (int i = 0; i < digit; i++) {
        *answer *= 10;
        *answer += rand() % 9 + 1;
    }
   
}