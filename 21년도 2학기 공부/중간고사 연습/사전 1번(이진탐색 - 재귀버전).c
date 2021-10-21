#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bianrySearch(int *arr,int l, int r, int k);
int main(){
    int n, k, *arr, i;
    scanf("%d %d",&n,&k);
    arr = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("%d",bianrySearch(arr,0,n-1,k));
    return 0;
}
int bianrySearch(int *arr,int l, int r, int k){
    int mid;
    mid = (l+r)/2;
    if(l>r){
        return r;
    }
    else{
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]<k){
            bianrySearch(arr,mid+1,r,k);
        }
        else{
            bianrySearch(arr,l,mid-1,k);
        }
    }
}