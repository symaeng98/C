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
    m = (l+r)/2;
    if(l>r) return r; //r이 m-1이 들어와서 종료되면 r을 return
    if(k == arr[m]) return m;
    else if(k < arr[m]) return binarySearch(arr,l,m-1,k);
    else return binarySearch(arr,m+1,r,k);
}