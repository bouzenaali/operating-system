#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc < 2){
	printf("Usage: %s <number1> <number2> ... <numberN>\n",argv[0]);
	return 1;
	}

    double sum = 0;
    for (int i =1; i<argc; i++){
	double number = atof(argv[i]);
	sum += number;

    }

    double average = sum / (argc -1);
    printf("Average: %.21f\n", average);

    return 0;

}
