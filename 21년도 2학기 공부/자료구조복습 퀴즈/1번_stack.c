#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char data[11];
    struct Node *next;
    struct Node *prev;
}ND;

void add(ND **top, char data[]);
void pop(ND **top, char *arr);
int main(){
    ND *top = NULL;
    char arr[11];
    char ch[11];
    while(1){
        scanf("%s",ch);
        getchar();
        if(!strcmp(ch,"*")){
            break;
        }
        add(&top, ch);
    }

    while(1){
        if(top==NULL){
            break;
        }
        pop(&top,arr);
        printf("%s\n",arr);
    }
    return 0;
}
void add(ND **top, char data[]){
    ND *new;
    if((*top)==NULL){
        new = (ND*)malloc(sizeof(ND));
        strcpy(new->data, data);
        new->next = NULL;
        new->prev = NULL;
        *top = new;
        return;
    }
    new = (ND*)malloc(sizeof(ND));
    strcpy(new->data, data);
    new->next = NULL;
    new->prev = *top;
    (*top)->next = new;
    *top = new;
}
void pop(ND **top, char *arr){
    ND *q;
    if((*top)->prev==NULL){
        q = *top;
        *top = NULL;
        strcpy(arr,q->data);
        free(q);
        return;
    }
    q = *top;
    (*top) = (*top)->prev;
    (*top)->next = NULL;
    q->prev = NULL;
    strcpy(arr,q->data);
    free(q);
    return;
}
    