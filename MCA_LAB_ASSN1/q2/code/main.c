#include"header.h"

int main(void)
{	IO0DIR|=0xEF;
	short a=0	;
	while(1)
	{ if((IO0PIN & bit(4))==0)
		{
		 while((IO0PIN & bit(4))==0);	 
		 //wait for switch to change state
			
		if(a==0) 
		{	IOSET0|=bit(1);
			a=1;
		}	
		else
		{ IO0CLR|=bit(1);
			a=0;
		}	
	}
	}
	return 0;
}