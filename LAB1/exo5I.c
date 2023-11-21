#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int p=1;
    while(p>0){
	p=fork();
    }
printf("hello!\n");
return 0;
}
