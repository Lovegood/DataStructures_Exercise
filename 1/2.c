#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 101
#define ERROR 1
#define SUCCESS 0

typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SeqList;


void init_SeqList(SeqList*);
int Insert_SeqList(SeqList*, int, ElemType);
int Del_SeqList(SeqList*, ElemType);
int FindByValue_SeqList(SeqList*, ElemType);

int main(){
	SeqList L;

	init_SeqList(&L);

	//input
	char t[MAXSIZE];
	char * str_tmp = NULL;
	char * delim = " ";
	int index = 1;
	gets(t);
	str_tmp = strtok(&t[0], delim);
	do{
        int digit = atoi(str_tmp);
        Insert_SeqList(&L, index++, digit);
	}while( (str_tmp = strtok(NULL, delim)) != NULL );

	int del;
	scanf("%d",&del);

	Del_SeqList(&L, del);

	for(int i = 1; i <= L.length; i++){
        printf("%d ", L.data[i]);
	}

	return 0;
}



void init_SeqList(SeqList * L){
	L->length = 0;
}

int Insert_SeqList(SeqList * L, int index, ElemType elem){
	if( L->length == MAXSIZE-1 ){
		printf("表满，插入失败\n");
		return ERROR;
	}else if( index < 1 || index > L->length+1 ){
		printf("插入位置不合理\n");
		return ERROR;
	}else{
        for(int i = L->length; i >= index; i--){
            L->data[i+1] = L->data[i];
        }
        L->data[index] = elem;
        L->length++;
        return SUCCESS;
	}
}

/*
 * Delete by value.
 *
 */
int Del_SeqList(SeqList * L, ElemType elem){//elem 欲删除元素
    if(L->length == 0){
        printf("表空，删除失败\n");
        return ERROR;
    }else{
        int index = FindByValue_SeqList(L,elem);
        while( (index != -1)){
            for(int i = index; i < L->length; i++){
                L->data[i] = L->data[i+1];
            }
            L->length--;
            index = FindByValue_SeqList(L,elem);
        }
        return SUCCESS;
    }
}

int FindByValue_SeqList(SeqList * L, ElemType elem){
    int index = -1;
    for(int i = 1; i <= L->length; i++){
        if( L->data[i] == elem ){
            index = i;
            return index;
        }
    }
    return index;
}
