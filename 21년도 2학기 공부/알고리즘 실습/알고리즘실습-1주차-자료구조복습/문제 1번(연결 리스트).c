#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{ //Node 구조체
    char elem;
    struct Node *prev;
    struct Node *next;
}ND;
typedef struct Doubly_Linked_List{ //이중연결리스트 구조체
    ND *header;
    ND *trailer;
    int num; //연결되어있는 노드들의 개수 저장
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
    dll.header = (ND*)malloc(sizeof(ND)); //header와 trailer 동적할당
    dll.trailer = (ND*)malloc(sizeof(ND));
    dll.header->next = dll.trailer; //header의 next는 trailer를 가리키게 초기화
    dll.header->prev = NULL;
    dll.trailer->prev = dll.header; //trailer의 prev는 header를 가리키게 초기화
    dll.trailer->next = NULL; 
    dll.num = 0; //0으로 초기화

    scanf("%d",&N); //명령 횟수
    getchar();
    for(i=0;i<N;i++){
        scanf("%c",&ch);
        if(ch == 'A'){ //A면 
            scanf("%d",&rank); //rank(순위)와
            getchar();
            scanf("%c",&element); //element 입력받고
            getchar();
            if((rank>dll.num+1)||(rank<=0)){ //rank가 0보다 같거나 작거나 연결되어있는 노드 개수+1보다 크면, 예를 들면 아무것도 연결되어있지 않은데(num=0) rank가 2가 들어오는 경우
                printf("invalid position\n"); //invalid position 출력 후
                continue;
            }
            else{
                add(&dll,rank,element); //add함수 호출 (넘기는 인자는 dll의 주소)
            }
        }
        else if(ch == 'D'){
            scanf("%d",&rank); 
            getchar();
            if((rank>dll.num)||(rank<=0)){ //rank가 0보다 같거나 작거나 연결되어있는 노드 개수보다 크면,
                printf("invalid position\n"); //invalid position 출력 후
                continue;
            }
            else{
                delete(&dll, rank); //delete함수 호출
            }
        }
        else if(ch == 'G'){
            scanf("%d",&rank);
            getchar();
            if((rank>dll.num)||(rank<=0)){ //rank가 0보다 같거나 작거나 연결되어있는 노드 개수보다 크면,
                printf("invalid position\n"); //invalid position 출력 후
                continue;
            }
            else{
                printf("%c\n",get(&dll,rank)); //반환 값 확인
            }
        }
        else if(ch == 'P'){
            print(&dll); 
            getchar();
        }
        else{
            printf("입력 잘못됨\n");
        }
    }
    return 0;
}
void add(DLL *dll, int rank, char element){
    int i;
    ND *p, *new, *q;
    p = dll->header; //header부터 시작
    for(i=1;i<rank;i++){ //rank-1만큼 이동(rank가 1이면 이동하면 안됨)
        p = p->next;
    }
    q = p->next; //q는 p의 next 노드
    new = (ND*)malloc(sizeof(ND)); //삽입할 노드 생성
    new->elem = element; //element 저장
    p->next = new; //p가 가리키는 노드의 next는 new를 가리키고
    new->prev = p; //new의 prev는 p를 가리키게한다.
    q->prev = new; //q가 가리키는 노드의 prev는 new를 가리키고
    new->next = q; //new의 next는 q를 가리키게한다.
    dll->num += 1;
}
void delete(DLL *dll, int rank){
    int i;
    ND *p;
    p = dll->header; //header부터 시작
    for(i=0;i<rank;i++){ //rank만큼 이동(rank가 1이면 이동하면 안됨)
        p = p->next;
    }
    //현재 p는 삭제할 노드를 가리킴
    p->prev->next = p->next; //삭제할 노드의 이전 노드의 next가 삭제할 노드의 다음 노드를 가리키게한다.
    p->next->prev = p->prev; //반대로 삭제할 노드의 다음 노드의 prev가 삭제할 노드의 이전 노드를 가리키게한다.
    p->next = p->prev = NULL; //삭제할 노드의 prev와 next 모두 NULL값을 가리키고
    free(p);//삭제
    dll->num -= 1;
}
char get(DLL *dll, int rank){
    int i;
    ND *p;
    p = dll->header; //header부터 시작
    for(i=0;i<rank;i++){ //rank만큼 이동(rank가 1이면 이동하면 안됨)
        p = p->next;
    }
    return p->elem;
}
void print(DLL *dll){
    int i;
    ND *p;
    p = dll->header->next; //첫 번째 노드부터 시작
    while(p->next!=NULL){ //p가 trailer를 가리키지 않는 동안
        printf("%c",p->elem); //출력후
        p = p->next; //다음 노드를 가리킴
    }
    printf("\n");
}
//문제에서 순위 정보가 유요하지 않으면 "해당 연산을 무시한다"라고 했기 때문에
//invalid position을 판단하는 조건문을 함수 안에 넣지 않고 연산 자체를 건너뛰게함