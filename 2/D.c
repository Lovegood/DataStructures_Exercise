#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 101

typedef char type;
typedef struct{
    type data[MAX];
    int top;
}SeqStack;

SeqStack * createSeqStack();
void push(SeqStack*,type);
void pop(SeqStack*,type*);
bool bracketIsMatch(char,char);

int main(){
    SeqStack * s = createSeqStack();

    bool isMatch = true;

    char input[MAX];
    gets(input);

    char ch, value;
    for(int i = 0; i < strlen(input); i++){
        ch = input[i];
        if( (ch == '(')||(ch == '[')||(ch == '{')||(ch == '（') ){  // 样例中还有中文括号
            push(s, ch);
        }else if( (ch == ')')||(ch == ']')||(ch == '}')||(ch == '）') ){
            pop(s, &value);
            isMatch = bracketIsMatch(value, ch);
            if( !isMatch ){
                break;
            }
        }
    }

    if( isMatch ){
        printf("It's macth.");
    }

    return 0;
}

bool bracketIsMatch(char left,char right){
    if( left == '(' && right == ')' ){
        return true;
    }else if( left == '[' && right == ']' ){
        return true;
    }else if( left == '{' && right == '}' ){
        return true;
    }else if(left == '（' && right == '）'){
        return true;
    }else{
        return false;
    }
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
