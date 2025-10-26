#include <stdio.h>

int conjecture(int n){
 int count = 1;//Because the edges counts too.
 while(n>1){
  if(n%2==0)
   n= n/2;
  else
   n= n*3+1;
  count++;
 } 
 return count;
}

void  max_cycle(int i, int j){
 int cycle = 0;
 int max = 0;
 int init_i = i;
 while(i<=j){
  cycle = conjecture(i++); 
  if(cycle>max)
   max = cycle;
 }
printf("%d %d %d\n",init_i,j,max); 
}

void main(void){
 int n1,n2;
 printf("Introduza dois Números: ");
 scanf("%d%d",&n1,&n2);
 max_cycle(n1,n2);
}
