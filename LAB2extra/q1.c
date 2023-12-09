#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
    int num_children = 10;
    pid_t child_pid;
    for(int j=0; j<10; j++){
        for (int i = 0; i < num_children; i++) {

	child_pid = fork();

        if (child_pid < 0) {
            perror("Fork failed");
            return 1;
        } else if (child_pid == 0) {

                printf("%d ",j);
	  	fflush(stdout);
	    //int pid = getpid();
	    //printf("(%d)",pid);
            exit(0);
        }}
    }



    return 0;
}
