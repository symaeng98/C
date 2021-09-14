#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void selection_sort(int *arr, int N, int reverse);
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

    //---------------case A----------------

    printf("----정렬이 안 된 데이터의 정렬 시간----\n\n");
    // --------------선택 정렬 시간 측정---------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    selection_sort(arrA,N,1); //선택 정렬
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("선택 정렬 시간: %.12f ms\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);

    
    //---------------삽입 정렬 시간 측정--------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입 정렬 시간: %.12f ms\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);
    
    // 정렬된 데이터를 위한 정렬
    for(i=0;i<N;i++){
        arrA[i] = arrB[i] = rand()%N;
    }
    selection_sort(arrA,N,1);
    selection_sort(arrB,N,1);
    
    //------------------- case B ------------------- 
    printf("----정렬된 데이터의 정렬 시간----\n\n");
    // --------------선택 정렬 시간 측정---------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    selection_sort(arrA,N,1);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("선택 정렬 시간: %.12f ms\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);

    
    
    //---------------삽입 정렬 시간 측정--------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입 정렬 시간: %.12f ms\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);
    

    //역순으로 정렬시키기
    for(i=0;i<N;i++){
        arrA[i] = arrB[i] = rand()%N;
    }
    selection_sort(arrA,N,0); //0이면 역순
    selection_sort(arrB,N,0);



    printf("----역순으로 정렬된 데이터의 정렬 시간----\n\n");
    // --------------선택 정렬 시간 측정---------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    selection_sort(arrA,N,1);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("선택 정렬 시간: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);

    
    //---------------삽입 정렬 시간 측정--------------- //
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입 정렬 시간: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);

    free(arrA);
    free(arrB);
    return 0;
}
void selection_sort(int *arr, int N,int reverse){ //선택 정렬 알고리즘
    int max_index, i, j, tmp, min_index;
    if(reverse){
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
    else{
        for(i=N-1;i>=1;i--){
            min_index = i;
            for(j=i-1;j>=0;j--){
                if(arr[j]<arr[min_index]){
                    min_index = j;
                }
            }
            tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
}
void insertion_sort(int *arr, int N){ //삽입 정렬 알고리즘
    int i, j, save;
    for(i=1;i<N;i++){
        save = arr[i];
        j = i-1;
        while((j>=0)&&(arr[j]>save)){
            arr[j+1] = arr[j]; //값 붙여넣기
            j--;
        }
        arr[j+1] = save; //j는 비교 대상보다 작은 수의 위치이므로 j+1에 삽입
    }
}