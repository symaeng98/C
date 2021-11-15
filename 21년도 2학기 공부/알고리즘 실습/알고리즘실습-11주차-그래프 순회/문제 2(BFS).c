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
}G;
void BFS(G *graph, int start);
void BFS1(G *graph, int start);
int main(){
    int n, m, s;
    int start, end;
    int i,j;
    G graph;
    scanf("%d %d %d",&n,&m,&s);
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1;
        graph.vertices[i].visited = 0; //fresh
        for(j=0;j<n;j++){
            graph.matrix[i][j] = -1; //초기화
        }
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&start,&end);
        graph.matrix[start-1][end-1] = 0; //new
        graph.matrix[end-1][start-1] = 0;
        graph.edge[] 
    }
    BFS(&graph, s);
    return 0;
}
void BFS(G *graph, int start){
    
}
void BFS1(G *graph, int start){

}