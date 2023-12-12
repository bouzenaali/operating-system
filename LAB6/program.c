#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

int compte = 100000000;

void *threadFunc(void *arg){
    printf("Thread Function :: Start\n");
    if(compte >= 100000000){
        for (int i = 1; i<= 100000000; i++){
            compte--;
        }
    }

    printf("Thread Function :: End\n");
    return NULL;
}

int main(){
    pthread_t threadId;

    int err = pthread_create(&threadId, NULL, &threadFunc, NULL);
    if (err){
        printf("Thread creation failed : %s\n", strerror(err));
        return err;
    } else {
        printf("Thread creation with ID : %ld\n", threadId);
    }

    for (int i = 1; i <=  100000000; i++){
        compte++;
    }

    printf("Waiting for thread to exit\n");

    err = pthread_join(threadId, NULL);
    if(err){
        printf("Failed to join Thread : %s\n", strerror(err));
        return err;
    }

    printf("sold : %d\n", compte);
    printf("Exiting Main\n");
    return 0;
}