#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//메인 함수 
int main(){
    int a, b, m, n, i;
    char ch;
    scanf("%d %d %d",&a,&b,&n);
    getchar();
    for(i=0;i<n;i++){
        m = (a + b) / 2;
        scanf("%c",&ch);
        if(ch=='Y'){
            a = m + 1;
        }
        else{
            b = m;
        }
    }
    printf("%d",a);
    return 0;
}