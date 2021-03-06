#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inPlaceQuickSort(int *arr, int l, int r);
int findPivot(int *arr, int l, int r);
int inPlacePartition(int *arr, int l, int r, int k);
void swapElements(int *arr, int a, int b);
int main(){
    int i, n, *arr;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n); 
    for(i=0;i<n;i++) scanf("%d",&arr[i]); //입력
    inPlaceQuickSort(arr,0,n-1); //0부터 n-1까지의 index에 대해서 제자리 퀵 정렬 진행
    for(i=0;i<n;i++) printf(" %d",arr[i]);
    free(arr);
    return 0;
}
void inPlaceQuickSort(int *arr, int l, int r){
    int k;
    int index;
    if(l>=r) return;
    k = findPivot(arr,l,r);
    index = inPlacePartition(arr,l,r,k);
    inPlaceQuickSort(arr,l,index-1);
    inPlaceQuickSort(arr,index+1,r);
}
int findPivot(int *arr, int l, int r){
    //랜덤으로 Pivot을 설정해주는 버전(4)
    // int i;
    // srand(time(NULL)); 
    // i = rand()%(l-r+1)+l; //l~r사이의 값 중 랜덤으로 값을 받음
    // return i;

    //가장 첫 번째 원소를 Pivot으로 사용하는 버전(1)
    return l;
}
int inPlacePartition(int *arr, int l, int r, int k){
    int tmp;
    int i, j, pivot;
    //Pivot이 매번 첫 번째 원소를 사용하면 Pivot을 숨길 필요가 없지만,
    //어떤 상황이 올지 모르니 k를 l이라고 생각하지 않고 코드를 쓰자.
    pivot = arr[k];
    swapElements(arr,k,r); //Pivot 숨겨줌
    i = l; //l부터
    j = r-1; //r-1까지의 범위에 대해 수행
    while(i<=j){
        while(i<r && arr[i]<=pivot){
            i++;
        }
        while(l<=j && arr[j]>=pivot){
            j--;
        }
        if(i<j){ //i와 j가 엇갈리지 않았다면,
            swapElements(arr,i,j);
        }
    }
    //i와 j가 엇갈려서 반복문을 탈출 했다면
    swapElements(arr,i,r); //pivot과 i의 원소를 swap
    return i;
}
void swapElements(int *arr, int a, int b){
    int tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}