#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void selection_sort(int *arr, int N);
void insertion_sort(int *arr, int N);
void insertion_sort2(int *arr, int N);
int main() {
    int N, *arrA, *arrB, i, j, max_index, tmp;
    scanf("%d",&N);
    arrA = (int *)malloc(sizeof(int)*N);
    arrB = (int *)malloc(sizeof(int)*N);
    srand(time(NULL));
    for(i=0;i<N;i++){
        arrA[i] = arrB[i] = rand()%N;
    }
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    QueryPerformanceFrequency(&ticksPerSec);
    printf("----정렬이 안 된 데이터의 정렬 시간----\n\n");
    // --------------선택 정렬 시간 측정---------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    selection_sort(arrA,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("선택 정렬 시간: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    
    
    //---------------삽입 정렬 시간 측정--------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입 정렬 시간: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    


    printf("----정렬된 데이터의 정렬 시간----\n\n");
    // --------------선택 정렬 시간 측정---------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    selection_sort(arrA,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("선택 정렬 시간: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    
    
    //---------------삽입 정렬 시간 측정--------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입 정렬 시간: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));



    int *p, *q;
    for(p=arrA,q=&arrA[N-1];p<q;p++,q--){
        int tmp;
        tmp = *p;
        *p = *q;
        *q = tmp;
    }
    for(p=&arrB[0],q=&arrB[N-1];p<q;p++,q--){
        int tmp;
        tmp = *p;
        *p = *q;
        *q = tmp;
    }
    printf("----역순으로 정렬된 데이터의 정렬 시간----\n\n");
    // --------------선택 정렬 시간 측정---------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    selection_sort(arrA,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("선택 정렬 시간: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    
    
    //---------------삽입 정렬 시간 측정--------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입 정렬 시간: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));


    return 0;
}
void selection_sort(int *arr, int N){ //선택 정렬 알고리즘
    int max_index, i, j, tmp;
    for(i=N-1;i>=1;i--){
        max_index = i;
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[max_index]){
                max_index = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = tmp;
    }
}
void insertion_sort(int *arr, int N){ //삽입 정렬 알고리즘
    int i, j, tmp;
    for(i=1;i<N;i++){
        for(j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
            else{
                break;
            }
        }
    }
}