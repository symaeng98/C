#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 7
// S001 English 000712
// S002 Math 000712
// S003 Science 000712
// S001 English 000813
// S003 Science 000813
// S001 English 001211
// S002 Math 001211


//NlogN�� �ð� ���⵵�� ���� ���⵵�� O(N)�̰� �����ϰ�,
//������ ��������(stable)�Ϸ���
//�պ� ������ ���� ����Ʈ ������ �����ϴ�.
typedef struct Node{
    char ID[11];
    char Subject[21];
    char SID[9];
    struct Node *next;
}ND;
typedef struct part{
    ND *L1;
    ND *L2;
}P;
ND *getNode(char ID[], char Subject[], char SID[]);
void mergeSort(ND **list, int n);
ND *merge(ND **L1, ND**L2);
P partition(ND *list, int n);
int main(){
    int n, i;
    char ID[11];
    char Subject[21];
    char SID[9];
    ND *list, *p, *q;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s", &ID);
        scanf("%s", &Subject);
        scanf("%s", &SID);
        if(i==0){
            list = (ND *)malloc(sizeof(ND));
            strcpy(list->ID,ID);
            strcpy(list->Subject,Subject);
            strcpy(list->SID,SID);
            list->next = NULL;
            p = list;
        }
        else{
            p->next = getNode(ID,Subject,SID);
            p=p->next;
        }
    }
    mergeSort(&list, n);
    p = list;
    while(p!=NULL){
        printf("%s %s %s\n",p->ID,p->Subject,p->SID);
        p=p->next;
    }
    p = list;
    while(p!=NULL){
        q = p;
        p = p->next;
        free(q);
    }
    return 0;
}
void mergeSort(ND **list, int n){
    P part;
    if(n<=1) return;
    part = partition(*list, n/2);
    mergeSort(&part.L1,n/2);
    mergeSort(&part.L2,n-n/2);
    *list = merge(&part.L1,&part.L2);
}
ND *merge(ND **L1, ND**L2){ //�� ����� next�θ� �����ϱ� ������ �߰����� ������ �ʿ� ����.
    ND *r;
    ND *p;
    if(strcmp((*L1)->ID,(*L2)->ID)==-1){
        r = (*L1);
    }
    else {
        r = (*L2);
    }
    while((*L1)!=NULL&&(*L2)!=NULL){
        if(strcmp((*L1)->ID,(*L2)->ID)==-1){
            while((*L1)!=NULL&&strcmp((*L1)->ID,(*L2)->ID)==-1){
                p = *L1;
                (*L1)=(*L1)->next;
            }   
            p->next = (*L2);
        }
        else{
            while((*L2)!=NULL&&(strcmp((*L1)->ID,(*L2)->ID)==1||strcmp((*L1)->ID,(*L2)->ID)==0)){
                p = *L2;
                (*L2)=(*L2)->next;
            }
            p->next = (*L1);
        }
    }
    return r;
}
P partition(ND *list, int n){
    //L2�� �ùٸ� ���� ���� ����
    ND *L1, *L2, *f;
    P part;
    int i;
    L1 = list;
    f = list; 
    for(i=0;i<n-1;i++){
        f=f->next;
    }
    L2 = f->next;
    f->next = NULL;
    part.L2 = L2;
    return part;
}
ND *getNode(char ID[], char Subject[], char SID[]){
    ND *newnode;
    newnode = (ND*)malloc(sizeof(ND));
    strcpy(newnode->ID,ID);
    strcpy(newnode->SID,SID);
    strcpy(newnode->Subject,Subject);
    newnode->next = NULL;
    return newnode;
}