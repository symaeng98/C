#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void push(int *st, int *index, int num);
void pop(int *index);
int main(){
    int N, i,top=-1, cnt=1, j=0, isRight=1;
    int stack[100001], sequence[100001];
    char ans[200001];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&sequence[i]);
    }
    push(stack,&top,cnt); //초기값 설정
    cnt += 1;
    ans[j] = '+'; //ans배열은 +나-를 저장
    j+=1; //j는 ans의 인덱스
    for(i=0;i<N;i++){
        while(1){
            if(sequence[i]<stack[top]){ //탐색하는 수열의 값이 스택의 top의 크기보다 작으면,
                isRight=0; //경우가 없다.
                break;
            }
            if(sequence[i]==stack[top]){ //탐색하는 수열의 값이면,
                pop(&top); //pop
                ans[j] = '-';
                j+=1;
                break;//반복문 탈출
            }
            else{ //탐색하는 수열의 값이 아니면,
                push(stack,&top,cnt);//맞을 때 까지 push를 해준다.
                cnt += 1;
                ans[j] = '+';
                j+=1;
            }
        }
    }
    if(isRight){ //정답이 있으면,
        for(i=0;i<strlen(ans);i++){ //출력
            printf("%c\n",ans[i]);
        }
    }
    else{
        printf("NO\n");
    }
    return 0;
}
void push(int *st, int *index, int num){
    *index+=1;
    st[*index] = num;
}
void pop(int *index){
    *index -= 1;
}