#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 101

typedef struct{
    int data[MAXSIZE];
    int front;
    int rear;
}Queue;

Queue * createQueue();
bool isEmpty(Queue*);
bool isFull(Queue*);
void enterQueue(Queue*,int);
void outQueue(Queue*,int*);
int getQueueHeader(Queue*);

int main(){
    int N;
    scanf("%d", &N);

    Queue * q = createQueue();

    // print Ñî»ÔÈý½ÇÐÎ
    int print;

    enterQueue(q, 1);
    for(int line = 1; line <= N; line++){
        enterQueue(q, 1);
        for(int cnt = 1; cnt < line; cnt++){
            outQueue(q, &print);
            printf("%d ", print);

            enterQueue(q, print+getQueueHeader(q));
        }
        outQueue(q, &print);
        printf("%d \n", print);
        enterQueue(q, 1);
    }


    return 0;
}

Queue * createQueue(){
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
}

void enterQueue(Queue * q, int value){
    if( isFull(q) ){
        printf("¶ÓÂú\n");
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAXSIZE;
}

void outQueue(Queue * q, int * value){
    if( isEmpty(q) ){
        printf("¶Ó¿Õ\n");
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
}

int getQueueHeader(Queue * q){
    return q->data[q->front];
}

bool isEmpty(Queue * q){
    if( q->front == q->rear){
        return true;
    }else{
        return false;
    }
}

bool isFull(Queue * q){
    if( (q->rear+1) % MAXSIZE == q->front ){
        return true;
    }else{
        return false;
    }
}
