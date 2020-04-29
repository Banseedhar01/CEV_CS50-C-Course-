#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc,string argv[])
{   char  ciphertext[100];
    int a, x=strlen(argv[1]);
      for(int i=0;i<x;i++)
      {
          if(!(isdigit(argv[1][i])))
           a=0; 
          else
           a=1;
      }
   /* if(argc ==2 && a==1)
     printf("success");
    else
     printf("Usage: ./caesar key"); */
     
    int n=atoi(argv[1]);
    string plaintext=get_string("plaintext: ");
    
   

    for (int i=0;i<strlen(plaintext);i++)
    {
        if(isupper(plaintext[i]))
        {  
            
             ciphertext[i]=((plaintext[i]-65+n)%26)+65;
        }
        else if(islower(plaintext[i]))
        {  
            ciphertext[i]=((plaintext[i]-97+n)%26)+97;
        }
       else
         ciphertext[i]=plaintext[i];
    }
     
    
    printf("ciphertext: %s\n",ciphertext);
}