#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void inPlaceQuickSort(int *arr, int l, int r);
typedef struct Index{ //a,b를 모두 반환하기 위한 구조체 선언
    int a;
    int b;
}I;
int findPivot(int *arr, int l, int r);
I inPlacePartition(int *arr, int l, int r, int k);
int main(){
    int i, n, *arr;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n); 
    for(i=0;i<n;i++) scanf("%d",&arr[i]); //입력
    inPlaceQuickSort(arr,0,n-1); //0부터 n-1까지의 index에 대해서 제자리 퀵 정렬 진행
    for(i=0;i<n;i++) printf(" %d",arr[i]);
    return 0;
}
void inPlaceQuickSort(int *arr, int l, int r){
    int k;
    I index;
    if(l>=r) return; //l이 r보다 같거나 크면 return
    k = findPivot(arr,l,r); //랜덤으로 pivot의 index를 반환해줌
    index = inPlacePartition(arr, l, r, k); //index 구조체로 값을 받고 
    inPlaceQuickSort(arr, l, index.a-1); //구조체에 들어있는 a와 b를 이용해서 각 파티션에 대한 퀵 정렬 수행
    inPlaceQuickSort(arr, index.b+1, r);
}
int findPivot(int *arr, int l, int r){
    int i;
    srand(time(NULL)); 
    i = rand()%(l-r+1)+l; //l~r사이의 값 중 랜덤으로 값을 받음
    return i;
}
I inPlacePartition(int *arr, int l, int r, int k){
    int tmp;
    int i, j, pivot;
    pivot = arr[k];
    tmp = arr[k]; //pivot을 숨겨줌
    arr[k] = arr[r];
    arr[r] = tmp;
    i = l; //l부터
    j = r-1; //r-1까지의 범위에 대해 수행

    while(i<=j){
        while(i<j && arr[i]<=pivot){
            i++;
        }
        while(i<j && arr[j]>=pivot){
            j--;
        }
        if(i<j){
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    tmp = arr[i];
    arr[i] = arr[r];
    arr[r] = arr[i];



}