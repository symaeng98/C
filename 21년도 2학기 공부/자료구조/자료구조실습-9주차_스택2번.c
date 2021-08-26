#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data;
    struct node *next;
} ND;
typedef struct stack
{
    ND *head;
    ND *top;
    int cnt;
} ST;
void push(ST *stack, char c);
char pop(ST *stack);
int main()
{
    char ch[1010];
    int is_right = 1;
    ST stack;
    int N, num, i, num_data, cnt =0,j;
    char data;
    stack.head = (ND *)malloc(sizeof(ND));
    stack.head->next = NULL;
    stack.cnt = 0;
    stack.top = stack.head;
    scanf("%[^\n]",ch);
    for(i=0;i<strlen(ch);i++){
        if(ch[i]=='(' || ch[i]=='{' || ch[i]=='['){
            push(&stack, ch[i]);
            cnt++;
        }
        else if(ch[i]==')' || ch[i]=='}' || ch[i]==']'){
            data = pop(&stack);
            if(data=='#'){ //Stack_Empty
                for(j=i;j<strlen(ch);j++){
                    if(ch[j]==')' || ch[j]=='}' || ch[j]==']'|| ch[j]=='('|| ch[j]=='{'|| ch[j]=='['){
                        cnt++;
                    }
                }
                is_right = 0;
                break;
            }
            else{
                if((ch[i]==')'&&data=='(') || (ch[i]=='}'&&data=='{') || (ch[i]==']'&&data=='[')){
                    cnt++;
                }
                else{
                    for(j=i;j<strlen(ch);j++){
                    if(ch[j]==')' || ch[j]=='}' || ch[j]==']'|| ch[j]=='('|| ch[j]=='{'|| ch[j]=='['){
                        cnt++;
                    }
                }
                is_right = 0;
                break;
                }
            }
        }
        else{
            continue;
        }
    }
    if(!is_right || stack.cnt!=0){
        printf("Wrong_%d",cnt);
    }
    else{
        printf("OK_%d",cnt);
    }
    return 0;
}
void push(ST *stack, char c)
{
    ND *new, *p;
    int i;
    new = (ND *)malloc(sizeof(ND));
    new->next = NULL;
    new->data = c;
    stack->top->next = new;
    stack->top = new;
    stack->cnt += 1;
    return;
}
char pop(ST *stack)
{
    ND *p, *q;
    char ch;
    int i;
    if(stack->cnt==0){
        return '#';
    }
    p = stack->head;
    for (i = 0; i < stack->cnt - 1; i++)
    {
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