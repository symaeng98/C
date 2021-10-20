#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
    struct Node *next;
    int data;
}ND;
typedef struct part{
    ND *L1;
    ND *L2;
}P;
ND *getNode(int data);
void mergeSort(ND **list, int n);
ND *merge(ND **L1, ND **L2);
P partition(ND *list, int k);
int main(){
    ND *list, *f;
    int n, i, data;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &data);
        if(i==0){
            list = (ND *)malloc(sizeof(ND));
            list->data = data;
            list->next = NULL;
            f = list;
        }
        else{
            f->next = getNode(data);
            f=f->next;
        }
    }
    mergeSort(&list, n);
    for(i=0;i<n;i++){
        printf(" %d",list->data);
        list=list->next;
    }
    while(list!=NULL){
        f = list;
        list = list->next;
        f->next=NULL;
        free(f);
    }
    return 0;
}
ND *getNode(int data){
    ND *newnode;
    newnode = (ND*)malloc(sizeof(ND));
    newnode->data = data;
    newnode->next = NULL;
}
void mergeSort(ND **list, int n){
    P part;
    ND *p;
    if(n==1) return;
    part = partition(*list, n/2);
    mergeSort(&part.L1, n/2);
    mergeSort(&part.L2, n-n/2);
    *list = merge(&part.L1, &part.L2);
}
ND *merge(ND **L1, ND **L2){
    ND *r, *p;
    if((*L1)->data<(*L2)->data) r = *L1;
    else r = *L2;
    while((*L1)!=NULL&&(*L2)!=NULL){
        if((*L1)->data<(*L2)->data){
            while((*L1)!=NULL&&(*L1)->data<(*L2)->data){ //L1이 작은 동안
                p = *L1;
                *L1=(*L1)->next;
            }
            p->next = *L2;
        }
        else{
            while((*L2)!=NULL&&(*L1)->data>=(*L2)->data){ //L2가 작은 동안
                p = *L2;
                *L2=(*L2)->next;
            }
            p->next = *L1;
        }
    }
    return r;
}
P partition(ND *list, int k){
    ND *f, *p;
    P part;
    int i;
    f = list;
    part.L1 = list;
    for(i=0;i<k-1;i++) f=f->next;
    p = f->next;
    f->next = NULL;
    part.L2 = p;
    return part;
}