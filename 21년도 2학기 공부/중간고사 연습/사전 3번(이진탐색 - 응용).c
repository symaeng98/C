#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int a, b, n, i;
    int mid;
    char ch;
    scanf("%d %d %d",&a,&b,&n);
    getchar();
    for(i=0;i<n;i++){
        scanf("%c",&ch);
        mid = (a+b)/2;
        if(ch=='Y'){
            a = mid+1;
        }
        else{
            b = mid;
        }
    }
    printf("%d",a);
    return 0;
}