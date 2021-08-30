#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}ND;
typedef struct Tree{
    ND *F;
}T;
ND *newnode(int data);
int main(){
    T *tree;
    int N;
    scanf("%d",&N);
    tree = (T*)malloc((sizeof(T))*8);
    tree[7].F = newnode(80);
	tree[6].F = newnode(130);
	tree[5].F = newnode(120);
	tree[5].F->right = tree[7].F;
	tree[5].F->left = tree[6].F;
	tree[2].F = newnode(50);
	tree[2].F->right = tree[5].F;
	tree[0].F = newnode(20);
	tree[0].F->right = tree[2].F;
	tree[3].F = newnode(70);
	tree[4].F = newnode(90);
	tree[1].F = newnode(30);
	tree[1].F->right = tree[4].F;
	tree[1].F->left = tree[3].F;
    tree[0].F->left = tree[1].F;
    if(N>=1&&N<=8){
        printf("%d ",tree[N-1].F->data);
        if(tree[N-1].F->left!=NULL) printf("%d ",tree[N-1].F->left->data);
        if(tree[N-1].F->right!=NULL) printf("%d ",tree[N-1].F->right->data);
    }
    else{
        printf("-1");
    }
    
    return 0;
}
ND *newnode(int data){
    ND *new;
    new = (ND*)malloc(sizeof(ND));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}