#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{ //Node ����ü
    char elem;
    struct Node *prev;
    struct Node *next;
}ND;
typedef struct Doubly_Linked_List{ //���߿��Ḯ��Ʈ ����ü
    ND *header;
    ND *trailer;
    int num; //����Ǿ��ִ� ������ ���� ����
}DLL;

void add(DLL *dll, int rank, char element);
void delete(DLL *dll, int rank);
char get(DLL *dll, int rank);
void print(DLL *dll);

int main(){
    DLL dll;
    int N,i,rank;
    char element;
    char ch;
    dll.header = (ND*)malloc(sizeof(ND)); //header�� trailer �����Ҵ�
    dll.trailer = (ND*)malloc(sizeof(ND));
    dll.header->next = dll.trailer; //header�� next�� trailer�� ����Ű�� �ʱ�ȭ
    dll.header->prev = NULL;
    dll.trailer->prev = dll.header; //trailer�� prev�� header�� ����Ű�� �ʱ�ȭ
    dll.trailer->next = NULL; 
    dll.num = 0; //0���� �ʱ�ȭ

    scanf("%d",&N); //��� Ƚ��
    getchar();
    for(i=0;i<N;i++){
        scanf("%c",&ch);
        if(ch == 'A'){ //A�� 
            scanf("%d",&rank); //rank(����)��
            getchar();
            scanf("%c",&element); //element �Է¹ް�
            getchar();
            if((rank>dll.num+1)||(rank<=0)){ //rank�� 0���� ���ų� �۰ų� ����Ǿ��ִ� ��� ����+1���� ũ��, ���� ��� �ƹ��͵� ����Ǿ����� ������(num=0) rank�� 2�� ������ ���
                printf("invalid position\n"); //invalid position ��� ��
                continue;
            }
            else{
                add(&dll,rank,element); //add�Լ� ȣ�� (�ѱ�� ���ڴ� dll�� �ּ�)
            }
        }
        else if(ch == 'D'){
            scanf("%d",&rank); 
            getchar();
            if((rank>dll.num)||(rank<=0)){ //rank�� 0���� ���ų� �۰ų� ����Ǿ��ִ� ��� �������� ũ��,
                printf("invalid position\n"); //invalid position ��� ��
                continue;
            }
            else{
                delete(&dll, rank); //delete�Լ� ȣ��
            }
        }
        else if(ch == 'G'){
            scanf("%d",&rank);
            getchar();
            if((rank>dll.num)||(rank<=0)){ //rank�� 0���� ���ų� �۰ų� ����Ǿ��ִ� ��� �������� ũ��,
                printf("invalid position\n"); //invalid position ��� ��
                continue;
            }
            else{
                printf("%c\n",get(&dll,rank)); //��ȯ �� Ȯ��
            }
        }
        else if(ch == 'P'){
            print(&dll); 
            getchar();
        }
        else{
            printf("�Է� �߸���\n");
        }
    }
    return 0;
}
void add(DLL *dll, int rank, char element){
    int i;
    ND *p, *new, *q;
    p = dll->header; //header���� ����
    for(i=1;i<rank;i++){ //rank-1��ŭ �̵�(rank�� 1�̸� �̵��ϸ� �ȵ�)
        p = p->next;
    }
    q = p->next; //q�� p�� next ���
    new = (ND*)malloc(sizeof(ND)); //������ ��� ����
    new->elem = element; //element ����
    p->next = new; //p�� ����Ű�� ����� next�� new�� ����Ű��
    new->prev = p; //new�� prev�� p�� ����Ű���Ѵ�.
    q->prev = new; //q�� ����Ű�� ����� prev�� new�� ����Ű��
    new->next = q; //new�� next�� q�� ����Ű���Ѵ�.
    dll->num += 1;
}
void delete(DLL *dll, int rank){
    int i;
    ND *p;
    p = dll->header; //header���� ����
    for(i=0;i<rank;i++){ //rank��ŭ �̵�(rank�� 1�̸� �̵��ϸ� �ȵ�)
        p = p->next;
    }
    //���� p�� ������ ��带 ����Ŵ
    p->prev->next = p->next; //������ ����� ���� ����� next�� ������ ����� ���� ��带 ����Ű���Ѵ�.
    p->next->prev = p->prev; //�ݴ�� ������ ����� ���� ����� prev�� ������ ����� ���� ��带 ����Ű���Ѵ�.
    p->next = p->prev = NULL; //������ ����� prev�� next ��� NULL���� ����Ű��
    free(p);//����
    dll->num -= 1;
}
char get(DLL *dll, int rank){
    int i;
    ND *p;
    p = dll->header; //header���� ����
    for(i=0;i<rank;i++){ //rank��ŭ �̵�(rank�� 1�̸� �̵��ϸ� �ȵ�)
        p = p->next;
    }
    return p->elem;
}
void print(DLL *dll){
    int i;
    ND *p;
    p = dll->header->next; //ù ��° ������ ����
    while(p->next!=NULL){ //p�� trailer�� ����Ű�� �ʴ� ����
        printf("%c",p->elem); //�����
        p = p->next; //���� ��带 ����Ŵ
    }
    printf("\n");
}
//�������� ���� ������ �������� ������ "�ش� ������ �����Ѵ�"��� �߱� ������
//invalid position�� �Ǵ��ϴ� ���ǹ��� �Լ� �ȿ� ���� �ʰ� ���� ��ü�� �ǳʶٰ���