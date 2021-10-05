#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int data;
    struct Node *next;
}ND;
typedef struct Part{
    ND *p;
    ND *q;
}P;
void mergeSort(ND **L, int n);
ND *merge(ND **L1, ND **L2);
P partition(ND *L, int k);
void getnode(ND **q, int data);
int main(){
    int n, i, data;
    ND *p, *q, *r,*s;
    //단일연결리스트 생성
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        if(i==0){
            p = (ND*)malloc(sizeof(ND));
            p->data = data;
            p->next = NULL;
            q = p;
        }
        else{
            getnode(&q,data);
        }
    }
    mergeSort(&p,n);
    r = p;
    for(i=0;i<n;i++){
        printf(" %d",p->data);
        p=p->next;
    }

    //free
    while(r!=NULL){
        s = r;
        r=r->next;
        s->next=NULL;
        free(s);
    }
    return 0;
}
void mergeSort(ND **L, int n){
    ND *p, *q, *r;
    int i;
    P part;
    if(n==1){
        return;
    }
    part = partition(*L,n/2);
    p = part.p;
    q = part.q;
    mergeSort(&p,n/2);
    mergeSort(&q,n-(n/2));
    r = merge(&p,&q);
    *L = r;
}
ND *merge(ND **L1, ND **L2){
    ND *l, *f;
    if((*L1)->data<(*L2)->data) l = f = *L1;
    else l = f = *L2;
    while((*L1)!=NULL && (*L2)!=NULL){
        if((*L1)->data < (*L2)->data){
            while(((*L1)!=NULL) && ((*L1)->data < (*L2)->data)){
                l = (*L1);
                (*L1) = (*L1)->next;
            }
            l->next=(*L2);
        }
        else{
            while(((*L2)!=NULL) && ((*L2)->data <= (*L1)->data)){
                l = (*L2);
                (*L2) = (*L2)->next;
            }
            l->next=(*L1);
        }
    }
    return f;
}
P partition(ND *L, int k){
    int i;
    P new;
    new.p = L;
    new.q = L;
    for(i=0;i<k-1;i++){
        L=L->next;
    }
    new.q = L->next;
    L->next = NULL;
    return new;
}
void getnode(ND **q, int data){
    ND *new;
    new = (ND*)malloc(sizeof(ND));
    new->data = data;
    new->next = NULL;
    (*q)->next = new;
    (*q) = (*q)->next;
}