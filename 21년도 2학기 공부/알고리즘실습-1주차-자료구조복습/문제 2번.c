#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{ //Node 구조체
    int data;
    struct Node *left;
    struct Node *right;
}ND;
typedef struct Tree{ //트리 구조체
    ND *header;
}T;
void add_left_child(ND *p, int data);
void add_right_child(ND *p, int data);
ND* make_tree(ND *p, int data);
int main(){
    T tree;
    ND *p, *q;
    int N, i,j;
    int left, right, data;
    char ch[101];

    tree.header = (ND*)malloc(sizeof(ND));
    p = tree.header; //p는 header를 가리킨다.
    p->left = NULL; //root의 left와 right를 NULL로 초기화
    p->right = NULL;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d %d",&data,&left,&right);
        if(i==0){ //첫 시행때는 정보가 없으므로 root에 값을 붙여줘야한다.
            add_left_child(p,data); //root노드 생성
            p = p->left; //root노드로 이동
            if(left!=0){ //NULL이 아니면
                add_left_child(p,left); //leftchild 연결
            }
            if(right!=0){
                add_right_child(p,right); //rightchild 연결 
            }
        }
        else{ //두 번째 시행부터
            q = make_tree(p, data); //q는 make_tree함수에서 반환된 값을 가리킴
            if(left!=0){
                add_left_child(q,left);
            }
            if(right!=0){
                add_right_child(q,right);
            }
        }
        p = tree.header->left; //입력때마다 root에서 시작
    }
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        p = tree.header->left;
        scanf("%s",ch); //탐색 정보 입력
        getchar();
        printf(" %d",p->data);
        for(j=0;j<strlen(ch);j++){ //ch의 길이만큼 반복
            if(ch[j]=='R'){ //R이면
                p = p->right; //rightchild로 이동
            }
            else{ //L이면
                p = p->left; //leftchild로 이동
            }
            printf(" %d",p->data);
        }
        printf("\n");
    }
    return 0;
}
void add_left_child(ND *p, int data){ //leftchild 연결 함수
    ND *q;
    q = (ND*)malloc(sizeof(ND));
    q->data = data;
    q->left = q->right = NULL; //NULL로 초기화
    p->left = q;
}
void add_right_child(ND *p, int data){ //rightchild 연결 함수
    ND *q;
    q = (ND*)malloc(sizeof(ND));
    q->data = data;
    q->left = q->right = NULL;
    p->right = q;
}
ND* make_tree(ND *p, int data){
    ND *tmp;
    if(p==NULL){ //p가 NULL값이면, (재귀함수이므로 left나 right로 계속 순회중에 값이 NULL이면)
        return NULL; //NULL값 return
    }
    if(p->data==data && p->left==NULL && p->right==NULL){ //leftchild와 rightchild를 연결해줘야할 데이터를 찾았으면,
        return p; //그 데이터를 가리키는 포인터 p 반환
    }
    tmp = make_tree(p->left,data); //tmp를 선언하지않으면 재귀함수를 빠져나올 때 값을 잃는다.
    if(tmp!=NULL){ //tmp에 NULL값이 아닌 찾으려고하는 데이터를 가리키는 포인터가 들어있으면
        return tmp; //tmp반환
    }
    tmp = make_tree(p->right,data); //같은 방식으로 right로 계속 순회
    if(tmp!=NULL){
        return tmp;
    }
    return NULL;
}