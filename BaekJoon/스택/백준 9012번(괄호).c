#include <stdio.h>
#include <string.h>

int main(){
    int N, i, top=-1,isRight=1, j;
    char bracket[100], bracket_stack[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        top = -1;
        isRight=1;
        scanf("%s",bracket);
        for(j=0;j<strlen(bracket);j++){
            if(bracket[j]=='('){ //'('가 나오면 push해주고
                top+=1;
                bracket_stack[top]='(';
            }
            else{ //')'가 나오면
                if(top==-1){  //스택에 '('가 없으면
                    printf("NO\n"); //NO출력
                    isRight=0;
                    break;
                }
                else{ //스택에 '('가 있으면 pop해준다.
                    top-=1; 
                }
            }
        }
        if(isRight){ //반복문을 모두 통과했을 경우,
            if(top!=-1){ //아직 스택에 '('가 남아있으면 NO
                printf("NO\n");
            }
            else{ //그렇지 않으면 YES
                printf("YES\n");
            }
        }
    }
    return 0;
}