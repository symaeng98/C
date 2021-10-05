#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void inPlaceQuickSort(int *arr, int l, int r);
typedef struct Index{ //a,b�� ��� ��ȯ�ϱ� ���� ����ü ����
    int a;
    int b;
}I;
int findPivot(int *arr, int l, int r);
I inPlacePartition(int *arr, int l, int r, int k);
int main(){
    int i, n, *arr;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n); 
    for(i=0;i<n;i++) scanf("%d",&arr[i]); //�Է�
    inPlaceQuickSort(arr,0,n-1); //0���� n-1������ index�� ���ؼ� ���ڸ� �� ���� ����
    for(i=0;i<n;i++) printf(" %d",arr[i]);
    return 0;
}
void inPlaceQuickSort(int *arr, int l, int r){
    int k;
    I index;
    if(l>=r) return; //l�� r���� ���ų� ũ�� return
    k = findPivot(arr,l,r); //�������� pivot�� index�� ��ȯ����
    index = inPlacePartition(arr, l, r, k); //index ����ü�� ���� �ް� 
    inPlaceQuickSort(arr, l, index.a-1); //����ü�� ����ִ� a�� b�� �̿��ؼ� �� ��Ƽ�ǿ� ���� �� ���� ����
    inPlaceQuickSort(arr, index.b+1, r);
}
int findPivot(int *arr, int l, int r){
    int i;
    srand(time(NULL)); 
    i = rand()%(l-r+1)+l; //l~r������ �� �� �������� ���� ����
    return i;
}
I inPlacePartition(int *arr, int l, int r, int k){
    int tmp;
    int i, j, pivot;
    pivot = arr[k];
    tmp = arr[k]; //pivot�� ������
    arr[k] = arr[r];
    arr[r] = tmp;
    i = l; //l����
    j = r-1; //r-1������ ������ ���� ����

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