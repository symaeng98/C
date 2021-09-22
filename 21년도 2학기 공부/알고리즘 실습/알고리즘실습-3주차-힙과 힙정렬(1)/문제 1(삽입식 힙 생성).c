#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//전역 변수 선언
int heap[101], n=0;

//함수 선언
void insertItem(int key);
int removeMax();
void upHeap(int index);
void downHeap(int index);
void printHeap();

void main(){
    char ch;
    int key;
    while(1){
        scanf("%c",&ch);
        getchar();
        if(ch=='q') break;
        else if(ch=='i'){
            scanf("%d", &key);
            getchar();
            insertItem(key);
            printf("0\n");
        }
        else if(ch=='d'){
            printf("%d\n",removeMax());
        }
        else if(ch=='p'){
            printHeap();
        }
        else{
            printf("입력이 잘못됨\n");
        }
        
    }
    return;
}
void insertItem(int key){
    n++;
    heap[n] = key;
    upHeap(n);
    return;
}
int removeMax(){
    int key;
    key = heap[1];
    heap[1] = heap[n];
    n--;
    downHeap(1);
    return key;
}
void upHeap(int index){
    int tmp;
    if((heap[index/2]>heap[index])||index==1){ //부모가 더 크면 탈출
        return;
    }
    else{ //부모가 더 작으면 교환
        tmp = heap[index/2];
        heap[index/2] = heap[index];
        heap[index] = tmp;
        upHeap(index/2);
    }
}
void downHeap(int index){
    int left, right, max_index, tmp;
    if(n<index*2){ //자식이 없음 //external node임
        return;
    }
    else if(n==index*2){ //자식이 left만 있음
        if(heap[index]<heap[index*2]){ //left가 더 크면
            tmp = heap[index];
            heap[index] = heap[index*2];
            heap[index*2] = tmp;
            return;
        }      
        return;
    }
    else{ //자식이 둘 다 있을 때
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