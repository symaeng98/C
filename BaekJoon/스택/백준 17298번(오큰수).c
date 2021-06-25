#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void push(int *st, int *index, int num);
int pop(int *st, int *index);
int main(){
    int N,i,top=-1;
    int A[1000001],st[1000001],ans[1000001];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
        ans[i]=-1; //ans배열은 모두 -1로 초기화
    }
    for(i=0;i<N;i++){ 
        while (top!=-1 && A[st[top]] < A[i]){ //스택이 비어있지 않고, 스택의 top이 가리키는 인덱스의 A값이
            ans[pop(st, &top)] = A[i]; //현재 탐색하는 인덱스의 A값보다 작으면, A[i]값을 스택의 top이 가리키는 인덱스의 값을 pop해서 나온 인덱스의 ans에 넣어준다.
        }
        push(st,&top,i); //탐색중인 값이 더 작으면 인덱스를 push해준다.
    }
    for(i=0;i<N;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
void push(int *st, int *index, int num){
    *index+=1;
    st[*index] = num;
}
int pop(int *st, int *index){
    int num;
    num = st[*index];
    *index -= 1;
    return num;
}