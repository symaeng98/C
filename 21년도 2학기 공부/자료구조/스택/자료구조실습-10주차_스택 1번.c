#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	struct node *next;
	char data;
	int rank;
}ND;
typedef struct stack {
	ND *head;
	int n;
}ST;
void push(ST *stack, char data);
char pop(ST *stack);
int main() {
	int N, i, length, j, k, rank = 0, cnt = 0,cnt1=0,flag=0,flag2=0;
	char **equ, check, check1;
	char *st, data, pre = '?';
	ST stack;
	ND *p, *q;
	stack.head = (ND *)malloc(sizeof(ND));
	stack.head->rank = 0;
	stack.head->next = NULL;
	stack.n = 0;
	scanf("%d", &N);
	getchar();
	equ = (char **)malloc(sizeof(char *)*N);
	for (i = 0; i < N; i++) {
		equ[i] = (char *)malloc(sizeof(char) * 101);
	}
	p = stack.head;
	for (i = 0; i < N; i++) {
		gets(equ[i]);
		st = equ[i];
		length = strlen(equ[i]);
		for (j = 0; j < length; j++) {
			if (st[j] >= 'A'&&st[j] <= 'Z') {//���ĺ��̸�
				printf("%c", st[j]);
				cnt1 = 0;
			}
			else {
				if (j == 0 && (st[j] == '+' || st[j] == '-')) {
					push(&stack, st[j]);
					p = stack.head->next;
					p->rank = 6;
					flag = 1;
				}
				else if (j != 0)
					flag = 0;
				if (flag == 0) {
					cnt1++;
					if (cnt1 == 2 && (st[j] == '+' || st[j] == '-' )&&st[j-1]!=')') {//�����̸�
						cnt1 = 0;
						push(&stack, st[j]);
						flag2 = 1;
					}
					else {
						flag2 = 0;
					}
					if (flag2 == 0) {//���Ӿƴϸ�
						if (stack.n > 0) {//������ ���ÿ� ���� �鰡������
							p = stack.head;
							for (k = 0; k < stack.n; k++) {//top�� ����
								p = p->next;
							}
							if (st[j] == '!') {
								rank = 6;
							}
							else if (st[j] == '*' || st[j] == '/') {
								rank = 5;
							}
							else if (st[j] == '+' || st[j] == '-') {
								rank = 4;
							}
							else if (st[j] == '>' || st[j] == '<') {
								rank = 3;
							}
							else if (st[j] == '&') {
								rank = 2;
								cnt++;
							}
							else if (st[j] == '|') {
								rank = 1;
								cnt++;
							}
							else if (st[j] == '(' || st[j] == ')')
								rank = 0;
							if (p->rank >= rank && st[j] != '('&&st[j] != ')') {
								if (cnt == 2) {
									push(&stack, st[j]);
									cnt = 0;
								}
								else {
									while (p->rank >= rank) {
										q = stack.head;
										for (k = 1; k < stack.n; k++) {
											q = q->next;
										}
										printf("%c", pop(&stack));
							
										p = q;
									}
									push(&stack, st[j]);
								}
							}
							else if (st[j] == '(') {
								push(&stack, st[j]);
							}
							else if (p->rank < rank)
								push(&stack, st[j]);
							if (st[j] == ')') {
								check = pop(&stack);
								while (check != '(') {
									printf("%c", check);
									check = pop(&stack);
								}
							}
						}
						else {//������ ������
							push(&stack, st[j]);
							if (st[j] == '|' || st[j] == '&')
								cnt++;
						}
					}
				}//flag
			}
			if (j == length - 1) {
				while (stack.n != 0)
					printf("%c", pop(&stack));
			}
		}
		printf("\n");
	}
	return 0;
}
void push(ST *stack, char data) {
	int i;
	ND *p;
	ND *newN;
	p = stack->head;
	for (i = 0; i < stack->n; i++) {
		p = p->next;
	}
	newN = (ND*)malloc(sizeof(ND));
	newN->data = data;
	if (data == '!') {
		newN->rank = 6;
	}
	else if (data == '*' || data == '/') {
		newN->rank = 5;
	}
	else if (data == '+' || data == '-') {
		newN->rank = 4;
	}
	else if (data == '>' || data == '<') {
		newN->rank = 3;
	}
	else if (data == '&') {
		newN->rank = 2;
	}
	else if (data == '|') {
		newN->rank = 1;
	}
	else
		newN->rank = 0;
	p->next = newN;
	newN->next = NULL;
	stack->n = (stack->n) + 1;
}
char pop(ST *stack) {
	int i;
	char data;
	ND *p, *q;
	p = stack->head;
	for (i = 1; i < stack->n; i++) {
		p = p->next;
	}
	q = p->next;
	data = q->data;
	p->next = NULL;
	free(q);
	stack->n = stack->n - 1;
	return data;
}