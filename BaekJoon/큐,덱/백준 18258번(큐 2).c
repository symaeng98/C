#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void push_X();
void pop();
void size();
void empty();
void front();
void back();
typedef struct Node{
    int data;
    struct Node *next;
}ND;
int main(){
    int N,i;
    char _push[10] = "push", _pop[10] = "pop", _size[10] = "size", _empty[10] = "empty", _front[10] = "front", _back[10] = "back";
    ND *front, *rear;
    front = (ND *)malloc(sizeof(ND));
    rear = (ND *)malloc(sizeof(ND));
    front->next = rear;
    rear->next = NULL;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        
    }
    return 0;
}