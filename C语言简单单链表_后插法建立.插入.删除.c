#include <stdio.h>
#include <stdlib.h>
#define ERROR 1
#define SUCCESS 0

typedef struct node{
    int data;
    struct node * next;
}LinkListNode, LinkList;

LinkList * create_LinkList(int[], int);
void print_LinkList_r(LinkList*);
int InsertElement_LinkList(LinkList*,int,int);
int deleteElement_LinkList(LinkList*,int);

int main(){
    int a[] = {0, 1, 2, 3, 4, 5};
    LinkList * L = create_LinkList(a, 6);
    printf("Create Link List Result:\n");
    print_LinkList_r(L);

    int ele, pos;
    printf("Please enter the element that you want to insert:\n");
    scanf("%d", &ele);
    printf("Please enter the position that you want to insert:\n");
    scanf("%d", &pos);
    if( InsertElement_LinkList(L, ele, pos) == SUCCESS ){
        printf("Insert Link List Result:\n");
        print_LinkList_r(L);
    }else{
        printf("Insert fail.\n");
    }

    int delPos;
    printf("Please enter the element's position that you want to delete:\n");
    scanf("%d", &delPos);
    if( deleteElement_LinkList(L, delPos) == SUCCESS ){
        printf("Delete Link List Element Result:\n");
        print_LinkList_r(L);
    }else{
        printf("Delete fail.\n");
    }

    return 0;
}

int deleteElement_LinkList(LinkList * L, int pos){
    int length = 0;
    LinkList * cpy = L;
    while(cpy->next != NULL){
        length++;
        cpy = cpy->next;
    }

    if( (pos < 1) || (pos > length) ){
        printf("Insert position error.\n");
        return ERROR;
    }

    LinkListNode * forwardDel = L;
    LinkListNode * del = L->next;
    for(int i = 1; i < pos; i++){
        forwardDel = forwardDel->next;
        del = del->next;
    }
    forwardDel->next = del->next;
    free(del);
    return SUCCESS;
}

LinkList * create_LinkList(int a[], int cnt){//cnt count 元素个数
    LinkList * header = (LinkList*)malloc(sizeof(LinkListNode));

    header->next = NULL;
    LinkListNode * rear = header;

    for(int i = 0; i < cnt; i++){
        LinkListNode * tmp = (LinkListNode*)malloc(sizeof(LinkListNode));

        tmp->data = a[i];
        tmp->next = NULL;

        rear->next = tmp;

        rear = rear->next;
	}

    return header;
}

int InsertElement_LinkList(LinkList * L, int ele, int pos){
    int length = 0;
    LinkList * cpy = L;
    while(cpy->next != NULL){
        length++;
        cpy = cpy->next;
    }

    if( (pos < 1) || (pos > length) ){
        printf("Insert position error.\n");
        return ERROR;
    }

    LinkListNode * tmp = (LinkListNode*)malloc(sizeof(LinkListNode));
    if(tmp == NULL){
        printf("NULL pointer error.\n");
        return ERROR;
    }
    tmp->data = ele;

    LinkList * front = L;
    for(int i = 2; i <= pos; i++){
        front = front->next;
    }
    tmp->next = front->next;
    front->next = tmp;

    return SUCCESS;
}

void print_LinkList_r(LinkList * l){
    while(l->next != NULL){
        l = l->next;
        printf("data=%d\t\t",l->data);
        printf("next=%p\t\n",l->next);
    }
}
