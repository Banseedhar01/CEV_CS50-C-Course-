#include "helpers.h"
#include<math.h>
#include<string.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{  for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            float av;
            av=(image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue)/3.00;
            image[i][j].rgbtRed=round(av);
            image[i][j].rgbtGreen=round(av);
            image[i][j].rgbtBlue=round(av);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{   for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {   float sepiaRed,sepiaGreen ,sepiaBlue;
            int originalRed=image[i][j].rgbtRed, originalGreen=image[i][j].rgbtGreen;
            int originalBlue=image[i][j].rgbtBlue;

            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            image[i][j].rgbtRed=fmin(round(sepiaRed),255);
            image[i][j].rgbtGreen=fmin(round(sepiaGreen),255);
            image[i][j].rgbtBlue=fmin(round(sepiaBlue),255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE temp;
    for(int i=0;i<height;i++)
   {
       for(int j=0;j<width/2;j++)
       {
           temp=image[i][j];
           image[i][j]=image[i][width-j-1];
           image[i][width-j-1]=temp;
       }
   }


   return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create new array to store blurred value
   RGBTRIPLE temp[height][width];
   
   memcpy(temp,image,sizeof(RGBTRIPLE)*height*width);
   
   for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            float average=0.0;
           int red=0;
           int green=0;
           int blue=0;
           
           for(int k=-0;k<=1;k++)
           {
               for(int l=-1;l<=1;l++)
               {
                   if(i+k != height && i+k != -1 && j+l != width && j+l != -1)
                   {
                       red +=temp[i+k][j+l].rgbtRed;
                       green+=temp[i+k][j+l].rgbtGreen;
                       blue+=temp[i+k][j+l].rgbtBlue;
                       
                       average++;
                   }
                   
               }
           }
              image[i][j].rgbtRed=round(red/average);
              image[i][j].rgbtGreen=round(green/average);
              image[i][j].rgbtBlue=round(blue/average);  
        }
      
    }
    return;
}
