#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#include <semaphore.h>


int compte = 100000000;
sem_t semaphore;

void *threadFunc(void *arg){
    //lock semaphore (decrement)
    sem_wait(&semaphore);
    printf("Thread Function :: Start\n");
    if(compte >= 100000000){
        for (int i = 1; i<= 100000000; i++){
            compte--;
        }
    }

    printf("Thread Function :: End\n");
    //unlock semaphore (increment)
    sem_post(&semaphore);
    return NULL;
}

int main(){
    pthread_t threadId;

    //inialize semaphore with 1 value (unlocked)
    sem_init(&semaphore, 0, 1);

    int err = pthread_create(&threadId, NULL, &threadFunc, NULL);
    if (err){
        printf("Thread creation failed : %s\n", strerror(err));
        return err;
    } else {
        printf("Thread creation with ID : %ld\n", threadId);
    }

    //wait for semaphore to be posted (unlocked) by threadFunc
    sem_wait(&semaphore);

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