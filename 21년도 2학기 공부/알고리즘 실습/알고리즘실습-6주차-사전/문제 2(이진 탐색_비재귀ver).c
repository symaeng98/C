#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int *arr, int l, int r, int k);

int main(){
    int n, k, *arr,i;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    scanf("%d",&k);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf(" %d",binarySearch(arr,0,n-1,k));
    free(arr);
    return 0;
}

int binarySearch(int *arr, int l, int r, int k){
    int m;
    int fl, fr; //flag
    while(l<=r){
        fl = 0; fr = 0;
        m = (l+r)/2;
        if(arr[m]==k) return m;
        else if(arr[m]<k){
            l = m+1;
            fl = 1;
        }
        else{
            r = m-1;
            fr = 1;
        }
        
    }
    //마지막 비교 원소보다 k가 크면 fl에 1이, k가 작으면 fr에 1이 들어있다.
    if(fl) return l;
    else return r+1;
}
//마지막에 어떤 원소보다 크고, 어떤 원소보다 작아서 반복문을 탈출했는지에 따라
//return하는 값이 변한다.