#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void isMinHeap(int *arr, int index, int n, int isRight[]);
int main(){
    int n, i , *arr,isRight[1];
    isRight[0] = 1;
    scanf("%d",&n);
    arr = (int *)malloc(sizeof(int)*(n+1));
    for(i=1;i<=n;i++) scanf("%d",&arr[i]);
    isMinHeap(arr, 1, n, isRight);
    if(isRight[0]) printf("Yes\n");
    else printf("No\n");
    printf("%d",arr[n/2]);
    free(arr);
    return 0;
}
void isMinHeap(int *arr, int index, int n, int isRight[]){
    if(index*2>n) return;
    else if(index*2==n){
        if(arr[index]>arr[index*2]){
            isRight[0] = 0;
            return;
        }
    }
    else{
        if(arr[index]>arr[index*2]||arr[index]>arr[index*2+1]){
            isRight[0] = 0;
            return;
        }
    }
    isMinHeap(arr, index*2, n, isRight);
    isMinHeap(arr, index*2+1, n, isRight);
}