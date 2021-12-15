#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct IncidenceList{
    struct IncidenceList *next;
    int weight;
    int vIndex;
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
    int num;
    int vNum;
}G;
void upHeap(G *graph, int index);
void downHeap(G *graph, int index);
void push(G *graph, V vertex);
V pop(G *graph);
void swap(G *graph, int index1, int index2);
IL* getIL(int vIndex, int weight);
void djikstra(G *graph, int sIndex);
int main(){
    int n, m, s, i;
    int v1,v2,w;
    IL *p, *new;
    G graph;
    scanf("%d %d %d",&n,&m,&s);
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1;
        graph.vertices[i].locator = -1;
        graph.vertices[i].visited = 0;
        graph.vertices[i].distance = 100000;
        graph.vertices[i].header = getIL(-1,-1);
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        p = graph.vertices[v1-1].header;
        while(p->next!=NULL&&p->next->vIndex<v2-1){
            p=p->next;
        }
        new = getIL(v2-1,w);
        new->next = p->next;
        p->next = new;

        p = graph.vertices[v2-1].header;
        while(p->next!=NULL&&p->next->vIndex<v1-1){
            p=p->next;
        }
        new = getIL(v1-1,w);
        new->next = p->next;
        p->next = new;
    }
    graph.num = 0;
    graph.vNum = n;
    djikstra(&graph, s-1);
    for(i=0;i<n;i++){
        if(graph.vertices[i].visited==0||i==s-1) continue;
        printf("%d %d\n",graph.vertices[i].data,graph.vertices[i].distance);
    }
    return 0;
}
void upHeap(G *graph, int index){
    if(index==1) return;
    if(graph->heap[index].distance<graph->heap[index/2].distance){
        swap(graph,index,index/2);
        upHeap(graph,index/2);
    }
}
void downHeap(G *graph, int index){
    if(index*2>graph->num) return;
    if(index*2==graph->num){
        if(graph->heap[index].distance>graph->heap[index*2].distance){
        swap(graph,index,index*2);
        downHeap(graph,index*2);
        }
    }
    else{
        int min;
        if(graph->heap[index*2+1].distance>graph->heap[index*2].distance) min = index*2;
        else min = index*2+1;
        if(graph->heap[index].distance>graph->heap[min].distance){
            swap(graph,index,min);
            downHeap(graph,min);
        }
    }
}
void push(G *graph, V vertex){
    graph->num++;
    graph->heap[graph->num] = vertex;
    graph->vertices[graph->heap[graph->num].data-1].locator = graph->num;
    upHeap(graph,graph->num);
}
V pop(G *graph){
    V data;
    data = graph->heap[1];
    graph->heap[1] = graph->heap[graph->num];
    graph->vertices[graph->heap[1].data-1].locator = 1;
    graph->num--;
    downHeap(graph,1);
    return data;
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
IL* getIL(int vIndex, int weight){
    IL *new;
    new = (IL*)malloc(sizeof(IL));
    new->next = NULL;
    new->vIndex = vIndex;
    new->weight = weight;
    return new;
}
void djikstra(G *graph, int sIndex){
    V data;
    int i;
    IL *p;
    graph->vertices[sIndex].distance = 0;
    graph->vertices[sIndex].visited = 1;
    for(i=0;i<graph->vNum;i++){
        push(graph, graph->vertices[i]);
    }
    while(graph->num!=0){
        data = pop(graph);
        p = graph->vertices[data.data-1].header->next;
        while(p!=NULL){
            if(graph->vertices[p->vIndex].distance>data.distance+p->weight){
                graph->vertices[p->vIndex].distance = data.distance+p->weight;
                graph->heap[graph->vertices[p->vIndex].locator].distance = data.distance+p->weight;
                graph->vertices[p->vIndex].visited=1;
                upHeap(graph, graph->vertices[p->vIndex].locator);
            }
            p=p->next;
        }
    }
}