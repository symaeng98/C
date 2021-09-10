#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    char elem;
    struct Node *left_child;
    struct Node *right_child;
}ND;
typedef struct Tree{ 
    ND *Root;
}T;
ND *get_node(char elem);
ND *connect_node(ND *p, char elem);
void print(ND *p);
int main(){
    int N, i;
    char m, left, right;
    ND *tmp;
    T tree;

    tree.Root = (ND*)malloc(sizeof(ND));
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        scanf("%c %c %c",&m,&left,&right);
        getchar();
        if(i==0){
            tree.Root->left_child = get_node(m);
            tree.Root->left_child->left_child = get_node(left);
            tree.Root->left_child->right_child = get_node(right);
        }
        else{
            tmp = connect_node(tree.Root->left_child, m);
            tmp->left_child = get_node(left);
            tmp->right_child = get_node(right);
        }

    }
    print(tree.Root->left_child);
    return 0;
}

ND *get_node(char elem){
    ND *new;
    if(elem=='0') return NULL;
    new = (ND*)malloc(sizeof(ND));
    new->elem = elem;
    new->left_child = new->right_child = NULL;
    return new;
}
ND *connect_node(ND *p, char elem){
    ND *tmp;
    if(p==NULL) return NULL;
    if(p->elem == elem){
        return p;
    }
    tmp = connect_node(p->left_child, elem);
    if(tmp!=NULL) return tmp;
    tmp = connect_node(p->right_child, elem);
    if(tmp!=NULL) return tmp;
}
void print(ND *p){
    if(p==NULL){
        return;
    }
    printf("%c",p->elem);
    print(p->left_child);
    print(p->right_child);
}