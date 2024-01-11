#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Wrong usage of the program\n");
    } else {
        FILE *file;
        file = fopen("toto.txt", "w");  

        int pid;
        for (int i = 1; i < argc; i++) {  
            pid = fork();

            if (pid == 0) {
                // Child process
                printf("%s ", argv[i]);  
                fflush(stdout);
                return 0;
            } else {
                wait(NULL);  
                fprintf(file, "%s ", argv[i]);  
                fflush(file);
            }
        }

        printf("All world\n");
        fclose(file);
    }

    return 0;
}
