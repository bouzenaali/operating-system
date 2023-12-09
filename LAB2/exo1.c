#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>


int main(){

int p = getpid();
printf("DEBUT %i\n",p);
unsigned n = 0x7fffffff;
while(n--);
printf("FIN %i\n",p);
return 0;
}
