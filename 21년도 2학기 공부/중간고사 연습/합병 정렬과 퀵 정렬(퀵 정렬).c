#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Index{
    int a;
    int b;
}I;
void swapElements(int *arr, int index1, int index2);
void inPlaceQuickSort(int *arr, int l, int r);
I inPlacePartition(int *arr, int l, int r);
int main(){
    int n, *arr, i;
    scanf("%d",&n);
    arr = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    inPlaceQuickSort(arr,0,n-1);
    for(i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}
void inPlaceQuickSort(int *arr, int l, int r){
    I index;
    if(l>=r) return;
    index = inPlacePartition(arr,l,r);
    inPlaceQuickSort(arr,l,index.a-1);
    inPlaceQuickSort(arr,index.b+1,r);
}
I inPlacePartition(int *arr, int l, int r){
    I index;
    int pivot, i, j;
    pivot = arr[l];
    swapElements(arr, l, r);
    i = l;
    j = r-1;
    while(i<=j){
        while((i<=j)&&arr[i]<pivot){
            i++;
        }
        while((i<=j)&&arr[j]>=pivot){
            j--;
        }
        if(i<j){
            swapElements(arr,i,j);
        }
    }
    swapElements(arr,i,r);
    index.a = i;
    j = r;
    while(i<j){
        while((i<=j)&&arr[i]==pivot){
            i++;
        }
        while((i<=j)&&arr[j]!=pivot){
            j--;
        }
        if(i<j)
            swapElements(arr,i,j);
    }
    index.b = j;
    return index;
}
void swapElements(int *arr, int index1, int index2){
    int tmp;
    tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}