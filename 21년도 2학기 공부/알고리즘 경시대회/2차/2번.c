#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dis(int x1, int y1, int x2, int y2);
int main(){
    int M, N, i, j,cnt=0;
    char room[11][11];
    int k1_x,k1_y,k2_x,k2_y,k3_x,k3_y;
    int p_x,p_y;
    int e_x,e_y;
    int ans[6];
    int min;
    scanf("%d %d",&M,&N);
    getchar();
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%c",&room[i][j]);
            if(room[i][j]=='P'){
                p_x = i;
                p_y = j;
            }
            else if(room[i][j]=='E'){
                e_x=i;
                e_y=j;
            }
            else if(room[i][j]=='K'){
                if(cnt==0){
                    k1_x=i;
                    k1_y=j;
                    cnt++;
                }
                else if(cnt==1){
                    k2_x=i;
                    k2_y=j;
                    cnt++;
                }
                else if(cnt==2){
                    k3_x=i;
                    k3_y=j;
                    cnt++;
                }
                else{
                    continue;
                }
            }
        }
        getchar();
    }
    ans[0] = dis(k1_x,k1_y,k2_x,k2_y)+dis(k2_x,k2_y,k3_x,k3_y); //1~3
    ans[1] = dis(k1_x,k1_y,k3_x,k3_y)+dis(k3_x,k3_y,k2_x,k2_y); //1~2
    ans[2] = dis(k1_x,k1_y,k2_x,k2_y)+dis(k1_x,k1_y,k3_x,k3_y); //2~3
    ans[3] = dis(k3_x,k3_y,k2_x,k2_y)+dis(k1_x,k1_y,k3_x,k3_y); //2~1
    ans[4] = dis(k1_x,k1_y,k3_x,k3_y)+dis(k2_x,k2_y,k1_x,k1_y); //3~2
    ans[5] = dis(k3_x,k3_y,k2_x,k2_y)+dis(k2_x,k2_y,k1_x,k1_y); //3~1

    ans[0] += dis(p_x,p_y,k1_x,k1_y); //p°¡ 1±îÁö
    ans[1] += dis(p_x,p_y,k1_x,k1_y);
    ans[2] += dis(p_x,p_y,k2_x,k2_y);
    ans[3] += dis(p_x,p_y,k2_x,k2_y);
    ans[4] += dis(p_x,p_y,k3_x,k3_y);
    ans[5] += dis(p_x,p_y,k3_x,k3_y);

    
    ans[0] += dis(e_x,e_y,k3_x,k3_y); 
    ans[1] += dis(e_x,e_y,k2_x,k2_y);
    ans[2] += dis(e_x,e_y,k3_x,k3_y);
    ans[3] += dis(e_x,e_y,k1_x,k1_y);
    ans[4] += dis(e_x,e_y,k2_x,k2_y);
    ans[5] += dis(e_x,e_y,k1_x,k1_y);
    min = ans[0];
    for(i=0;i<6;i++){
        if(ans[i]<min){
            min = ans[i];
        }
    }

    printf("%d",min);

    
    return 0;
}
int dis(int x1, int y1, int x2, int y2){
    int sum=0;
    if(x1>x2){
        sum += x1-x2;
    }
    else sum += x2-x1;
    if(y1>y2) sum+=y1-y2;
    else sum+= y2-y1;

    return sum; 
}