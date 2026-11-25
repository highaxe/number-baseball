#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int initialized = 0;

void generate_answer(int digit, int* answer) {

    if(initialized == 0) {
        srand((unsigned int)time(NULL));
        initialized = 1;
    }

    int numbers[9]= {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i=8;i>0;i--) {
        int j=rand() % (i+1);

        int temp=numbers[i];
        numbers[i]=numbers[j];
        numbers[j]=temp;
    }

    for(int i=0;i<digit;i++) {
        *answer *= 10;
        *answer += numbers[i];
    }   
}