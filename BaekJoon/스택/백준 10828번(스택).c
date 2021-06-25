#include <stdio.h>
#include <string.h>

void push_X(int x, int *s, int *index);
void pop(int *s, int *index);
void size(int *index);
void empty(int *index);
void Top(int *s, int *index);

int main(){
    int N, i, num;
    int stack[10001], top = -1;
    char st[10];
    char _push[5] = "push", _pop[5] = "pop", _size[5] = "size", _empty[6] = "empty", _top[5] = "top";
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        scanf("%s",&st);
        if (!strcmp(_push,st)){
            scanf("%d",&num);
            push_X(num, stack, &top);
        }
        else if(!strcmp(_pop,st)){
            pop(stack,&top);
        }
        else if(!strcmp(_size,st)){
            size(&top);
        }
        else if(!strcmp(_empty,st)){
            empty(&top);
        }
        else{
            Top(stack,&top);
        }
    }


    return 0;
}
void push_X(int x, int *s, int *index){
    *index += 1;
    s[*index] = x;
}
void pop(int *s, int *index){
    if(*index == -1){
        printf("-1\n");
    }
    else{
        printf("%d\n",s[*index]);
        *index -= 1;
    }
}
void size(int *index){
    printf("%d\n",(*index)+1);
}
void empty(int *index){
    if(*index==-1){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}
void Top(int *s, int *index){
    if(*index==-1){
        printf("-1\n");
    }
    else{
        printf("%d\n",s[*index]);
    }
}