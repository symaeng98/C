#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Heap{
    int num;
    int *h;
}H;
void downHeap(H *h, int index);
void buildHeap(H *h);
void swapElements(H *h, int index1, int index2);
int main(){
    H h;
    int n, k, i, key;
    scanf("%d %d",&n,&k);
    h.h = (int *)malloc(sizeof(int)*(k+1));
    h.num = k;
    for(i=1;i<=k;i++){
        scanf("%d",&h.h[i]);
    }
    buildHeap(&h);
    for(i=0;i<n-k;i++){
        scanf("%d",&key);
        if(h.h[1]<key){
            h.h[1] = key;
            downHeap(&h, 1);
        }
    }
    for(i=0;i<k;i++){
        printf("%d ",h.h[1]);
        h.h[1] = h.h[h.num];
        h.num--;
        downHeap(&h,1);
    }
    free(h.h);
    return 0;
}
void downHeap(H *h, int index){
    int minIndex;
    if(h->num<index*2){
        return;
    }
    else if(h->num==index*2){
        if(h->h[index]>h->h[index*2]){
            swapElements(h,index,index*2);
            downHeap(h,index*2);
        }
    }
    else{
        if(h->h[index*2]<h->h[index*2+1]){
            minIndex = index*2;
        }
        else minIndex = index*2+1;
        if(h->h[minIndex]<h->h[index]){
            swapElements(h,index,minIndex);
            downHeap(h,minIndex);
        }
    }
}
void buildHeap(H *h){
    int i;
    for(i=h->num/2;i>0;i--){
        downHeap(h, i);
    }
}
void swapElements(H *h, int index1, int index2){
    int tmp;
    tmp = h->h[index1];
    h->h[index1] = h->h[index2];
    h->h[index2] = tmp;
}