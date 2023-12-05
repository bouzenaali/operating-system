#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
    char myFile[10];
    strcpy(myFile, argv[1]);

    FILE *file;
    char buffer[5];

	file = fopen(myFile, "r+");
	if (file == NULL) {
		perror("Unable to open file for writing 1\n");
		return 1;
	}

    if(fork()){
        sleep(1);

        fseek(file, 0, SEEK_SET);
        while(fgets(buffer, sizeof(buffer), file) != NULL){
            printf("%s", buffer);
        }

        fprintf(file, "Parent ");
        fflush(file);
    } else {
        fprintf(file, "Child ");
        fflush(file);

        sleep(2);

        fseek(file, 6, SEEK_SET);
        while(fgets(buffer, sizeof(buffer), file) != NULL){
            printf("%s", buffer);
        }
    }

    fclose(file);
}