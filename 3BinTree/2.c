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
BinTree createBinTree();

int zero = 0, one = 0; two = 0;
char leaf[100] = "";
int leafcnt = 0;

int main(){
    BinTree bt = createBinTree();

    PreOrder(bt);

    printf("%d %d %d\n", zero, one, two);
    for(int i = 0; i < leafcnt; i++){
        printf("%c",leaf[i]);
    }

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

    if(root->lchild == NULL && root->rchild == NULL){
        zero++;
        leaf[leafcnt++] = root->data;
    } else if(root->lchild != NULL && root->rchild != NULL){
        two++;
    } else{
        one++;
    }

    PreOrder(root->lchild);
    PreOrder(root->rchild);
}


