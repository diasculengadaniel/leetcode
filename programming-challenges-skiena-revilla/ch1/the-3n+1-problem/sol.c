#include <stdio.h>

int conjecture(unsigned long int n){
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

int max_cycle(unsigned long int i, unsigned long int j){
 int cycle = 0;
 int max = 0;

 if(i>j){
  unsigned long int tmp = i;
  i=j;
  j=tmp;
 }

 while(i<=j){
  cycle = conjecture(i++); 
  if(cycle>max)
   max = cycle;
 }
 return max;
}

int main(void){
 unsigned long int a,b;
 while(scanf("%ld %ld",&a,&b) == 2){
  printf("%d %d %d\n",a,b,max_cycle(a,b));
 }
 return 0;
}
