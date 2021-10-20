#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int n, i ,j;
    int *arr, save;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++){
        save = arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]<save) break;
            arr[j+1] = arr[j];
        }
        arr[j+1] = save;
    }
    for(i=0;i<n;i++) printf(" %d",arr[i]);
    return 0;
}