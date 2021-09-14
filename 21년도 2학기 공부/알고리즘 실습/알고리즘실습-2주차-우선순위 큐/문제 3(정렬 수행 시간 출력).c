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

    printf("----������ �� �� �������� ���� �ð�----\n\n");
    // --------------���� ���� �ð� ����---------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    selection_sort(arrA,N,1); //���� ����
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("���� ���� �ð�: %.12f ms\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);

    
    //---------------���� ���� �ð� ����--------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("���� ���� �ð�: %.12f ms\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);
    
    // ���ĵ� �����͸� ���� ����
    for(i=0;i<N;i++){
        arrA[i] = arrB[i] = rand()%N;
    }
    selection_sort(arrA,N,1);
    selection_sort(arrB,N,1);
    
    //------------------- case B ------------------- 
    printf("----���ĵ� �������� ���� �ð�----\n\n");
    // --------------���� ���� �ð� ����---------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    selection_sort(arrA,N,1);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("���� ���� �ð�: %.12f ms\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);

    
    
    //---------------���� ���� �ð� ����--------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("���� ���� �ð�: %.12f ms\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);
    

    //�������� ���Ľ�Ű��
    for(i=0;i<N;i++){
        arrA[i] = arrB[i] = rand()%N;
    }
    selection_sort(arrA,N,0); //0�̸� ����
    selection_sort(arrB,N,0);



    printf("----�������� ���ĵ� �������� ���� �ð�----\n\n");
    // --------------���� ���� �ð� ����---------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    selection_sort(arrA,N,1);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("���� ���� �ð�: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);

    
    //---------------���� ���� �ð� ����--------------- //
    QueryPerformanceCounter(&start);
    // �ð��� �����ϰ� ���� �۾�(��: �Լ� ȣ��)�� �̰��� ����
    insertion_sort(arrB,N);
    QueryPerformanceCounter(&end);
    // ���������κ��� ����ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("���� ���� �ð�: %.12f sec\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)/1000.0);

    free(arrA);
    free(arrB);
    return 0;
}
void selection_sort(int *arr, int N,int reverse){ //���� ���� �˰���
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
void insertion_sort(int *arr, int N){ //���� ���� �˰���
    int i, j, save;
    for(i=1;i<N;i++){
        save = arr[i];
        j = i-1;
        while((j>=0)&&(arr[j]>save)){
            arr[j+1] = arr[j]; //�� �ٿ��ֱ�
            j--;
        }
        arr[j+1] = save; //j�� �� ��󺸴� ���� ���� ��ġ�̹Ƿ� j+1�� ����
    }
}