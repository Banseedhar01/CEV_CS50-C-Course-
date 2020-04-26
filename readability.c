#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{
    int numof_word(string text);
    int numof_letters(string text);
    int numof_sentences(string text);
    float l,s,index;
    int grade;
    string text=get_string("text:");
    
   
    int x=numof_letters(text);
    int y=numof_word(text);
    int z=numof_sentences( text);
    
   // printf("%d letters\n ",x);
    //printf("%d words \n",y);
    //printf("%d sentences\n",z);
    
    l=(float)(100*x)/(float)y;
    s=(float)(100*z)/(float)y;
    index=0.0588 * l - 0.296 * s- 15.8;
    
    grade=round(index);
    if(grade>=1 && grade<=16)
      printf("Grade %d\n",grade);
    else if(grade<1)
     printf("Before Grade 1\n");
   else if(grade>16)
      printf("Grade 16+\n");
    
}
 int numof_letters(string text)
    {  int n=0,i=0;
        while(text[i] != '\0' )
        {
            if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z'))
               n++;
               i++;  
        }
    
        return n;
    }    
    
     int numof_word(string text)
     {
        int n=0,i=0;
        while(text[i] != '\0')
        {
            if((text[i]==' ')  && ((text[i+1]>='a' && text[i+1]<='z') || (text[i+1]>='A' && text[i+1]<='Z') ))
               n++;
               i++;
        }
     
         return (n+1); 
     }
     
     int numof_sentences(string text)
     {
         int i=0,n=0;
         while(text[i]!='\0')
         {
             if(text[i]=='?'||text[i]=='!'||text[i]=='.')
              n++;
              i++;
         }
        return n; 
     }