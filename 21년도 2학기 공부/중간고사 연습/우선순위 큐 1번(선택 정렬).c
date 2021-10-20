#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, i, j;
    int *arr, tmp, maxArr;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    for(i=n-1;i>0;i--){
        maxArr = i;
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[maxArr]){
                maxArr = j;
            }
        }
        if(i==maxArr) continue;
        else{
            tmp = arr[i];
            arr[i] = arr[maxArr];
            arr[maxArr] = tmp;
        }
    }
    for(i=0;i<n;i++) printf(" %d",arr[i]);
    return 0;
}