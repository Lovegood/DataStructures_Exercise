#include <stdio.h>
#include <stdlib.h>
#define MAX 101

typedef struct{
    int data[MAX];
    int top;
}SeqStack;

void cnt(int);

int main(){
    int input;
    while( scanf("%d",&input) != EOF){
        cnt(input);
    }

    return 0;
}

void cnt(int tmp){
    // create stack
    SeqStack * s = (SeqStack*)malloc(sizeof(SeqStack));
    s->top = -1;

    // calculate
    while(tmp > 0){
        s->data[++(s->top)] = tmp % 2;
        tmp /= 2;
    }

    // output
    int index = s->top;
    while(index >= 0){
        printf("%d", s->data[index--]);
    }
    printf("\n");
}
