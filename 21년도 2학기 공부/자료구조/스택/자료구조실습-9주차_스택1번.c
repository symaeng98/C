#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char data;
    struct node *next;
}ND;
typedef struct stack{
    ND *head;
    ND *top;
    int max_num;
    int cnt;
}ST;
void push(ST *stack, char c);
char pop(ST *stack);
void peek(ST *stack);
void duplicate(ST *stack);
void upRotate(ST *stack, int n);
void downRotate(ST *stack, int n);
void print(ST *stack);
int main(){
    ST stack;
    int N, num, i, num_data;
    char ch[7];
    char data;
    stack.head = (ND*)malloc(sizeof(ND));
    stack.head->next = NULL;
    stack.cnt = 0;
    stack.top = stack.head;
    scanf("%d",&N);
    stack.max_num = N;
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++){
        scanf("%s",ch);
        if (!strcmp(ch,"*")){
            getchar();
            scanf("%c",&data);
            push(&stack, data);
        }
        else if(!strcmp(ch,"POP")){
            pop(&stack);
        }
        else if(!strcmp(ch, "PEEK")){
            peek(&stack);
        }
        else if(!strcmp(ch, "DUP")){
            duplicate(&stack);
        }
        else if(!strcmp(ch,"UpR")){
            getchar();
            scanf("%d",&num_data);
            upRotate(&stack,num_data);
        }
        else if(!strcmp(ch,"DownR")){
            getchar();
            scanf("%d",&num_data);
            downRotate(&stack,num_data);
        }
        else if(!strcmp(ch, "PRINT")){
            print(&stack);
        }
        else{
            printf("?ž…? ¥ ?ž˜ëª»ë¨\n");
        }
    }
    return 0;
}
void push(ST *stack, char c){
    ND *new, *p;
    int i;
    if(stack->cnt == stack->max_num){
        printf("Stack FULL\n");
        return;
    }
    else{
        new = (ND *)malloc(sizeof(ND));
        new->next = NULL;
        new->data = c;
        stack->top->next = new;
        stack->top = new;
        stack->cnt += 1;
        return;
    }
}
char pop(ST *stack){
    ND *p,*q;
    char ch;
    int i;
    if(stack->cnt == 0){
        printf("Stack Empty\n");
        return '#';
    }
    p = stack->head;
    for(i=0;i<stack->cnt-1;i++){
        p = p->next;
    }
    q = stack->top;
    ch = q->data;
    p->next = NULL;
    free(q);
    stack->cnt -= 1;
    stack->top = p;
    return ch;
}
void peek(ST *stack){
    if(stack->cnt == 0){
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n",stack->top->data);
    return;
}
void duplicate(ST *stack){
    char ch;
    if(stack->cnt==0){
        printf("Stack Empty\n");
        return;
    }
    ch = pop(stack);
    push(stack, ch);
    push(stack, ch);
    return;
}
void downRotate(ST *stack, int n){
    ST sub_stack;
    char ch;
    int i;
    if(n>stack->cnt){
        return;
    }
    sub_stack.head = (ND*)malloc(sizeof(ND));
    sub_stack.cnt = 0;
    sub_stack.head->next = NULL;
    sub_stack.max_num = 1000000;
    sub_stack.top = sub_stack.head;
    for(i=0;i<n-1;i++){
        push(&sub_stack,pop(stack));
    }
    ch = pop(stack);
    for(i=0;i<n-1;i++){
        push(stack,pop(&sub_stack));
    }
    push(stack,ch);
    return;
}
void upRotate(ST *stack, int n){
    ST sub_stack;
    char ch;
    int i,num=0,j;
    if(n>stack->cnt){
        return;
    }
    sub_stack.head = (ND*)malloc(sizeof(ND));
    sub_stack.cnt = 0;
    sub_stack.head->next = NULL;
    sub_stack.max_num = 1000000;
    sub_stack.top = sub_stack.head;
    ch = pop(stack);
    num = stack->cnt;
    for(i=0;i<n-1;i++){
        push(&sub_stack,pop(stack));
    }
    push(stack,ch);
    num = sub_stack.cnt;
    for(i=0;i<n-1;i++){
        push(stack,pop(&sub_stack));
    }
    return;
}
void print(ST *stack){
    ST sub_stack;
    char ch;
    int i, num=0;
    sub_stack.head = (ND*)malloc(sizeof(ND));
    sub_stack.cnt = 0;
    sub_stack.head->next = NULL;
    sub_stack.top = sub_stack.head;
    sub_stack.max_num = 1000000;
    num = stack->cnt;
    for(i=0;i<num;i++){
        ch = pop(stack);
        printf("%c",ch);
        push(&sub_stack, ch);
    }
    printf("\n");
    num = sub_stack.cnt;
    for(i=0;i<num;i++){
        push(stack,pop(&sub_stack));
    }
    return;
}