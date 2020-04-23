#include <cs50.h>
#include <stdio.h>

int main(void)
{   int n;
  do
  {
    
    n=get_int("height: \n");
    
  } while (n<1 || n>8);
   
   int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i;j++)
            printf(" ");
            for(j=1;j<=i;j++)
            printf("#");
            printf("\n");
            
        }
}



