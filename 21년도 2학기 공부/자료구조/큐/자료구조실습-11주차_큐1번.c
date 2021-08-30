#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int i,front=0, rear=0, *q,N,K,j;
    char ch;
    int num;
    scanf("%d",&N);
    scanf("%d",&K);
    q = (int*)malloc(sizeof(int)*(N+1));
    for(i=0;i<N;i++){
        q[i]=0;
    }
    for(i=0;i<K;i++){
        getchar();
        scanf("%c",&ch);
        if(ch=='I'){
            scanf("%d",&num);
            if(front == (rear+1)%N){
                printf("overflow");
                for(j=0;j<N;j++){
                printf(" %d",q[j]);
                }
                printf("\n");
                break;
            }
            else{
                rear++;
                rear%=N;
                q[rear] = num;
            }
            
        }
        else if(ch=='D'){
            if(front == rear){
                printf("underflow\n");
                break;
            }
            else{
                front++;
                front%=N;
                q[front] = 0;
            }
        }
        else if(ch=='P'){
            for(j=0;j<N;j++){
                printf(" %d",q[j]);
            }
            printf("\n");
        }
        else{
            printf("ÀÔ·Â Àß¸øµÊ\n");
            break;
        }
    }
    return 0;
}