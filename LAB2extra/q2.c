#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void createChildProcesses(char processName,char processChilds[], int numChildren) {
    pid_t parent_pid = fork();
    if (parent_pid<0){
     perror("fork failed");
     return 1;
    } else if (parent_pid == 0){
      printf("Process %c (PID: %d) reporting its parent A",processName,parent_pid);

      }
    for (int i = 0; i < numChildren; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (child_pid == 0) {
	    for(int j;j++;j<numChildren){
            // This is the child process
            printf("Process %c (PID: %d) reporting its parent PID: %d\n", processChild[j], getpid(), getppid());
            // Terminate the loop in the child process
            }
	    break;
        }
    }

    // Parent process waits for all its children to complete
    if (getpid() != 1) {
        for (int i = 0; i < numChildren; i++) {
            wait(NULL);
        }
    }
}

int main() {
    printf("Process A (PID: %d)\n", getpid());

    createChildProcesses('b',['d'], 1);
    createChildProcesses('c',['e','f'], 2);
    return 0;
}

