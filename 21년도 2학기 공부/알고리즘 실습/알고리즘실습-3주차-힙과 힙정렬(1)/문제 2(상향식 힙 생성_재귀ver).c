#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//���� ���� ����
int heap[101], n=0;

//�Լ� ����
void recursiveBuildHeap(int index);
void downHeap(int index);
void printHeap();

void main(){
    int N, i;
    scanf("%d",&N);
    n = N;
    for(i=1;i<=N;i++){
        scanf("%d",&heap[i]);
    }
    recursiveBuildHeap(1);
    printHeap();
    return;
}
void recursiveBuildHeap(int index){
    if(index>n) return; //�ܺ� ���� Ż��
    recursiveBuildHeap(index*2);
    recursiveBuildHeap(index*2 + 1);
    downHeap(index);
    return;
}
void downHeap(int index){
    int left, right, max_index, tmp;
    if(n<index*2){ //�ڽ��� ���� //external node��
        return;
    }
    else if(n==index*2){ //�ڽ��� left�� ����
        if(heap[index]<heap[index*2]){ //left�� �� ũ��
            tmp = heap[index];
            heap[index] = heap[index*2];
            heap[index*2] = tmp;
            return;
        }      
        return;
    }
    else{ //�ڽ��� �� �� ���� ��
        left = heap[index*2];
        right = heap[index*2 + 1];
        if(left>right) max_index = index*2;
        else max_index = index*2 + 1;
        if(heap[index]<heap[max_index]){
            tmp = heap[index];
            heap[index] = heap[max_index];
            heap[max_index] = tmp;
            downHeap(max_index);
        }
    }
}
void printHeap(){
    int i;
    for(i=1;i<=n;i++)
        printf(" %d",heap[i]);
    printf("\n");
}