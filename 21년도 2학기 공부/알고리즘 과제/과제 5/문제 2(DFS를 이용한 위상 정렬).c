#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct IncidenceList{
    int vIndex;
    struct IncidenceList *next;
}IL;
typedef struct Vertex{
    char name;
    int visited;
    IL *uHeader;
    IL *wHeader;
}V;
typedef struct Graph{
    V vertices[10];
    int *topOrder;
    int n;
    int m;
    int cycle;
}G;
void insertVertex(G *graph, char vName, int ind);
void insertDirectedEdge(char uName, char wName, G *graph);
int Index(char vName, G graph);
void add(IL *header, int ind);
void rToplogicalSortDFS(G *graph, int ind);
int main(){
    int n, m,i;
    char s, ch;
    char u, w;
    G graph;
    scanf("%d %d %c",&n, &m, &s);
    graph.n = n;
    graph.m = m;
    graph.cycle=0;
    graph.topOrder = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        getchar();
        scanf("%c",&ch);
        insertVertex(&graph,ch,i);
        graph.topOrder[i]=-1;
    }
    for(i=0;i<m;i++){
        getchar();
        scanf("%c %c",&u,&w);
        insertDirectedEdge(u,w,&graph);
    }
    rToplogicalSortDFS(&graph,Index(s,graph));
    if(graph.cycle==1){
        printf("-1");
    }
    else{
        for(i=0;i<n;i++){
            printf("%c ",graph.vertices[graph.topOrder[i]].name);
        }
    }
    return 0;
}
void insertVertex(G *graph, char vName, int ind){
    graph->vertices[ind].name = vName;
    graph->vertices[ind].uHeader = (IL*)malloc(sizeof(IL));
    graph->vertices[ind].wHeader = (IL*)malloc(sizeof(IL));
    graph->vertices[ind].uHeader->next = NULL;
    graph->vertices[ind].wHeader->next = NULL;
    graph->vertices[ind].uHeader->vIndex = -1;
    graph->vertices[ind].wHeader->vIndex = -1;
    graph->vertices[ind].visited = 0;
}
void insertDirectedEdge(char uName, char wName, G *graph){
    int iu, iw;
    iu = Index(uName,*graph);
    iw = Index(wName,*graph);
    add(graph->vertices[iu].wHeader,iw); 
    add(graph->vertices[iw].uHeader,iu);
}
int Index(char vName, G graph){
    int i;
    for(i=0;i<graph.n;i++){
        if(graph.vertices[i].name==vName) return i;
    }
    return -1;
}
void add(IL *header, int ind){
    IL *new, *p;
    new = (IL*)malloc(sizeof(IL));
    new->vIndex = ind;
    p = header;
    while(p->next!=NULL){
        if(p->next->vIndex>ind) break;
        p=p->next;
    }
    new->next = p->next;
    p->next = new;
}
void rToplogicalSortDFS(G *graph, int ind){
    IL *p, *q;
    graph->vertices[ind].visited = 1; //¹æ¹®
    p = graph->vertices[ind].wHeader->next;
    q = graph->vertices[ind].uHeader->next;
    while(p!=NULL){
        if(graph->vertices[p->vIndex].visited==0){
            rToplogicalSortDFS(graph,p->vIndex);
        }
        else if(graph->topOrder[p->vIndex]==-1){
            graph->cycle=1;
            return;
        }
        p=p->next;
    }
    graph->topOrder[graph->n-1] = ind;
    graph->n--;
    printf("%d %c\n",graph->n,graph->vertices[ind].name);
}