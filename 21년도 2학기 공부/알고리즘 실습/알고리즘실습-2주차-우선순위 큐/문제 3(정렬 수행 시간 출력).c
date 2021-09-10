#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void selection_sort(int *arr, int N);
void insertion_sort(int *arr, int N);
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
    printf("----������ �� �� �������� ���� �ð�----\n\n");
    // --------------���� ���� �ð� ����---------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    selection_sort(arrA,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("���� ���� �ð�: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    
    
    //---------------���� ���� �ð� ����--------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("���� ���� �ð�: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    


    printf("----���ĵ� �������� ���� �ð�----\n\n");
    // --------------���� ���� �ð� ����---------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    selection_sort(arrA,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("���� ���� �ð�: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    
    
    //---------------���� ���� �ð� ����--------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("���� ���� �ð�: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));



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
    printf("----�������� ���ĵ� �������� ���� �ð�----\n\n");
    // --------------���� ���� �ð� ����---------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    selection_sort(arrA,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("���� ���� �ð�: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    
    
    //---------------���� ���� �ð� ����--------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("���� ���� �ð�: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));


    return 0;
}
void selection_sort(int *arr, int N){ //���� ���� �˰���
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
void insertion_sort(int *arr, int N){ //���� ���� �˰���
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