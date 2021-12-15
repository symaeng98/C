#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct HashTable{
    struct HashTable *next;
    int data;
}HT;
void *insert(HT *ht, int data, int index);
int search(HT *ht, int data, int m);
void delete(HT *ht, int data, int m);
void print(HT *ht, int m);
int main(){
    HT *ht ,*p;
    int i;
    int m, x;
    int mod;
    char ch;
    scanf("%d",&m);
    getchar();
    ht = (HT*)malloc(sizeof(HT)*m);
    for(i=0;i<m;i++){
        ht[i].next=NULL;
    }
    while(1){
        scanf("%c",&ch);
        getchar();
        if(ch=='i'){
            scanf("%d",&x);
            getchar();
            mod = x % m;
            insert(ht,x,mod);
        }
        else if(ch=='s'){
            scanf("%d",&x);
            getchar();
            search(ht,x,m);
        }
        else if(ch=='d'){
            scanf("%d",&x);
            getchar();
            delete(ht,x,m);
        }
        else if(ch=='p'){
            print(ht, m);
        }
        else{
            break;
        }
    }
    return 0;
}
void *insert(HT *ht, int data, int index){
    HT *new;
    new = (HT*)malloc(sizeof(HT));
    new->next=NULL;
    new->data = data;
    new->next = ht[index].next;
    ht[index].next = new;
}
int search(HT *ht, int data, int m){
    int mod;
    int cnt=1;
    HT *p;
    mod = data%m;
    p = ht[mod].next;
    while(p!=NULL){
        if(p->data==data){
            printf("%d\n",cnt);
            return cnt;
        }
        p=p->next;
        cnt++;
    }
    printf("0\n");
    return 0;
}
void delete(HT *ht, int data, int m){
    HT *p,*q;
    int mod;
    int cnt,i;
    mod = data%m;
    cnt = search(ht,data,m);
    p = ht[mod].next;
    if(cnt==0) return;
    else if(cnt==1){
        q = ht[mod].next;
        ht[mod].next = p->next;
        free(q);
        return;
    }
    for(i=0;i<cnt-1;i++){
        q = p;
        p=p->next;
    }
    q->next = p->next;
    free(p);
}
void print(HT *ht, int m){
    int i=0;
    HT *p;
    for(i=0;i<m;i++){
        p = ht[i].next;
        while(p!=NULL){
            printf(" %d",p->data);
            p=p->next;
        }
    }
    printf("\n");
}