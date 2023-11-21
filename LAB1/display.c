#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc != 2){
	   printf("Usage: %s <string>\n",argv[0]);
	   return 1;
	}

	FILE *myfile = fopen("output.txt","w");
	if (myfile != NULL){
	  int j=0;
	  char *i = argv[1];
	  while (i[j] != '\0' ){

	    printf("%c\n",i[j]);//print in the console
	    fprintf(myfile,"%c\n",i[j]);//print in the file
	    j++;
	  }
	  fclose(myfile);
	} else {
	  printf("the file does not exist");
	}

	return 0;


}
