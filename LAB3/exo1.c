#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
  system("ps u");
  int *a;
  a = (int*)malloc(sizeof(int)*30000000000);
  printf("%p\n",a);
  system("ps u");
  free(a);
  system("ps u");
}
