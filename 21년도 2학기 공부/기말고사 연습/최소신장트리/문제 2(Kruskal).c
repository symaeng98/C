#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Edge{
    int weight;
    int v1Index;
    int v2Index;
}E;
typedef struct Vertex{
    int data;
    int sack;
}V;
typedef struct Graph{
    V vertices[100];
    E heap[1010];
    E edge[1001];
    int num;
    int eNum;
    int vNum;
}G;
void upHeap(G *graph, int index);
void downHeap(G *graph, int index);
void push(G *graph, E edge);
E pop(G *graph);
void swap(G *graph, int index1, int index2);
void kruskal(G *graph);
int main(){
    int n, m, i;
    int v1,v2,w;
    G graph;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1;
        graph.vertices[i].sack = -1;
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        graph.edge[i].v1Index = v1-1;
        graph.edge[i].v2Index = v2-1;
        graph.edge[i].weight = w;
    }
    graph.num = 0;
    graph.eNum = m;
    graph.vNum = n;
    kruskal(&graph);
    return 0;
}
void upHeap(G *graph, int index){
    if(index==1) return;
    if(graph->heap[index].weight < graph->heap[index/2].weight){
        swap(graph,index,index/2);
        upHeap(graph, index/2);
    }
}
void downHeap(G *graph, int index){
    if(index*2>graph->num) return;
    else if(index*2==graph->num){
        if(graph->heap[index*2].weight<graph->heap[index].weight){
            swap(graph,index,index*2);
            downHeap(graph,index*2);
        }
    }
    else{
        int min;
        if(graph->heap[index*2].weight<graph->heap[index*2+1].weight) min = index*2;
        else min = index*2+1;
        if(graph->heap[min].weight<graph->heap[index].weight){
            swap(graph,index,min);
            downHeap(graph,min);
        }
    }
}
void push(G *graph, E edge){
    graph->num++;
    graph->heap[graph->num] = edge;
    upHeap(graph,graph->num);
}
E pop(G *graph){
    E data;
    data = graph->heap[1];
    graph->heap[1] = graph->heap[graph->num];
    graph->num--;
    downHeap(graph,1);
    return data;
}
void kruskal(G *graph){
    E data;
    int sackType=0;
    int sackNum[1000];
    int i, sum=0;
    int save;
    for(i=0;i<1000;i++) sackNum[i] = 0;
    for(i=0;i<graph->eNum;i++){
        push(graph, graph->edge[i]);
    }
    while(graph->num!=0){
        data = pop(graph);
        if(graph->vertices[data.v1Index].sack==-1&&graph->vertices[data.v2Index].sack==-1){
            graph->vertices[data.v1Index].sack = sackType;
            graph->vertices[data.v2Index].sack = sackType;
            sackNum[sackType] += 2;
            sackType++;
            sum+=data.weight;
            printf(" %d",data.weight);
        }
        else if(graph->vertices[data.v1Index].sack==-1&&graph->vertices[data.v2Index].sack!=-1){
            graph->vertices[data.v1Index].sack = graph->vertices[data.v2Index].sack;
            sackNum[graph->vertices[data.v2Index].sack]++;
            sum+=data.weight;
            printf(" %d",data.weight);
        }
        else if(graph->vertices[data.v2Index].sack==-1&&graph->vertices[data.v1Index].sack!=-1){
            graph->vertices[data.v2Index].sack = graph->vertices[data.v1Index].sack;
            sackNum[graph->vertices[data.v1Index].sack]++;
            sum += data.weight;
            printf(" %d",data.weight);
        }
        else{ //둘 다 있음
            if(graph->vertices[data.v1Index].sack!=graph->vertices[data.v2Index].sack){
                if(sackNum[graph->vertices[data.v1Index].sack]<sackNum[graph->vertices[data.v2Index].sack]){
                    sackNum[graph->vertices[data.v2Index].sack] += sackNum[graph->vertices[data.v1Index].sack];
                    sackNum[graph->vertices[data.v1Index].sack] = 0;
                    save = graph->vertices[data.v1Index].sack;
                    for(i=0;i<graph->vNum;i++){
                        if(graph->vertices[i].sack==save){
                            graph->vertices[i].sack = graph->vertices[data.v2Index].sack;
                        }
                    }
                }
                else {
                    sackNum[graph->vertices[data.v1Index].sack] += sackNum[graph->vertices[data.v2Index].sack];
                    sackNum[graph->vertices[data.v2Index].sack] = 0;
                    save = graph->vertices[data.v2Index].sack;
                    for(i=0;i<graph->vNum;i++){
                        if(graph->vertices[i].sack==save){
                            graph->vertices[i].sack = graph->vertices[data.v1Index].sack;
                        }
                    }
                }
                sum+=data.weight;
                printf(" %d",data.weight);
            }
        }
    }
    printf("\n");
    printf("%d",sum);
}
void swap(G *graph, int index1, int index2){
    E tmp;
    tmp = graph->heap[index1];
    graph->heap[index1] = graph->heap[index2];
    graph->heap[index2] = tmp;
}