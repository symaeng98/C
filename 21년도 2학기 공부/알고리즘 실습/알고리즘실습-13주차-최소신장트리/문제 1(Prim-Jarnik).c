#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct IncidenceList{
    struct IncidenceList *next;
    int end;
    int type; //간선의 타입(0이면 new, 1이면 tree, 2면 back)
    int weight;
}I;
typedef struct Vertex{
    int data;
    int visited;
    int distance;
    int position;
    I *link;
}V;
typedef struct Graph{
    V vertices[100];
    V heap[100];
    int vNum;
    int num;
}G;
I *getIL(int end, int weight);
void insertEdge(G *graph, int start, int end, int weight);
void push(G *graph, V *vertex);
V pop(G *graph);
void upHeap(G *graph, int index);
void downHeap(G *graph, int index);
void swap(G *graph, int index1, int index2);
void PrimJarnikMST(G *graph, int start);
int Index(G graph, int data);
int main(){
    int n, m;
    int start, end, weight;
    int i;
    G graph;
    I *p, *q;
    scanf("%d %d",&n,&m);
    graph.vNum = n;
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1; //index 0부터 1씩 들어감
        graph.vertices[i].visited = 0; 
        graph.vertices[i].link = getIL(-1,-1);
        graph.vertices[i].distance = 100000; //보류
        graph.vertices[i].position = 0;
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&start,&end, &weight);
        insertEdge(&graph,start,end, weight);
    }
    graph.heap[0].distance=-1;
    graph.num=0;
    PrimJarnikMST(&graph,0);
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
void insertEdge(G *graph, int start, int end, int weight){
    I *new, *new2, *p;
    new = getIL(end, weight);
    p = graph->vertices[start-1].link;
    while(p->next!=NULL&&p->next->end<end){
        p=p->next;
    }
    new->next = p->next;
    p->next = new;

    if(start!=end){
        new2 = getIL(start, weight);
        p = graph->vertices[end-1].link;
        while(p->next!=NULL&&p->next->end<start){
            p=p->next;
        }
        new2->next = p->next;
        p->next = new2;
    }

}
I *getIL(int end, int weight){
    I *new;
    new = (I*)malloc(sizeof(I));
    new->weight = weight;
    new->end = end;
    new->type = 0;
    new->next = NULL;
    return new;
}
void upHeap(G *graph, int index){
    if(index==1) return;
    if(graph->heap[index].distance<graph->heap[index/2].distance){
        swap(graph,index,index/2);
        upHeap(graph,index/2);
    }
    else return;
}
void downHeap(G *graph, int index){
    int min;
    if(index*2>graph->num) return;
    if(index*2==graph->num){
        if(graph->heap[index].distance>graph->heap[index*2].distance){
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
            swap(graph,min,index);
            downHeap(graph,min);
        }
    }
}
void swap(G *graph, int index1, int index2){
    V tmp;
    tmp = graph->heap[index1];
    graph->heap[index2] = graph->heap[index1];
    graph->heap[index1] = tmp;
}
void push(G *graph, V *vertex){
    graph->num++;
    graph->heap[graph->num] =  *vertex;
    upHeap(graph,graph->num);
    vertex->position = Index(*graph,vertex->data);
}
int Index(G graph, int data){
    int i;
    for(i=1;i<=graph.num;i++){
        if(graph.heap[i].data==data) return i;
    }
}
V pop(G *graph){
    V data;
    data = graph->heap[1];
    graph->heap[1] = graph->heap[graph->num];
    graph->num--;
    downHeap(graph,1);
    return data;
}
void PrimJarnikMST(G *graph, int start){
    int i;
    V u;
    I *p;
    graph->vertices[start].distance = 0;
    for(i=0;i<graph->vNum;i++){
        push(graph,&graph->vertices[i]);
    }
    while(graph->num!=0){
        u = pop(graph);
        // printf(" %d",u.data);
        u.visited=1;//pop처리
        p = u.link->next;
        while(p!=NULL){
            if(graph->vertices[p->end].visited==0&&p->weight<graph->heap[graph->vertices[p->end].position].distance){
                graph->heap[graph->vertices[p->end].position].distance = p->weight;
                upHeap(graph,graph->vertices[p->end].position);
                graph->vertices[p->end].position = Index(*graph,graph->vertices[p->end].data);
            }
            p=p->next;
        }
        for(i=1;i<=graph->num;i++) printf("%d ",graph->heap[i].distance);
        printf("\n");
    }
}