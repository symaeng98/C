#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct IncidenceList{
    int vIndex;
    struct IncidenceList *next;
}IL;
typedef struct Vertex{
    char name;
    IL *uHeader;
    IL *wHeader;
}V;
typedef struct Graph{
    V vertices[100];
    int n;
    int m;
    int *in;
    int *topOrder;
    int *queue;
    int front, rear;
}G;
G buildGraph(G *graph);
G insertVertex(char vName, int ind, G *graph);
G insertDirectedEdge(char uName, char wName, int ind, G *graph);
int Index(char vName, G graph);
void addFirst(IL *header, int ind);
int *topologicalSort(G graph);
int isEmpty(G graph);
void enqueue(G *graph, V *vertice);
V *dequeue(G *graph);
int main(){
    G graph;
    int i;
    int *topOrder;
    graph = buildGraph(&graph);
    topOrder = topologicalSort(graph);
    if(topOrder[0]==0){
        printf("0\n");
    }
    else{
        for(i=1;i<graph.n+1;i++){
            printf("%c ",graph.vertices[topOrder[i]].name);
        }
    }
    return 0;
}
G buildGraph(G *graph){
    int i;
    char s,e;
    char ch;
    scanf("%d",&graph->n);
    getchar();
    for(i=0;i<graph->n;i++){
        scanf("%c",&ch);
        getchar();
        insertVertex(ch,i,graph);
    }
    scanf("%d",&graph->m);
    getchar();
    for(i=0;i<graph->m;i++){
        scanf("%c %c",&s,&e);
        getchar();
        insertDirectedEdge(s,e,i,graph);
    }
    graph->front = graph->rear = 0;
    graph->queue = (int*)malloc(sizeof(int)*graph->n);
    graph->topOrder = (int*)malloc(sizeof(int)*(graph->n+1));
    return *graph;
}
G insertVertex(char vName, int ind, G *graph){
    graph->vertices[ind].name = vName;
    graph->vertices[ind].uHeader = (IL*)malloc(sizeof(IL));
    graph->vertices[ind].wHeader = (IL*)malloc(sizeof(IL));
    graph->vertices[ind].uHeader->next=NULL;
    graph->vertices[ind].wHeader->next=NULL;
    graph->vertices[ind].uHeader->vIndex=-1;
    graph->vertices[ind].wHeader->vIndex=-1;
    return *graph;
}
G insertDirectedEdge(char uName, char wName, int ind, G *graph){
    int iu, iw;
    iu = Index(uName,*graph);
    iw = Index(wName,*graph);
    addFirst(graph->vertices[iu].wHeader,iw);
    addFirst(graph->vertices[iw].uHeader,iu);
}
int Index(char vName, G graph){
    int i;
    for(i=0;i<graph.n;i++){
        if(graph.vertices[i].name==vName) return i;
    }
    return -1;
}
void addFirst(IL *header, int ind){
    IL *new;
    new = (IL*)malloc(sizeof(IL));
    new->vIndex = ind;
    new->next = header->next;
    header->next = new;
}
int *topologicalSort(G graph);
int isEmpty(G graph);
void enqueue(G *graph, V *vertice);
V *dequeue(G *graph);