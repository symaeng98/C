#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct heap{
    int Heap[101];
    int n;
    int totalNum;
}H;

//함수 선언
void insertItem(H *h, int key);
void upHeap(H *h, int index);
void downHeap(H *h, int index);
void printArray(H *h);
void inPlaceHeapSort(H *h);
void swapElement(H *h, int index1, int index2);
void main(){
    char ch;
    int num, i, key;
    H heap, *h;
    h = &heap;
    h->n = 0;
    scanf("%d",&num);
    h->totalNum = num;
    for(i=0;i<num;i++){
        scanf("%d",&key);
        insertItem(h, key);
    } //힙 생성

    inPlaceHeapSort(h);
    printArray(h);
    return;
}
void insertItem(H *h, int key){
    h->n++;
    h->Heap[h->n] = key;
    upHeap(h,h->n);
}
void upHeap(H *h, int index){
    if(index == 1) return;
    if(h->Heap[index]>h->Heap[index/2]){ 
        swapElement(h,index,index/2);
        upHeap(h,index/2);
    }
}
void downHeap(H *h, int index){
    int maxIndex;
    if(index*2>h->n) return; //leaf 노드면 return
    else if(index*2==h->n){ //왼쪽 자식만 있으면
        if(h->Heap[index]<h->Heap[index*2]){
            swapElement(h,index,index*2);
            downHeap(h,index*2);
        }
        return;
    }
    else{ //모든 자식이 있으면
        if(h->Heap[index*2]>h->Heap[index*2+1]){//leftchild가 더 크면
            maxIndex = index*2;
        }
        else{
            maxIndex = index*2+1;
        }
        if(h->Heap[index]<h->Heap[maxIndex]){
            swapElement(h,index,maxIndex);
            downHeap(h,maxIndex);
        }
        return;
    }
}
void printArray(H *h){
    int i;
    for(i=1;i<=h->totalNum;i++){
        printf(" %d",h->Heap[i]);
    }
}
void inPlaceHeapSort(H *h){
    int i, num;
    num = h->n;
    for(i=0;i<num-1;i++){
        swapElement(h,h->n,1); //가장 큰 값(첫 번째 원소)을 마지막 값과 교환
        h->n--;
        downHeap(h,1); 
    }
}
void swapElement(H *h, int index1, int index2){
    int tmp;
    tmp = h->Heap[index1];
    h->Heap[index1] = h->Heap[index2];
    h->Heap[index2] = tmp;
}