#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}ND;
void add_front(ND *deque, int X);
void add_rear(ND *deque, int X);
void delete_front(ND *deque);
void delete_rear(ND *deque);
void print(ND *deque);

int main(){
    int i, N, data;
    char ch[4];
    ND *front, *rear;
    front = rear = NULL;
    
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        scanf("%s",ch);
        if(!strcmp(ch,"AF")){
            scanf("%d",&data);
            getchar();
            add_front(front, data);
        }
        else if(!strcmp(ch,"AR")){
            scanf("%d",&data);
            getchar();
            add_rear(rear, data);
        }
        else if(!strcmp(ch,"DF")){
            delete_front(front);
        }
        else if(!strcmp(ch,"DR")){
            delete_rear(rear);
        }
        else if(!strcmp(ch,"P")){
            print(front);
        }
        else{
            printf("입력 잘못됨\n");
        }
    }
    
    return 0;
}

void add_front(ND *deque, int X){
    ND *newnode;
    newnode = (ND*)malloc(sizeof(ND));
    newnode->data = X;
    newnode->prev = NULL;
    newnode->next = deque;
    deque->prev = newnode;
    deque = newnode;
    return;
}
void add_rear(ND *deque, int X){

}
void delete_front(ND *deque){

}
void delete_rear(ND *deque){

}
void print(ND *deque){
    while(deque->next!=NULL){
        printf(" %d",deque->data);
        deque = deque->next;
    }
    printf(" %d",deque->data);
    return;
}
