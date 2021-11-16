#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Edge{
    int start;
    int end;
    int type;//0이면 new, 1이면 tree, 2면 cross
}E;
typedef struct Vertex{
    int data;
    int visited;
}V;
typedef struct Graph{
    V vertices[100];
    E edge[1000];
    int matrix[100][100];
    int vNum; //정점 개수
}G;
void BFS(G *graph, int start);
int main(){
    int n, m, s;
    int start, end;
    int i,j;
    G graph;
    scanf("%d %d %d",&n,&m,&s);
    graph.vNum = n;
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1;
        graph.vertices[i].visited = 0; //fresh
        for(j=0;j<n;j++){
            graph.matrix[i][j] = -1; //초기화
        }
    }
    
    for(i=0;i<m;i++){
        scanf("%d %d",&start,&end);
        graph.edge[i].start = start-1;
        graph.edge[i].end = end-1;
        graph.edge[i].type = 0; //new
        graph.matrix[start-1][end-1] = i; //new
        graph.matrix[end-1][start-1] = i;
    }
    BFS(&graph, s);
    
    return 0;
}
void BFS(G *graph, int start){
    int front=0,i,j,rear=0;
    int index;
    int *queue;
    queue = (int*)malloc(sizeof(int)*(graph->vNum));
    queue[rear++] = start;
    graph->vertices[queue[i]-1].visited=1;
    while(front!=rear){
        for(i=front;i<rear;i++){
            printf("%d\n",graph->vertices[queue[i]-1].data);
        }
        j = rear;
        while(front!=j){
            for(i=0;i<graph->vNum;i++){
                index = graph->matrix[queue[front]-1][i];
                if(index!=-1){
                    if(graph->edge[index].start!=queue[i]-1&&graph->vertices[graph->edge[index].start].visited==0){ //start가 방문 안했으면    
                        graph->vertices[graph->edge[index].start].visited=1;
                        queue[rear++] = graph->vertices[graph->edge[index].start].data; //enqueue
                        graph->edge[index].type = 1;
                    }
                    else if(graph->edge[index].end!=queue[i]-1&&graph->vertices[graph->edge[index].end].visited==0){ //end가 방문 안헀으면
                        graph->vertices[graph->edge[index].end].visited=1;
                        queue[rear++] = graph->vertices[graph->edge[index].end].data; //enqueue
                        graph->edge[index].type = 1; //tree
                    }
                    else{
                        graph->edge[index].type = 2; //cross
                    }
                }
            }
            front++;
        }
    }
}