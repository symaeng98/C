#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int insert(int *h, int key, int index, int M, int q);
void search(int *h, int key, int M);
void print(int *h, int M);
int main(){
    int n, M, cnt=0, key, i, q;
    int *hash;
    char ch;
    scanf("%d %d %d",&M,&n, &q);
    getchar();
    hash = (int*)malloc(sizeof(int)*M);
    for(i=0;i<M;i++){
        hash[i] = 0;
    }
    while(1){
        scanf("%c",&ch);
        if(ch=='i'){
            if(cnt>n){
                printf("no more input\n");
            }
            else{ 
                scanf("%d",&key);
                printf("%d\n",insert(hash,key,key%M, M, q));
                cnt++;
            }  
        }
        else if(ch=='s'){
            scanf("%d",&key);
            search(hash, key, M);
        }
        else if(ch=='p'){
            print(hash, M);
        }
        else if(ch=='e'){
            print(hash, M);
            break;
        }
        else{
            printf("Wrong Input\n");
        }
        getchar();
    }
    free(hash);
    return 0;
}
int insert(int *h, int key, int index, int M, int q){
    if(h[index]==0){
        h[index] = key;
        return index;
    }
    else{
        printf("C");
        return insert(h,key,(index+(q-(key%q)))%M, M, q);
    }
}
void search(int *h, int key, int M){
    int i;
    for(i=0;i<M;i++){
        if(h[i]==key){
            printf("%d %d\n",i,key);
            return;
        }
    }
    printf("-1\n");
    return;
}
void print(int *h, int M){
    int i;
    for(i=0;i<M;i++) printf(" %d",h[i]);
    printf("\n");
}