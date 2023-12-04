#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    char myFile[10];
    strcpy(myFile, argv[1]);

    FILE *file;
    char buffer[5];  // Adjusted buffer size

    if (fork()) {
        file = fopen(myFile, "r+");
        if (file == NULL) {
            perror("Unable to open file for reading");
            return 1;
        }

        fprintf(file, "Parent");
        fclose(file); 
        sleep(2);

        file = fopen(myFile, "r");
        if (file == NULL) {
            perror("Unable to open file for reading\n");
            return 1;
        }

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fclose(file);
    } else {
        sleep(1);
        file = fopen(myFile, "r+");
        if (file == NULL) {
            perror("Unable to open file for reading\n");
            return 1;
        }

        sleep(1);

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fprintf(file, "Child");
        fclose(file);
    }

    return 0;
}
