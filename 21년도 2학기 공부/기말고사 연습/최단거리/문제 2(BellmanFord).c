#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Edge{
    int start;
    int end;
    int weight;
}E;
typedef struct Vertex{
    int data;
    int visited;
    int distance;
}V;
typedef struct Graph{
    V vertices[100];
    E edge[1000];
    int vNum;
    int eNum;
}G;
void bellmanFord(G *graph, int sIndex);
int main(){
    int n,m,s,i;
    int v1,v2,w;
    G graph;
    scanf("%d %d %d",&n,&m,&s);
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1;
        graph.vertices[i].distance = 100000;
        graph.vertices[i].visited = 0;
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        graph.edge[i].start = v1-1;
        graph.edge[i].end = v2-1;
        graph.edge[i].weight = w;
    }
    graph.vNum = n;
    graph.eNum = m;
    bellmanFord(&graph, s-1);
    for(i=0;i<n;i++){
        if(graph.vertices[i].visited==0||i==s-1) continue;
        printf("%d %d\n",graph.vertices[i].data,graph.vertices[i].distance);
    }
    return 0;
}
void bellmanFord(G *graph, int sIndex){
    int i,j;
    int start;
    int end;
    graph->vertices[sIndex].distance = 0;
    graph->vertices[sIndex].visited = 1;
    for(i=0;i<graph->vNum-1;i++){
        for(j=0;j<graph->eNum;j++){
            start = graph->edge[j].start;
            end = graph->edge[j].end;
            if(graph->vertices[start].distance==100000&&graph->vertices[end].distance==100000) continue;
            if(graph->vertices[end].distance>graph->vertices[start].distance+graph->edge[j].weight){
                graph->vertices[end].distance=graph->vertices[start].distance+graph->edge[j].weight;
                graph->vertices[end].visited = 1;
            }
        }
    }
}