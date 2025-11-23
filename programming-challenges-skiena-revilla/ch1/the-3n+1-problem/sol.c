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

int max_cycle(int i, int j){
 int cycle = 0;
 int max = 0;
 int init_i = i;
 while(i<=j){
  cycle = conjecture(i++); 
  if(cycle>max)
   max = cycle;
 }
return max;
}

void main(void){
 int a,b;
 while(scanf("%d %d,&a,&b")!= EOF){
  printf("%d %d %d\n",a,b,max_cycle(a,b));
 }
}
