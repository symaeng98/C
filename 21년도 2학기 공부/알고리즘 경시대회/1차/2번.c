#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char book, room;
    int num;
    char name[21];
    char info[10][21];
    int i, flag = 0;
    for(i=0;i<10;i++){
        strcpy(info[i],"0");
    }
    while(1){
        scanf("%c",&book);
        if(book=='n') break;
        getchar();
        scanf("%c",&room);
        getchar();
        scanf("%d",&num);
        getchar();
        gets(name);
        if(book=='y'){
            if((room!='p')&&(room!='s')&&(room!='d')){
                printf("please input correctly\n");
            }
            else{
                flag = 0;
                if(room=='p'&&num==1){
                    if(strcmp(info[num-1],"0")){
                        printf("please select another room\n");
                    }
                    else{
                        for(i=0;i<10;i++){
                            if(!strcmp(info[i],name)){
                                printf("please input another name\n");
                                flag=1;
                            }
                        }
                        if(!flag){
                            strcpy(info[num-1],name);
                            for(i=0;i<10;i++){
                                printf("%s ",info[i]);
                            }
                            printf("\n");
                        }
                    }
                }
                else if(room=='s'&&(num>=1)&&num<=3){
                    if(strcmp(info[num],"0")){
                        printf("please select another room\n");
                    }
                    else{
                        for(i=0;i<10;i++){
                            if(!strcmp(info[i],name)){
                                printf("please input another name\n");
                                flag=1;
                            }
                        }
                        if(!flag){
                            strcpy(info[num],name);
                            for(i=0;i<10;i++){
                                printf("%s ",info[i]);
                            }
                            printf("\n");
                        }
                    }
                }
                else if(room=='d'&&num>=1&&num<=6){
                    if(strcmp(info[num+3],"0")){
                        printf("please select another room\n");
                    }
                    else{
                        for(i=0;i<10;i++){
                            if(!strcmp(info[i],name)){
                                printf("please input another name\n");
                                flag=1;
                            }
                        }
                        if(!flag){
                            strcpy(info[num+3],name);
                            for(i=0;i<10;i++){
                                printf("%s ",info[i]);
                            }
                            printf("\n");
                        }
                    }
                }
                else{
                    printf("please input correctly\n");
                }
            }
        }
        else if(book=='c'){
            if((room!='p')&&(room!='s')&&(room!='d')){
                printf("please input correctly\n");
            }
            else{
                if(room=='p'&&num==1){
                    if(strcmp(info[num-1],"0")){
                        printf("please select another room\n");
                    }
                    else{
                        for(i=0;i<10;i++){
                            if(!strcmp(info[i],name)){
                                strcpy(info[i],"0");
                            }
                        }
                        strcpy(info[num-1],name);
                        for(i=0;i<10;i++){
                            printf("%s ",info[i]);
                        }
                        printf("\n");
                    }
                }
                else if(room=='s'&&(num>=1)&&num<=3){
                    if(strcmp(info[num],"0")){
                        printf("please select another room\n");
                    }
                    else{
                        for(i=0;i<10;i++){
                            if(!strcmp(info[i],name)){
                                strcpy(info[i],"0");
                            }
                        }
                        strcpy(info[num],name);
                        for(i=0;i<10;i++){
                            printf("%s ",info[i]);
                        }
                        printf("\n");
                    }
                }
                else if(room=='d'&&num>=1&&num<=6){
                    if(strcmp(info[num+3],"0")){
                        printf("please select another room\n");
                    }
                    else{
                        for(i=0;i<10;i++){
                            if(!strcmp(info[i],name)){
                                strcpy(info[i],"0");
                            }
                        }
                        strcpy(info[num+3],name);
                        for(i=0;i<10;i++){
                            printf("%s ",info[i]);
                        }
                        printf("\n");
                    }
                }
                else{
                    printf("please input correctly\n");
                }
            }
        }
        else{
            printf("please input correctly\n");
        }
    }
    return 0;
}