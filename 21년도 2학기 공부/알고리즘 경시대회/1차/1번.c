#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int k, n, b;
    int A = 10, B = 10;
    while(1){
        if(A==0||B==0) break;
        scanf("%d %d %d",&k, &n, &b);
        if(((k%2==0)&&(b%2==0))||((k%2!=0)&&(b%2!=0))){
            B += n;
            A -= n;
        }
        else{
            A += n;
            B -= n;
        }
        if(A>=20){
            A = 20;
            B = 0;
            break;
        }
        else if(A<=0){
            A = 0;
            B = 20;
            break;
        }
        if(B>=20){
            B = 20;
            A = 0;
            break;
        }
        else if(B<=0){
            B = 0;
            A = 20;
            break;
        }
        printf("%d %d\n",A,B);
    }
    printf("%d %d\n",A,B);
    return 0;
}