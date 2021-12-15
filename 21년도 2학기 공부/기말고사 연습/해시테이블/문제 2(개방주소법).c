#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void search(int *arr, int key, int m);
void insert(int *arr, int key, int index, int m);
int main(){
    int n, m;
    int x, i;
    char ch;
    int *arr;
    scanf("%d %d",&m,&n);
    getchar();
    arr = (int *)malloc(sizeof(int)*m);
    for(i=0;i<m;i++) arr[i]=0;
    while(1){
        scanf("%c",&ch);
        getchar();
        if(ch=='i'){
            scanf("%d",&x);
            getchar();
            insert(arr,x,x%m, m);
        }
        else if(ch=='s'){
            scanf("%d",&x);
            getchar();
            search(arr,x, m);
        }
        else break;
    }
    return 0;
}
void search(int *arr, int key,int m){
    int i;
    for(i=0;i<m;i++){
        if(arr[i]==key){
            printf("%d %d\n",i,key);
            return;
        }
    }
    printf("-1\n");
}
void insert(int *arr, int key, int index, int m){
    if(arr[index]==0){
        arr[index] = key;
        printf("%d\n",index);
        return;
    }
    else{
        printf("C");
        insert(arr,key,(index+1)%m,m);
    }
}