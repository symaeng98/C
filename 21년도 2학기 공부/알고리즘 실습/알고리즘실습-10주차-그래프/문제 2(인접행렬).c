#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Vertex{
    int data;
}V;
typedef struct Edge{
    int start;
    int end;
    int weight;
}E;
typedef struct graph{
    V vertices[6];
    E edges[21];
    int matrix[6][6];
}G;
void insertVertex(G *graph, int data);
void insertEdge(G *graph, int start, int end, int weight);
void adjacent(G graph, int data);
void modify(G *graph, int start, int end, int weight);
int main(){
    G graph;
    char ch;
    int data, i, start, end, weight, j;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            graph.matrix[i][j] = -1;
        }
    }
    insertVertex(&graph, 1);
    insertVertex(&graph, 2);
    insertVertex(&graph, 3);
    insertVertex(&graph, 4);
    insertVertex(&graph, 5);
    insertVertex(&graph, 6);
    insertEdge(&graph, 1, 2, 1);
    insertEdge(&graph, 1, 3, 1);
    insertEdge(&graph, 1, 4, 1);
    insertEdge(&graph, 1, 6, 2);
    insertEdge(&graph, 2, 3, 1);
    insertEdge(&graph, 3, 5, 4);
    insertEdge(&graph, 5, 5, 4);
    insertEdge(&graph, 5, 6, 3);
    while(1){
        scanf("%c",&ch);
        if(ch=='a'){
            scanf("%d",&data);
            getchar();
            adjacent(graph, data);
        }
        else if(ch=='m'){
            scanf("%d %d %d",&start,&end,&weight);
            getchar();
            modify(&graph,start, end, weight);
        }
        else if(ch=='q'){
            break;
        }
        else{
            printf("입력이 잘못됨\n");
        }
    }
    return 0;
}
void insertVertex(G *graph, int data){
    graph->vertices[data-1].data = data;
}
void insertEdge(G *graph, int start, int end, int weight){
    int i, k=6, sum=0, edgeIndex;
    for(i=0;i<start-1;i++){
        sum += k-i;
    }
    edgeIndex = end-start+sum;
    graph->edges[edgeIndex].start = start-1; //index 생각
    graph->edges[edgeIndex].end = end-1;
    graph->edges[edgeIndex].weight = weight;

    (*graph).matrix[start-1][end-1] = edgeIndex;
    (*graph).matrix[end-1][start-1] = edgeIndex;
}
void adjacent(G graph, int data){
    int i, index;
    if(data>6||data<0){
        printf("-1\n");
        return;
    } 
    for(i=0;i<6;i++){
        index = graph.matrix[data-1][i];
        if(index!=-1){
            if(graph.edges[index].start!=(data-1)){
                printf(" %d",graph.vertices[graph.edges[index].start].data);
                printf(" %d",graph.edges[index].weight);
            }
            else if(graph.edges[index].end!=(data-1)){ //end가 연결된 정점이면
                printf(" %d",graph.vertices[graph.edges[index].end].data);
                printf(" %d",graph.edges[index].weight);
        }
            else if(graph.edges[index].start==graph.edges[index].end){//자신이면
                printf(" %d",graph.vertices[graph.edges[index].end].data);
                printf(" %d",graph.edges[index].weight);
            }   
        }
    }
    printf("\n");
    return;
}
void modify(G *graph, int start, int end, int weight){
    int index;
    int i, b, s;
    if(start>6||start<0||end>6||end<0){
        printf("-1\n");
        return;
    }
    if(start>end){
        b = start;
        s = end;
    }
    else{
        b = end;
        s = start;
    }
    //수정할 간선의 edgeIndex
    if(weight!=0){ //삽입 or 수정
        index = (*graph).matrix[start-1][end-1];
        if(index!=-1){
            (*graph).edges[index].weight = weight;
        }
        insertEdge(graph,s,b,weight);
    }
    else{ //삭제
        (*graph).matrix[start-1][end-1]=-1;
        (*graph).matrix[end-1][start-1]=-1;
    }
}