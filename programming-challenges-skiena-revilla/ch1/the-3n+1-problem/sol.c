#include <stdio.h>

int conjecture(int n){
 int count = 1;
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

int main(void){
 int a,b;
 while(scanf("%d %d",&a,&b) == 2){
  printf("%d %d %d\n",a,b,max_cycle(a,b));
 }
 return 0;
}
