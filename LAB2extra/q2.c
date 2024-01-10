#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    printf("I am the process A THE PARENT\n");
    int id1 = fork();
    if (id1 == 0){
        printf("I am the process B SON OF A\n");
        int id3 = fork();

        if (id3 == 0){
            printf("I am the process D SON OF B\n");
        }

    } else {
        int id2 = fork();
        if(id2 == 0){
            printf("I am the process C SON OF A\n");

            int id4 = fork();

            if (id4 == 0){
                printf("I am the process E SON OF C\n");
            } else {
                int id5 = fork();
                if (id5==0){
                    printf("I am the process F SON OF C\n");
                }
            }
        }
    }
    return 0;
}

