#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int i=2;
  int j=10;
  int p;

  while((i--) && (p=fork())){
	if (p<0) exit(1);
	j+=2;

	if (p==0) {i *= 3; j *= 3;} else {i *=2; j *= 2;};
	printf("i=%d,j=%d\n",i,j);
  }
return 0;
}
