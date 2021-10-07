#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mergeSort(int *L, int l, int r);
void merge(int *L, int l, int m, int r);
int main(){
    int n, *arr, i;
    scanf("%d",&n);
    arr = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}
void mergeSort(int *L, int l, int r){
    int m;
    if(l>=r) return;
    m = (l+r)/2;
    mergeSort(L, l, m);
    mergeSort(L, m+1, r);
    merge(L,l,m,r);
}
void merge(int *L, int l, int m, int r){
    int i, j, k;
    int *tmp;
    tmp = (int*)malloc(sizeof(int)*(r-l+1));
    if(l>=r) return;
    i = l;
    j = m+1;
    k = 0;
    while(i<=m&&j<=r){
        if(L[i]<L[j]){
            tmp[k] = L[i];
            k++; i++;
        }
        else{
            tmp[k] = L[j];
            k++; j++;
        }
    }

    while(i<=m){
        tmp[k] = L[i];
        k++; i++;
    }
    while(j<=r){
        tmp[k] = L[j];
        k++; j++;
    }
    i = l;
    for(k=0;k<r-l+1;k++){
        L[i] = tmp[k];
        i++;
    }
}