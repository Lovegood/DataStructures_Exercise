#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}LinkListNode, LinkList;

LinkList * create_LinkList(int);
int search_LinkList(LinkList*,int);

void print_LinkList(LinkList * l){
    l = l->next;
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
    LinkList * list = create_LinkList(9);

    int k;
    scanf("%d", &k);

    //printf("print link list:");
    //print_LinkList(list);

    search_LinkList(list,k);

    return 0;
}

int search_LinkList(LinkList * list, int k){
    LinkListNode *front = list->next, *behind = list->next;

    // 先移动behind ，当到k个的时候，开始移动 front
    int cnt = 1;
    while( cnt < k ){
        if( behind->next == NULL ){
            return 0;
        }
        behind = behind->next;
        cnt++;
    }

    while( behind->next != NULL ){
        behind = behind->next;
        front = front->next;
    }

    printf("%d", front->data);

    return 1;
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

    //    str_tmp = strtok(NULL, delim);
	//}
	}

    return header;
}
