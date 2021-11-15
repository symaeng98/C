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
    int sum=0,b,ss;
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
        if(start>end){
            b = start;
            ss = end;
        }
        else{
            b = end;
            ss = start;
        }
        for(j=0;j<b-1;j++){
            sum+=n-j;
        }
        sum += (b-ss); //sum은 edge의 index
        graph.edge[sum].start = start-1;
        graph.edge[sum].end = end-1;
        graph.edge[sum].type = 0; //new
        graph.matrix[start-1][end-1] = sum; //new
        graph.matrix[end-1][start-1] = sum;
    }
    BFS(&graph, s);
    return 0;
}
void BFS(G *graph, int start){
    int i,p,j, index,q,a;
    int *list,k=0;
    list = (int*)malloc(sizeof(int)*graph->vNum);
    p = k;
    list[k++] = start;
    q = k;
    graph->vertices[start-1].visited = 1;
    printf("%d\n",graph->vertices[start-1].data);
    while(k<graph->vNum){
        a = k;
        for(i=p;i<q;i++){
            for(j=0;j<graph->vNum;j++){
                index = graph->matrix[list[i]-1][j];
                if(index!=-1){
                    if(graph->edge[index].start!=list[i]-1&&graph->vertices[graph->edge[index].start].visited!=1){
                        graph->vertices[graph->edge[index].start].visited = 1;
                        graph->edge[index].type = 1;
                        printf("%d\n",graph->vertices[graph->edge[index].start].data);
                        list[k++] = graph->edge[index].start+1;
                    }
                    else if(graph->edge[index].end!=list[i]-1&&graph->vertices[graph->edge[index].end].visited!=1){
                        graph->vertices[graph->edge[index].end].visited = 1;
                        graph->edge[index].type = 1;
                        printf("%d\n",graph->vertices[graph->edge[index].end].data);
                        list[k++] = graph->edge[index].end+1;
                    }
                    graph->edge[index].type = 2;
                }
            }
        }
        q = k;
        p = a;  
    }
    free(list);
}