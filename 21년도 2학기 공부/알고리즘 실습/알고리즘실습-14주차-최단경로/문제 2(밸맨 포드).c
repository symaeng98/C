#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Edge{
    int startIndex;
    int endIndex;
    int weight;
}E;
typedef struct Vertex{
    int data;
    int distance;
    int visited;
}V;
typedef struct Graph{
    V vertices[100];
    E edge[1000];
    int vNum;
    int eNum;
}G;
void BellmanFordShortestPaths(G *graph, int sIndex);
void swap(G *graph, int index1, int index2);
int main(){
    int n, m, s;
    int i;
    int v1, v2, w;
    G graph;
    scanf("%d %d %d",&n,&m,&s);
    graph.vNum = n;
    graph.eNum = m;
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1;
        graph.vertices[i].distance = 1000000;
        graph.vertices[i].visited = 0;
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&v1, &v2, &w);
        graph.edge[i].startIndex = v1-1;
        graph.edge[i].endIndex = v2-1;
        graph.edge[i].weight = w;
    }
    BellmanFordShortestPaths(&graph, s-1);
    for(i=0;i<graph.vNum;i++){
        if(graph.vertices[i].visited==0) continue;
        printf("%d %d\n",graph.vertices[i].data,graph.vertices[i].distance);
    }
    return 0;
}
void BellmanFordShortestPaths(G *graph, int sIndex){
    int i;
    int j;
    int start;
    int end;
    graph->vertices[sIndex].distance = 0;
    for(i=0;i<graph->vNum-1;i++){
        for(j=0;j<graph->eNum;j++){
            start = graph->edge[j].startIndex;
            end = graph->edge[j].endIndex;
            if(graph->vertices[end].distance==1000000&&graph->vertices[start].distance==1000000) continue; //둘다 무한대 무시
            if(graph->vertices[end].distance>graph->vertices[start].distance+graph->edge[j].weight){
                graph->vertices[end].distance = graph->vertices[start].distance+graph->edge[j].weight;
                graph->vertices[end].visited = 1;
            }
        }
    }
}