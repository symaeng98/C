#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, i;
    int arr[21];
    int a_x, a_y, b_x, b_y;
    int ans=0;
    a_x = 0; a_y = 4;
    b_x = 4; b_y = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]==1){
            a_x++;
        }
        else if(arr[i]==2){
            a_x--;
        }
        else if(arr[i]==3){
            a_y--;
        }
        else if(arr[i]==4){
            a_y++;
        }
    }
    if(a_x==b_x&&a_y==b_y) ans = 1;
    else ans = 2;

    if(ans==1) printf("%d",ans);
    else{
        printf("%d\n",ans);
        printf("%d %d\n",b_x-a_x, a_y-b_y);
    }
    return 0;
}