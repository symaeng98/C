#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct DisjointSets{
    int num; //몇 개가 들어있는지 확인용
    int vIndex[100]; //같은 배낭에 있는 정점들의 위치 저장
}DS;
typedef struct Vertex{
    int data;
    int setIndex;
    int visited;
}V;
typedef struct Edge{
    int v1Index;
    int v2Index;
    int weight;
}E;
typedef struct Graph{
    V vertices[100];
    E edge[1000];
    E heap[1001];
    int vNum;
    int num;
}G;
void upHeap(G *graph, int index);
void downHeap(G *graph, int index);
void swap(G *graph, int index1, int index2);
void push(G *graph, E edge);
E pop(G *graph);
void Kruskal(G *graph);
int main(){
    int n, m;
    int i;
    int v1, v2, w;
    G graph;

    scanf("%d %d",&n,&m);
    graph.vNum = n;
    graph.num = 0;
    for(i=0;i<n;i++){
        graph.vertices[i].data = i+1;
        graph.vertices[i].visited = 0;
        graph.vertices[i].setIndex = -1; //-1로 초기화
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        graph.edge[i].v1Index = v1-1;
        graph.edge[i].v2Index = v2-1;
        graph.edge[i].weight = w;
        push(&graph,graph.edge[i]);
    }
    Kruskal(&graph);
    return 0;
}
void upHeap(G *graph, int index){
    if(index==1) return;
    if(graph->heap[index].weight<graph->heap[index/2].weight){
        swap(graph,index,index/2);
        upHeap(graph,index/2);
    }
}
void downHeap(G *graph, int index){
    int min;
    if(index*2>graph->num) return;
    if(index*2==graph->num){
        if(graph->heap[index].weight>graph->heap[index*2].weight){
            swap(graph,index,index*2);
            downHeap(graph,index*2);
        }
    }
    else{
        if(graph->heap[index*2].weight>graph->heap[index*2+1].weight){
            min = index*2+1;
        }
        else min = index*2;
        if(graph->heap[index].weight>graph->heap[min].weight){
            swap(graph,index,min);
            downHeap(graph,min);
        }
    }
}
void swap(G *graph, int index1, int index2){
    E tmp;
    tmp = graph->heap[index1];
    graph->heap[index1] = graph->heap[index2];
    graph->heap[index2] = tmp;
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
void Kruskal(G *graph){
    DS set[100];
    int setIndex=0,i,j;
    int tmp;
    int tmp1, tmp2;
    E data;
    int sum=0;
    for(i=0;i<100;i++) set[i].num = 0; //초기화
    while(graph->num!=0){
        data = pop(graph); //pop
        if(graph->vertices[data.v1Index].visited==0&&graph->vertices[data.v2Index].visited==0){ //둘 다 방문 안했으면
            printf(" %d",data.weight);
            sum += data.weight;
            graph->vertices[data.v1Index].visited = 1; //방문처리
            graph->vertices[data.v2Index].visited = 1;
            graph->vertices[data.v1Index].setIndex = setIndex;
            graph->vertices[data.v2Index].setIndex = setIndex;
            set[setIndex].num += 2; //setNum은 처음에 
            set[setIndex].vIndex[0] = data.v1Index;
            set[setIndex].vIndex[1] = data.v2Index;
            setIndex++;
        }
        else if(graph->vertices[data.v1Index].visited==0&&graph->vertices[data.v2Index].visited==1){ //첫 번째 정점이 새 정점이면
            printf(" %d",data.weight);
            sum += data.weight;
            graph->vertices[data.v1Index].visited = 1;
            tmp=graph->vertices[data.v2Index].setIndex; //이미 방문한 정점을 포함한 집합의 인덱스
            graph->vertices[data.v1Index].setIndex = tmp; //집합에 포함
            set[tmp].vIndex[set[tmp].num] = data.v1Index;
            set[tmp].num++;
        }
        else if(graph->vertices[data.v1Index].visited==1&&graph->vertices[data.v2Index].visited==0){ //두 번째 정점이 새 정점이면
            printf(" %d",data.weight);
            sum += data.weight;
            graph->vertices[data.v2Index].visited = 1;
            tmp=graph->vertices[data.v1Index].setIndex; //이미 방문한 정점을 포함한 집합의 인덱스
            graph->vertices[data.v2Index].setIndex = tmp; //집합에 포함
            set[tmp].vIndex[set[tmp].num] = data.v2Index;
            set[tmp].num++;
        }
        else{ //둘 다 방문했으면
            if(graph->vertices[data.v1Index].setIndex!=graph->vertices[data.v2Index].setIndex){ //둘의 집합이 서로 다르면
                printf(" %d",data.weight);
                sum += data.weight;
                tmp1 = graph->vertices[data.v1Index].setIndex; //각 집합의 인덱스
                tmp2 = graph->vertices[data.v2Index].setIndex;
                if(set[tmp1].num<set[tmp2].num){ //v1이 포함된 집합의 원소가 더 적으면 v2로 모두 이동
                    j = set[tmp1].num;
                    for(i=0;i<j;i++){
                        graph->vertices[set[tmp1].vIndex[i]].setIndex = tmp2;
                        set[tmp2].vIndex[set[tmp2].num]=set[tmp1].vIndex[i];
                        set[tmp2].num++;
                        set[tmp1].num--; //이동
                    }
                }
                else{ //v2가 포함된 집합의 원소가 더 작으면
                    j = set[tmp2].num;
                    for(i=0;i<j;i++){
                        graph->vertices[set[tmp2].vIndex[i]].setIndex = tmp1;
                        set[tmp1].vIndex[set[tmp1].num]=set[tmp2].vIndex[i];
                        set[tmp1].num++;
                        set[tmp2].num--; //이동
                    }
                }
            }
        }
    }
    printf("\n%d",sum);
}