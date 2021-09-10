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
    for(i=1;i<N;i++){
        for(j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
            else{
                break;
            }
        }
    }
    for(i=0;i<N;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}