#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int N, *arr, i, j, save;
    scanf("%d",&N);
    arr = (int *)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<N;i++){
        save = arr[i];
        j = i-1;
        while((j>=0)&&(arr[j]>save)){
            arr[j+1] = arr[j]; //값 붙여넣기
            j--;
        }
        arr[j+1] = save; //j는 비교 대상보다 작은 수의 위치이므로 j+1에 삽입
    }
    for(i=0;i<N;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}