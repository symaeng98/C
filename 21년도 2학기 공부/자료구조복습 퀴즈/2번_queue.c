#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char data[11];
    struct Node *next;
}ND;

void enqueue(ND **rear, char data[]);
void dequeue(ND **front, char *arr);
void *reverse(char *str);
int main(){
    ND *front=NULL, queue,*rear=NULL;
    char ch[11];
    char arr[11];
    while(1){
        scanf("%s",ch);
        getchar();
        if(!strcmp(ch,"*")){
            break;
        }
        enqueue(&rear, ch);
        if(front==NULL){
            front = rear;
        }
    }
    while(front!=NULL){
        dequeue(&front,arr);
        printf("%s\n",arr);
    }
    return 0;
}
void enqueue(ND **rear, char data[]){
    ND *new;
    if((*rear)==NULL){
        new = (ND*)malloc(sizeof(ND));
        strcpy(new->data, data);
        new->next  = NULL;
        *rear = new;
        return;
    }
    new = (ND*)malloc(sizeof(ND));
    strcpy(new->data, data);
    new->next  = NULL;
    (*rear)->next = new;
    *rear = new;
}
void dequeue(ND **front, char *arr){
    ND *q;
    if((*front)->next==NULL){
        q = *front;
        *front = NULL;
        reverse(q->data);
        strcpy(arr,q->data);
        free(q);
        return;
    }
    q = *front;
    (*front) = (*front)->next;
    q->next = NULL;
    reverse(q->data);
    strcpy(arr,q->data);
    free(q);
}
void *reverse(char *str){
    char *p = str, *q = str+strlen(str)-1;
    for (p=str, q=str+strlen(str)-1; p<q;p++, q--){
        char tmp;
        tmp = *p;
        *p = *q;
        *q = tmp; 
    }
}