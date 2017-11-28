#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;
typedef struct Node{
    ElemType data;
    struct Node * lchild;
    struct Node * rchild;
}BinTreeNode,*BinTree;

void PreOrder(BinTree);
void InOrder(BinTree);
void PostOrder(BinTree);
BinTree createBinTree();

int main(){
    BinTree bt = createBinTree();

    PreOrder(bt);
    printf("\n");

    InOrder(bt);
    printf("\n");

    PostOrder(bt);
    printf("\n");

    return 0;
}

BinTree createBinTree(){
    BinTree bt;

    ElemType input;
    scanf("%c", &input);

    if(input == '#'){
        bt = NULL;
    }else{
        bt = (BinTree)malloc(sizeof(BinTreeNode));
        bt->data = input;
        bt->lchild = createBinTree();
        bt->rchild = createBinTree();
    }

    return bt;
}

void PreOrder(BinTree root){
    if(root == NULL){
        return;
    }
    printf("%c", root->data);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

void InOrder(BinTree root){
    if(root == NULL){
        return;
    }
    InOrder(root->lchild);
    printf("%c", root->data);
    InOrder(root->rchild);
}

void PostOrder(BinTree root){
    if(root == NULL){
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    printf("%c", root->data);
}

