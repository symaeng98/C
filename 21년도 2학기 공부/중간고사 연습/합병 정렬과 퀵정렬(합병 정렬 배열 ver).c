#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void mergeSort(int *arr,int l, int r);
void merge(int *arr, int l, int mid, int r);
int main(){
    int n,i,*arr;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    free(arr);
    return 0;
}
void mergeSort(int *arr,int l, int r){
    int mid;
    if(l==r) return;
    mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
void merge(int *arr, int l, int mid, int r){
    int i, j, k;
    int *tmpArr;
    k=0;
    tmpArr = (int*)malloc(sizeof(int)*(r-l+1));
    i = l;
    j = mid+1;
    while(i<=mid&&j<=r){
        if(arr[i]<arr[j]){
            tmpArr[k++] = arr[i++];
        }
        else{
            tmpArr[k++] = arr[j++];
        }
    }
    while(i<=mid){
        tmpArr[k++] = arr[i++];
    }
    while(j<=r){
        tmpArr[k++] = arr[j++];
    }
    for(i=0;i<k;i++){
        arr[l+i] = tmpArr[i];
    }
    free(tmpArr);
}