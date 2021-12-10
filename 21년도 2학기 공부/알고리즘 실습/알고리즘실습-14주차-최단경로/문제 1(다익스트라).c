#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct IncidenceList{
    struct IncidenceList *next;
    int vIndex;
    int weight;
}I;
typedef struct Vertex{
    int data;
    int distance;
    int visited;
    int locator;
    I *header;
}V;
typedef struct Graph{
    V vertices[100];
    V heap[101];
    int vNum;
    int num;
}G;
void upHeap(G *graph, int index);
void downHeap(G *graph, int index);
void push(G *graph, V data);
V pop(G *graph);
void DijikstraShortestPaths(G *graph, int sIndex);
I* getIL(int vIndex, int weight);
void swap(G *graph, int index1, int index2);
int main(){
    int n, m, s;
    int i;
    int v1, v2, w;
    I *p, *new, *q;
    G graph;
    scanf("%d %d %d",&n,&m,&s);
    graph.vNum = n;
    graph.num = 0;
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1;
        graph.vertices[i].distance = 1000000;
        graph.vertices[i].header = getIL(-1,-1);
        graph.vertices[i].locator = -1;
        graph.vertices[i].visited = 0;
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&v1, &v2, &w);
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
    DijikstraShortestPaths(&graph, s-1);
    for(i=0;i<graph.vNum;i++){
        if(graph.vertices[i].visited==0) continue;
        printf("%d %d\n",graph.vertices[i].data,graph.vertices[i].distance);
    }
    //free
    for(i=0;i<graph.vNum;i++){
        q = graph.vertices[i].header;
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
void upHeap(G *graph, int index){
    if(index==1) return;
    if(graph->heap[index].distance<graph->heap[index/2].distance){
        swap(graph,index,index/2);
        upHeap(graph,index/2);
    }
}
void downHeap(G *graph, int index){
    int min;
    if(index*2>graph->num) return;
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
void push(G *graph, V data){
    graph->num++;
    graph->heap[graph->num] = data;
    graph->vertices[data.data-1].locator = graph->num;
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
void DijikstraShortestPaths(G *graph, int sIndex){
    int i;
    V data;
    I *p;
    graph->vertices[sIndex].distance = 0;
    for(i=0;i<graph->vNum;i++){
        push(graph,graph->vertices[i]);
    }
    while(graph->num!=0){
        data = pop(graph);
        p = graph->vertices[data.data-1].header->next;
        while(p!=NULL){
            if(graph->vertices[p->vIndex].distance>p->weight+data.distance){
                graph->vertices[p->vIndex].distance = p->weight+data.distance;
                graph->heap[graph->vertices[p->vIndex].locator].distance = p->weight+data.distance;
                graph->vertices[p->vIndex].visited=1; //무한대에서 변경
                upHeap(graph,graph->vertices[p->vIndex].locator);
            }
            p=p->next;
        }
    }
}
I* getIL(int vIndex, int weight){
    I *new;
    new = (I*)malloc(sizeof(I));
    new->next = NULL;
    new->vIndex = vIndex;
    new->weight = weight;
    return new;
}
void swap(G *graph, int index1, int index2){
    V tmp;
    int tmp2;
    tmp = graph->heap[index1];
    graph->heap[index1] = graph->heap[index2];
    graph->heap[index2] = tmp;

    tmp2 = graph->vertices[graph->heap[index1].data-1].locator;
    graph->vertices[graph->heap[index1].data-1].locator = graph->vertices[graph->heap[index2].data-1].locator;
    graph->vertices[graph->heap[index2].data-1].locator = tmp2;
}