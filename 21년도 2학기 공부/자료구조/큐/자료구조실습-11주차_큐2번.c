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
int delete_front(ND *deque);
int delete_rear(ND *deque);
void print(ND *deque);

int main(){
    int i, N, data, num=0;
    char ch[4];
    ND *front, *rear, *new, *p;
    front = rear = NULL;
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        scanf("%s",ch);
        if(!strcmp(ch,"AF")){
            scanf("%d",&data);
            getchar();
            add_front(front, data);
            printf("woi");
            printf("%d",front->data);
            front = front->prev;
            num++;
        }
        else if(!strcmp(ch,"AR")){
            scanf("%d",&data);
            getchar();
            add_rear(rear, data);
            rear = rear->next;
            num++;
        }
        else if(!strcmp(ch,"DF")){
            if(!num){
                break;
            }
            delete_front(front);
            num--;
        }
        else if(!strcmp(ch,"DR")){
            if(!num){
                break;
            }
            delete_rear(rear);
            num--;
        }
        else if(!strcmp(ch,"P")){
            print(front);
            printf("%d\n",front->data);
        }
        else{
            printf("ÀÔ·Â Àß¸øµÊ\n");
        }
    }
    
    return 0;
}

void add_front(ND *deque, int X){
    ND *newnode;
    if(deque == NULL){
        newnode = (ND*)malloc(sizeof(ND));
        newnode->data = X;
        newnode->next = newnode->prev = NULL;
        deque = newnode;
        return;
    }
    newnode = (ND*)malloc(sizeof(ND));
    newnode->data = X;
    newnode->next = deque;
    deque->prev = newnode;
}
void add_rear(ND *deque, int X){
    ND *newnode;
    if(deque == NULL){
        newnode = (ND*)malloc(sizeof(ND));
        newnode->data = X;
        newnode->next = newnode->prev = NULL;
        deque = newnode;
        return;
    }
    newnode = (ND*)malloc(sizeof(ND));
    newnode->data = X;
    newnode->prev = deque;
    deque->next = newnode;
}
int delete_front(ND *deque){
    deque->next->prev = NULL;
    deque->next = NULL;
}
int delete_rear(ND *deque){

}
void print(ND *deque){
    while(deque->next!=NULL){
        printf(" %d",deque->data);
        deque = deque->next;
    }
    printf(" %d\n",deque->data);
    return;
}
