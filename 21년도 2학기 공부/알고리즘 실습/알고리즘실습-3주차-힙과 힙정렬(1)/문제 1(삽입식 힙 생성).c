#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct heap{
    int Heap[101];
    int n;
}H;

//함수 선언
void insertItem(H *heap, int key);
int removeMax(H *heap);
void upHeap(H *heap, int index);
void downHeap(H *heap, int index);
void printHeap(H *heap);
void main(){
    char ch;
    int key;
    H heap, *h;
    heap.n = 0;
    h = &heap;
    while(1){
        scanf("%c",&ch);
        getchar();
        if(ch=='q') break;
        else if(ch=='i'){
            scanf("%d", &key);
            getchar();
            insertItem(h, key);
            printf("0\n");
        }
        else if(ch=='d'){
            printf("%d\n",removeMax(h));
        }
        else if(ch=='p'){
            printHeap(h);
        }
        else{
            printf("입력이 잘못됨\n");
        }
        
    }
    return;
}
void insertItem(H *heap, int key){
    heap->n++;
    heap->Heap[heap->n] = key;
    upHeap(heap,heap->n);
    return;
}
int removeMax(H *heap){
    int key;
    key = heap->Heap[1];
    heap->Heap[1] = heap->Heap[heap->n];
    heap->n--;
    downHeap(heap, 1);
    return key;
}
void upHeap(H *heap, int index){
    int tmp;
    if((heap->Heap[index/2]>heap->Heap[index])||index==1){ //부모가 더 크면 탈출
        return;
    }
    else{ //부모가 더 작으면 교환
        tmp = heap->Heap[index/2];
        heap->Heap[index/2] = heap->Heap[index];
        heap->Heap[index] = tmp;
        upHeap(heap, index/2);
    }
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