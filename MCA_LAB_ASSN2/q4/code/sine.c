//script to generate sine values for DAC
//run outside keil and get the values to be fed to DAC
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define steps 25

int main()
{ int deg=0,sine;
  float r;
  for(int i=0;i<steps;i++)
    { r=deg*3.14/180;
      sine=512+512*sin(r);
      printf("%d,",sine);
      deg+=180/steps;
    } 
    deg=0;
  for(int i=0;i<steps;i++)
    { r=deg*3.14/180;
      sine=512-512*sin(r);
      printf("%d,",sine);
      deg+=180/steps;
    }
	return 0;	
	}		