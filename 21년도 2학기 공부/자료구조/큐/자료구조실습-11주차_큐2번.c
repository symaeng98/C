#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	struct node *next;
	struct node *prev;
	int data;
}ND;
void add_front(ND *q, int data);
void add_rear(ND *q, int data);
int delete_front(ND *q);
int delete_rear(ND *q);
void print(ND *q);
int main() {
	int N, i, data, deqnum = 0;
	char ch[3];
	ND *front, *rear,*del;
	rear = front = NULL;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%s", ch);
		if (ch[0] == 'A'&&ch[1] == 'F') {
			scanf("%d", &data);
			getchar();
			if (deqnum==0) {
				rear = (ND *)malloc(sizeof(ND));
				rear->data = data;
				rear->next = NULL;
				rear->prev = NULL;
				front = rear;
			}
			else {
				add_front(front, data);
				front = front->prev;
			}
			deqnum++;
		}
		else if (ch[0] == 'A'&&ch[1] == 'R') {
			scanf("%d", &data);
			getchar();
			if (deqnum==0) {
				rear = (ND *)malloc(sizeof(ND));
				rear->data = data;
				rear->next = NULL;
				rear->prev = NULL;
				front = rear;
			}
			else {
				add_rear(rear, data);
				rear = rear->next;
			}
			deqnum++;
		}
		else if (ch[0] == 'D'&&ch[1] == 'F') {
			if (deqnum == 0) {
				printf("underflow\n");
				return 0;
			}
			if (deqnum == 1) {
				del = front;
				front = front->prev;
				rear = rear->next;
				free(del);
			}
			else {
				front = front->next;
				delete_front(front);
			}
			deqnum--;
		}
		else if (ch[0] == 'D'&&ch[1] == 'R') {
			if (deqnum == 0) {
				printf("underflow");
				return 0;
			}
			if (deqnum == 1) {
				del = rear;
				front = front->prev;
				rear = rear->next;
				free(del);
			}
			else {
				rear = rear->prev;
				delete_rear(rear);
			}
			deqnum--;
		}
		else if (ch[0] = 'P') {
			print(front);
		}
	}
}
void add_front(ND *q, int data) {
	ND *p;
	p = (ND *)malloc(sizeof(ND));
	p->data = data;
	p->next = q->prev;
	q->prev = p;
	p->next = q;
}
void add_rear(ND *q, int data) {
	ND *p;
	p = (ND *)malloc(sizeof(ND));
	p->data = data;
	p->next = q->next;
	q->next = p;
	p->prev = q;
}
int delete_front(ND *q) {
	ND *del;
	del = q->prev;
	q->prev = NULL;
	free(del);
}
int delete_rear(ND *q) {
	ND *del;
	del = q->next;
	q->next = NULL;
	free(del);
}
void print(ND *q) {
	while (q!= NULL) {
		printf(" %d", q->data);
		q = q->next;
	}
	printf("\n");
}