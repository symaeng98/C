#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�Լ� ���� ����
int binarySearch(char *p, int a, int b);

//���� �Լ� 
int main(){
    int a, b, n;
    char *YN, *p;
    scanf("%d %d %d",&a,&b,&n);
    YN = (char*)malloc(sizeof(char)*(n+1));
    scanf("%s",YN);
    p = YN;
    printf("%d",binarySearch(p,a,b));

    //free
    free(YN);
    return 0;
}

//�Լ� 
int binarySearch(char *p, int a, int b){
    int m;
    if(a==b) return a;
    m = (a+b)/2;
    if((*p) =='Y'){
        p++;
        binarySearch(p,m+1,b);
    }
    else{
        p++;
        binarySearch(p,a,m);
    }
}