#include <stdio.h>
#include <string.h>

int main(){
    int K, N, i;
    int money[100001], sum = 0, top = -1;
    scanf("%d",&K);
    for(i=0;i<K;i++){
        scanf("%d",&N);
        if(N==0){
            if(top!=-1){
                top-=1;
            }
        }
        else{
            top+=1;
            money[top] = N;
        }
    }
    for(i=0;i<=top;i++){
        sum+=money[i];
    }
    printf("%d",sum);
    return 0;
}