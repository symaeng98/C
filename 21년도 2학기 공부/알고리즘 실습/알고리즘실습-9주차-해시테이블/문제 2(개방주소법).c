#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int insert(int *h, int key, int index, int M);
void search(int *h, int key, int M);
int main(){
    int n, M, cnt=0, key, i;
    int *hash;
    char ch;
    scanf("%d %d",&M,&n);
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
                printf("%d\n",insert(hash,key,key%M, M));
                cnt++;
            }  
        }
        else if(ch=='s'){
            scanf("%d",&key);
            search(hash, key, M);
        }
        else if(ch=='e'){
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
int insert(int *h, int key, int index, int M){
    if(h[index]==0){
        h[index] = key;
        return index;
    }
    else{
        printf("C");
        return insert(h,key,(index+1)%M, M);
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