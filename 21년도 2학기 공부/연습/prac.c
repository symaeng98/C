#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void one();
void two();
int re(int a, int n);
//메인 함수 
int main(){
    int num;
    scanf("%d",&num);
    if(num==1) one();
    else two();

    return 0;
}
void one(){
    int a, b, c;
    scanf("%d",&a);
    scanf("%d",&b);
    c = a-b;
    if(c%3==0){
        printf("%d is 3의 배수");
    }
    else{
        printf("%d is 3의 배수가 아님");
    }
}
void two(){
    int n, a;
    int i;
    scanf("%d",&n);
    scanf("%d",&a);
    i = 0;
    while(i!=n+1){
        printf("%d ",re(a,i));
        i += 1;
    }
}

int re(int a, int n){
    if(n<2) return 1;
    else{
        return re(a, n-1)+re(a, n-2)+a;
    }
}