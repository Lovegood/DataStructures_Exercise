#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 101

typedef char type;
typedef struct{
    type data[MAX];
    int top;
}SeqStack;

SeqStack * createSeqStack();
void push(SeqStack*,type);
void pop(SeqStack*,type*);

int main(){
    // get input
    type input[MAX];
    scanf("%s",&input[0]);

    int len = strlen(input);

    //create a stack
    SeqStack * s = createSeqStack();

    // push to stack
    for(int i = 0; i < len; i++){
        push(s, input[i]);
    }

    // pop from stack
    type popResult[MAX];
    for(int i = 0; i < len; i++){
        pop(s, &popResult[i]);
    }

    //printf("print:%s\n", popResult);

    if( strcmp(input, popResult) == 0 ){
        printf("回文");
    }else{
        printf("不是回文");
    }

    return 0;
}

SeqStack * createSeqStack(){
    SeqStack * s = (SeqStack*)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

void push(SeqStack * s, type c){
    if(s->top == MAX){
        printf("栈满");
    }
    s->data[++(s->top)] = c;
}

void pop(SeqStack * s, type * value){
    if( s->top == -1){
        printf("栈空");
    }
    *value = s->data[(s->top)--];
}
