#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct heap{
    int Heap[101];
    int n;
}H;

//함수 선언
void BuildHeap(H *heap);
void downHeap(H *heap, int index);
void printHeap(H *heap);

void main(){
    int N, i;
    H heap, *h;
    h = &heap;
    scanf("%d",&N);
    h->n = N;
    for(i=1;i<=N;i++){
        scanf("%d",&h->Heap[i]);
    }
    BuildHeap(h);
    printHeap(h);
    return;
}
void BuildHeap(H *heap){
    int i;
    for(i=heap->n/2;i>0;i--){
        downHeap(heap, i);
    }
    return;
}
void downHeap(H *heap, int index){
    int left, right, max_index, tmp;
    if(heap->n<index*2){ //자식이 없음 //external node임
        return;
    }
    else if(heap->n==index*2){ //자식이 left만 있음
        if(heap->Heap[index]<heap->Heap[index*2]){ //left가 더 크면
            tmp = heap->Heap[index];
            heap->Heap[index] = heap->Heap[index*2];
            heap->Heap[index*2] = tmp;
            return;
        }      
        return;
    }
    else{ //자식이 둘 다 있을 때
        left = heap->Heap[index*2];
        right = heap->Heap[index*2 + 1];
        if(left>right) max_index = index*2;
        else max_index = index*2 + 1;
        if(heap->Heap[index]<heap->Heap[max_index]){
            tmp = heap->Heap[index];
            heap->Heap[index] = heap->Heap[max_index];
            heap->Heap[max_index] = tmp;
            downHeap(heap, max_index);
        }
    }
}
void printHeap(H *heap){
    int i;
    for(i=1;i<=heap->n;i++)
        printf(" %d",heap->Heap[i]);
    printf("\n");
}