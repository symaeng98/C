#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Heap{
    int H[100];
    int num;
}H;
void downHeap(H *heap, int index);
void printHeap(H *heap);
void swapElements(H *heap, int index1, int index2);
void rBuildheap(H *heap, int index);
void Buildheap(H *heap);
int main(){
    H heap;
    int key, i, n;
    char ch;
    scanf("%d",&n);
    heap.num = n;
    for(i=1;i<=n;i++){
        scanf("%d",&heap.H[i]);
    }
    // rBuildheap(&heap,1);
    Buildheap(&heap);
    printHeap(&heap);
    return 0;
}
void rBuildheap(H *heap, int index){
    if(index>heap->num) return;
    rBuildheap(heap, index*2);
    rBuildheap(heap, index*2+1);
    downHeap(heap,index);
}
void Buildheap(H *heap){
    int i;
    for(i=heap->num;i>0;i--){
        downHeap(heap, i);
    }
}
void downHeap(H *heap, int index){
    int maxIndex;
    if(index*2>heap->num){
        return;
    }
    if(index*2==heap->num){
        if(heap->H[index]<heap->H[index*2]){
            swapElements(heap,index, index*2);
            downHeap(heap,index*2);
        }
    }
    else{
        if(heap->H[index*2]>heap->H[index*2+1]){
            maxIndex = index*2;
        }
        else
            maxIndex = index*2+1;
        if(heap->H[index]<heap->H[maxIndex]){
            swapElements(heap,index, maxIndex);
            downHeap(heap,maxIndex);
        }
    }
}
void printHeap(H *heap){
    int i;
    for(i=1;i<=heap->num;i++){
        printf(" %d",heap->H[i]);
    }
    printf("\n");
}
void swapElements(H *heap, int index1, int index2){
    int tmp;
    tmp = heap->H[index1];
    heap->H[index1] = heap->H[index2];
    heap->H[index2] = tmp;
}
