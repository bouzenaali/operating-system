#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    printf("I am P0 THE PARENT\n");
    int id1 = fork();
    if (id1==0){
        printf("I am P1 SON OF P0\n");
        int id2 = fork();
        if (id2==0){
            printf("I am P3 SON OF P1\n");
            int id5 = fork();
            if (id5==0){
                printf("I am P5 SON OF P3\n");
            } else {
                int id6=fork();
                if(id6==0){
                    printf("I am P6 SON OF P3\n");
                }
            }
        }else{
            int id3 = fork();
            if (id3==0){
                printf("I am P2 SON OF P1\n");
            } else {
                int id4 = fork();
                if (id4==0){
                    printf("I am P4 SON OF P1\n");
                }
            }
        }
    }
    
    wait(NULL);
    return 0;
}

//  -- 11/01/2024 --