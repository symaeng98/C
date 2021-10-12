#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int *arr, int l, int r, int k);

int main(){
    int n, k, *arr,i;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    scanf("%d",&k);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf(" %d",binarySearch(arr,0,n-1,k));
    free(arr);
    return 0;
}

int binarySearch(int *arr, int l, int r, int k){
    int m;
    while(l<=r){
        m = (l+r)/2;
        if(arr[m]==k) return m;
        else if(arr[m]<k){
            l = m+1;
        }
        else{
            r = m-1;
        }   
    }
    return l;
}