#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}ND;
void add_front(ND **deque, int X);
void add_rear(ND **deque, int X);
int delete_front(ND **deque);
int delete_rear(ND **deque);
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
            add_front(&front, data);
			if(!num){
				rear = front;
			}
            num++;
        }
        else if(!strcmp(ch,"AR")){
            scanf("%d",&data);
            getchar();
            add_rear(&rear, data);
			if(!num){
				front = rear;
			}
            num++;
        }
        else if(!strcmp(ch,"DF")){
            if(!num){
                printf("underflow\n");
                break;
            }
            delete_front(&front);
            num--;
        }
        else if(!strcmp(ch,"DR")){
            if(!num){
                printf("underflow\n");
                break;
            }
            delete_rear(&rear);
            num--;
        }
        else if(!strcmp(ch,"P")){
            print(front);
        }
        else{
            printf("�Է� �߸���\n");
        }
    }
    
    return 0;
}

void add_front(ND **deque, int X){
    ND *newnode;
    if(*deque == NULL){
        newnode = (ND*)malloc(sizeof(ND));
        newnode->data = X;
        newnode->next = newnode->prev = NULL;
        *deque = newnode;
        return;
    }
    newnode = (ND*)malloc(sizeof(ND));
    newnode->data = X;
    newnode->next = *deque;
	newnode->prev = NULL;
    (*deque)->prev = newnode; 
    *deque = newnode;
}
void add_rear(ND **deque, int X){
    ND *newnode;
    if(*deque == NULL){
        newnode = (ND*)malloc(sizeof(ND));
        newnode->data = X;
        newnode->next = newnode->prev = NULL;
        *deque = newnode;
        return;
    }
    newnode = (ND*)malloc(sizeof(ND));
    newnode->data = X;
    newnode->prev = *deque;
	newnode->next = NULL;
    (*deque)->next = newnode; 
    *deque = newnode;
}
int delete_front(ND **deque){
    ND *p;
    int a;
    if((*deque)->next == NULL){
        p = *deque;
        a = (*deque)->data;
        *deque = NULL;
        free(p);
        return a;
    }
    p = *deque;
    (*deque)->next->prev = NULL;
    *deque = (*deque)->next;
    p->next = NULL;
    free(p);

}
int delete_rear(ND **deque){
    ND *p;
    int a;
    if((*deque)->prev == NULL){
        p = *deque;
        a = (*deque)->data;
        *deque = NULL;
        free(p);
        return a;
    }
    p = *deque;
    (*deque)->prev->next = NULL;
    *deque = (*deque)->prev;
    p->prev = NULL;
    free(p);
}
void print(ND *deque){
    while(deque->next!=NULL){
        printf(" %d",deque->data);
        deque = deque->next;
    }
    printf(" %d\n",deque->data);
    return;
}