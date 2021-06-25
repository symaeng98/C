#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int top=-1,isRight=1, j;
    char bracket[110], bracket_stack[110];
    while(1){
        top = -1;
        isRight=1;
        fgets(bracket,110,stdin);
        if(!strcmp(bracket,".\n")){
            break;
        }
        for(j=0;j<strlen(bracket);j++){
            if(bracket[j]=='('||bracket[j]=='['){ //왼쪽 괄호면,
                top += 1; //push
                bracket_stack[top] = bracket[j];
            }
            else if(bracket[j]==')'){ //오른쪽 괄호면,
                if(bracket_stack[top]!='('){ //그에 맞는 왼쪽 괄호가 아니면
                    printf("no\n"); //no출력
                    isRight=0;
                    break;
                }
                else{ //맞으면,
                    top-=1; //pop
                }
            }
            else if(bracket[j]==']'){
                if(bracket_stack[top]!='['){
                    printf("no\n");
                    isRight=0;
                    break;
                }
                else{
                    top-=1;
                }
            }
        }
        if(isRight==1){
            if(top!=-1){
                printf("no\n");
            }
            else{
                printf("yes\n");
            }
        }
    }
    return 0;
}
