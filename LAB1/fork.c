#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Hello from the child process! (PID: %d)\n", getpid());
    } else if (child_pid > 0) {
        // This code is executed by the parent process
        printf("Hello from the parent process! (Child PID: %d, Parent PID: %d)\n", child_pid, getpid());
    } else {
        // Forking failed
        printf("Fork failed!\n");
    }

    return 0;
}
