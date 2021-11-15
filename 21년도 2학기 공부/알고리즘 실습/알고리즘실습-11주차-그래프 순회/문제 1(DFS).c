#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct IncidenceList{
    struct IncidenceList *next;
    int end;
    int type; //간선의 타입(0이면 new, 1이면 tree, 2면 back)
    // int weight;
}I;
typedef struct Vertex{
    int data;
    int visited;
    I *link;
}V;
typedef struct Graph{
    V vertices[100];
}G;
I *getIL(int end);
void insertEdge(G *graph, int start, int end);
void DFS(G *graph, int start);
int main(){
    int n, m, s;
    int start, end;
    int i;
    G graph;
    I *p, *q;
    scanf("%d %d %d",&n,&m,&s);
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1; //index 0부터 1씩 들어감
        graph.vertices[i].visited = 0; //fresh
        graph.vertices[i].link = getIL(-1);
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&start,&end);
        insertEdge(&graph,start,end);
    }
    DFS(&graph,s);
    //free
    for(i=0;i<n;i++){
        q = graph.vertices[i].link;
        p = q->next;
        while(p!=NULL){
            q->next = p->next;
            free(p);
            p = q->next;
        }
        free(q);
    }
    return 0;
}
void insertEdge(G *graph, int start, int end){
    I *new, *new2, *p;
    new = getIL(end);
    p = graph->vertices[start-1].link;
    while(p->next!=NULL&&p->next->end<end){
        p=p->next;
    }
    new->next = p->next;
    p->next = new;

    if(start!=end){
        new2 = getIL(start);
        p = graph->vertices[end-1].link;
        while(p->next!=NULL&&p->next->end<start){
            p=p->next;
        }
        new2->next = p->next;
        p->next = new2;
    }

}
I *getIL(int end){
    I *new;
    new = (I*)malloc(sizeof(I));
    new->end = end;
    new->type = 0;
    new->next = NULL;
    return new;
}
void DFS(G *graph, int start){
    I *p;
    graph->vertices[start-1].visited = 1;
    printf("%d\n",graph->vertices[start-1].data);
    p = graph->vertices[start-1].link->next;
    while(p!=NULL){
        if(graph->vertices[p->end-1].visited==0){
            p->type = 1; //tree
            DFS(graph,p->end);
        }
        else p->type = 2; //back
        p=p->next;
    }
    return;
}  