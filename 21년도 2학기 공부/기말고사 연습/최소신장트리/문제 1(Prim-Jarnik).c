#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct IncidenceList{
    int vIndex;
    struct IncidenceList *next;
    int weight;
}IL;
typedef struct Vertex{
    int data;
    int locator;
    int visited;
    int distance;
    IL *header;
}V;
typedef struct Graph{
    V vertices[100];
    V heap[101];
    int vNum;
    int num;
}G;
IL* getIL(G *graph,int vIndex, int weight);
void upHeap(G *graph, int index);
void downHeap(G *graph, int index);
void swap(G *graph, int index1, int index2);
void push(G *graph, V vertices);
void prim_Jarnik(G *graph);
V pop(G *graph);
int main(){
    int n, m;
    int i;
    int v1,v2,w;
    G graph;
    IL *p, *new;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        graph.vertices[i].visited = 0;
        graph.vertices[i].locator = -1;
        graph.vertices[i].header = getIL(&graph,-1,-1);
        graph.vertices[i].data = i+1;
        graph.vertices[i].distance = 100000;
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        //v1
        p = graph.vertices[v1-1].header;
        while(p->next!=NULL&&p->next->vIndex<v2-1){
            p=p->next;
        }
        new = getIL(&graph,v2-1,w);
        new->next = p->next;
        p->next = new;
        //v2
        p = graph.vertices[v2-1].header;
        while(p->next!=NULL&&p->next->vIndex<v1-1){
            p=p->next;
        }
        new = getIL(&graph,v1-1,w);
        new->next = p->next;
        p->next = new;
    }
    graph.vNum = n;
    graph.num = 0;
    prim_Jarnik(&graph);
    return 0;
}
IL* getIL(G *graph, int vIndex, int weight){
    IL *new;
    new = (IL*)malloc(sizeof(IL));
    new->next = NULL;
    new->vIndex = vIndex;
    new->weight = weight;
    return new;
}
void upHeap(G *graph, int index){
    if(index==1){
        return;
    }
    if(graph->heap[index].distance<graph->heap[index/2].distance){
        swap(graph,index,index/2);
        upHeap(graph,index/2);
    }
}
void downHeap(G *graph, int index){
    int min;
    if(index*2>graph->num){
        return;
    }
    else if(index*2==graph->num){
        if(graph->heap[index*2].distance<graph->heap[index].distance){
            swap(graph,index,index*2);
            downHeap(graph,index*2);
        }
    }
    else{
        if(graph->heap[index*2].distance<graph->heap[index*2+1].distance){
            min = index*2;
        }
        else min = index*2+1;
        if(graph->heap[min].distance<graph->heap[index].distance){
            swap(graph,index,min);
            downHeap(graph,min);
        }
    }
}
void swap(G *graph, int index1, int index2){
    V tmp;
    int tmpL;
    tmp = graph->heap[index1];
    graph->heap[index1] = graph->heap[index2];
    graph->heap[index2] = tmp;

    tmpL = graph->vertices[graph->heap[index1].data-1].locator;
    graph->vertices[graph->heap[index1].data-1].locator = graph->vertices[graph->heap[index2].data-1].locator;
    graph->vertices[graph->heap[index2].data-1].locator = tmpL;
}
void push(G *graph, V vertices){
    graph->num++;
    graph->heap[graph->num] = vertices;
    graph->vertices[vertices.data-1].locator = graph->num;
    upHeap(graph, graph->num);
}
V pop(G *graph){
    V data;
    data = graph->heap[1];
    graph->heap[1] = graph->heap[graph->num];
    graph->vertices[graph->heap[graph->num].data-1].locator = 1;
    graph->num--;
    downHeap(graph,1);
    return data;
}
void prim_Jarnik(G *graph){
    int i, sum=0;
    V data;
    IL *p;
    graph->vertices[0].distance=0;
    for(i=0;i<graph->vNum;i++){
        push(graph, graph->vertices[i]);
    }
    while(graph->num!=0){
        data = pop(graph);
        printf(" %d",data.data);
        sum += data.distance;
        graph->vertices[data.data-1].visited=1;
        p = graph->vertices[data.data-1].header->next;
        while(p!=NULL){
            if(graph->vertices[p->vIndex].visited==0&&graph->heap[graph->vertices[p->vIndex].locator].distance>p->weight){
                graph->heap[graph->vertices[p->vIndex].locator].distance=p->weight;
                graph->vertices[p->vIndex].distance = p->weight;
                upHeap(graph,graph->vertices[p->vIndex].locator);
            }
            p=p->next;
        }
    }
    printf("\n");
    printf("%d",sum);
}