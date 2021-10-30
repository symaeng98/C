#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    struct Node *next;
    int key;
}ND;
void insert(ND *h, int key, int index);
int search(ND *h, int key, int M);
int delete(ND *h, int key, int M);
void print(ND *h, int M);
int main(){
    int M, key, i;
    char ch;
    ND *hash, *h, *p;
    scanf("%d",&M);
    getchar();
    hash = (ND *)malloc(sizeof(ND)*M);
    h = hash;
    for(i=0;i<M;i++){
        hash[i].next=NULL;
    }
    while(1){
        scanf("%c",&ch);
        if(ch=='i'){
            scanf("%d",&key);
            insert(h,key,key%M);
        }
        else if(ch=='s'){
            scanf("%d",&key);
            printf("%d\n",search(h, key, M));
        }
        else if(ch=='d'){
            scanf("%d",&key);
            printf("%d\n",delete(h,key,M));
        }
        else if(ch=='p'){
            print(h,M);
        }
        else if(ch=='e'){
            break;
        }
        else{
            printf("입력이 잘못됨\n");
        }
        getchar();
    }
    //free
    for(i=0;i<M;i++){
        if(h[i].next==NULL) continue;
        while(h[i].next!=NULL){
            p = h[i].next;
            h[i].next = p->next;
            free(p);
        }
    }
    return 0;
}
void insert(ND *h, int key, int index){
    ND *new, *p;
    new = (ND*)malloc(sizeof(ND));
    new->key = key;
    new->next = h[index].next;
    h[index].next = new;
}
int search(ND *h, int key, int M){
    int i, level=0;
    ND *p;
    for(i=0;i<M;i++){
        level = 0;
        if(h[i].next==NULL) continue;
        p = h[i].next;
        while(p!=NULL){
            level++;
            if(p->key == key) return level;
            p = p->next;
        }
    }
    return 0;
}
int delete(ND *h, int key, int M){
    int i, level=0, flag=0;
    ND *p, *q;
    for(i=0;i<M;i++){
        level = 0;
        flag = 0;
        if(h[i].next==NULL) continue;
        p = &h[i];
        while(p->next!=NULL){
            level++;
            if(p->next->key == key){
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(flag) break;
    }
    if(!flag) return 0;
    q = p->next;
    p->next = q->next;
    free(q);
    return level;
}
void print(ND *h, int M){
    int i;
    ND *p;
    for(i=0;i<M;i++){
        if(h[i].next==NULL) continue;
        p = h[i].next;
        while(p!=NULL){
            printf(" %d",p->key);
            p = p->next;
        }
    }
    printf("\n");
}