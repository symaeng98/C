#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Heap{
    int H[100];
    int num;
}H;
void insertItem(H *heap, int key);
int removeMax(H *heap);
void upHeap(H *heap, int index);
void downHeap(H *heap, int index);
void printHeap(H *heap);
void swapElements(H *heap, int index1, int index2);
int main(){
    H heap;
    int key;
    char ch;
    heap.num = 0;
    while(1){
        scanf("%c",&ch);
        if(ch=='i'){
            scanf("%d",&key);
            insertItem(&heap, key);
        }
        else if(ch=='d'){
            printf("%d\n",removeMax(&heap));
        }
        else if(ch=='p'){
            printHeap(&heap);
        }
        else if(ch=='q'){
            break;
        }
        else{
            printf("입력이 잘못됨\n");
        }
        getchar();
    }

    return 0;
}
void insertItem(H *heap, int key){
    heap->num ++;
    heap->H[heap->num] = key;
    upHeap(heap,heap->num);
    printf("0\n");
    return;
}
int removeMax(H *heap){
    int data;
    data = heap->H[1];
    heap->H[1] = heap->H[heap->num];
    heap->num--;
    downHeap(heap, 1);
    return data;
}
void upHeap(H *heap, int index){
    if(index==1) return;
    if(heap->H[index]>heap->H[index/2]){
        swapElements(heap, index, index/2);
    }
    upHeap(heap, index/2);
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
