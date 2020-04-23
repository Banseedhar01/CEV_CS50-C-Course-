#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{   
    float n;
    int N;
    
    do
   {   
        n=get_float("change owned: ");
        N=round(n*100);
   }while(n<0);
    
   int a=round(N/25);
   int R=N%25;
   
   int b=round(R/10);
    R=R%10;

   int c=round(R/5);
    R=R%5;

   int d=round(R/1);
   int z=a+b+c+d;
  printf("%d",z);
   
 }
