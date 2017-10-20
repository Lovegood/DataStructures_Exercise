#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ERROR 1
#define SUCCESS 0

typedef struct node{
    int data;
    struct node * next;
}LinkListNode, LinkList;

LinkList * create_LinkList(int);
void print_LinkList(LinkList*,bool);

void print_LinkList_r(LinkList * l){
    while(l->next != NULL){
        printf("data=%d\t",l->data);
        printf("next=%p\t",l->next);
        printf("\n");
        l = l->next;
    }
    printf("data=%d\t",l->data);
    printf("next=%p\t",l->next);
    printf("\n");
}

int main(){
    // set la, lb
    LinkList * la = create_LinkList(10);
    LinkList * lb = create_LinkList(6);

    // i len j
    int i, len, j;
    scanf("%d",&i);
    scanf("%d",&len);
    scanf("%d",&j);

    // process
    // find insert and delete position
    LinkList *start = NULL, *end = NULL;

    start = la;
    for( int index = 1; index < i;index++){
        start = start->next;
    }

    end = start;
    for( int cnt = 1; cnt <= len; cnt++){
        end = end->next;
    }

    // find the insert position in lb
    LinkList * tmp = lb;
    for( int index = 0; index < j;index++){
        tmp = tmp->next;
    }

    LinkList * start_next = start->next;

    start->next = end->next;

    end->next = tmp->next;
    tmp->next = start_next;

    //output
    print_LinkList(la, true);
    print_LinkList(lb, false);

    return 0;
}

LinkList * create_LinkList(int cnt){
    LinkList * header = (LinkList*)malloc(sizeof(LinkListNode));// header
    header->next = NULL;
    LinkListNode * rear = header;

    for(int i = 0; i < cnt; i++){
        LinkListNode * tmp = (LinkListNode*)malloc(sizeof(LinkListNode));

        int digit;
        scanf("%d", &digit);

        tmp->data = digit;
        tmp->next = NULL;

        rear->next = tmp;

        rear = rear->next;
	}

    return header;
}

void print_LinkList(LinkList * l, bool is_al){
    // 第一次只输出一个数字
    // 之后输出格式 ：空格+数字
    l = l->next;
    int digit = l->data;
    if(is_al){
        printf("la:%d", digit);
    }else{
        printf("lb:%d", digit);
    }
    while(l->next != NULL){
        l = l->next;
        digit = l->data;
        printf(" %d", digit);
    }
    printf("\n");
}
