#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node * next;
}LinkListNode, LinkList;

LinkList * create_LinkList(int);
void print_LinkList(LinkList*);
LinkList * merge_LinkList(LinkList*,LinkList*);

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
    LinkList * a = create_LinkList(6);
    LinkList * b = create_LinkList(9);

    LinkList * c = merge_LinkList(a->next, b->next);
    //printf("print_linklist_r(c):\n");
    //print_LinkList_r(c);

    print_LinkList(c);

    return 0;
}

LinkList * create_LinkList(int cnt){
    LinkList * header = (LinkList*)malloc(sizeof(LinkListNode));// header
    header->next = NULL;
    LinkListNode * rear = header;

    //char t[101];
	//char * str_tmp = NULL;
	//char * delim = " ";
	//gets(t);
	//str_tmp = strtok(t, delim);
	//while( str_tmp != NULL ){
    //    int digit = atoi(str_tmp);

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

void print_LinkList(LinkList * l){
    int digit = l->data;
    printf("%d", digit);
    while(l->next != NULL){
        l = l->next;
        printf(" %d", l->data);
    }
    printf("\n");
}

LinkList * merge_LinkList(LinkList * a, LinkList * b){
    if( a == NULL ){
        return b;
    }
    if( b == NULL ){
        return a;
    }

    LinkList * result = NULL;

    if( a->data < b->data ){
        result = a;
        result->next = merge_LinkList(a->next, b);
    }else{
        result = b;
        result->next = merge_LinkList(a, b->next);
    }

    return result;
}
