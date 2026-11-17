#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generate_answer(int n, int answer[]) {
    int numbers[9]= {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i=8;i>0;i--) {
        int j=rand() % (i+1);

        int temp=numbers[i];
        numbers[i]=numbers[j];
        numbers[j]=temp;
    }

    for(int i=0;i<n;i++) {
        answer[i]=numbers[i];
    }
}