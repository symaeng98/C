#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int N, *arr, i, j, max_index, tmp;
    scanf("%d",&N);
    arr = (int *)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }

    for(i=N-1;i>=1;i--){
        max_index = i;
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[max_index]){
                max_index = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = tmp;
    }
    for(i=0;i<N;i++)
        printf(" %d",arr[i]);
    return 0;
}