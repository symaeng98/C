#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int N, *arr, i, j, save;
    scanf("%d",&N);
    arr = (int *)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<N;i++){
        save = arr[i];
        j = i-1;
        while((j>=0)&&(arr[j]>save)){
            arr[j+1] = arr[j]; //�� �ٿ��ֱ�
            j--;
        }
        arr[j+1] = save; //j�� �� ��󺸴� ���� ���� ��ġ�̹Ƿ� j+1�� ����
    }
    for(i=0;i<N;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}