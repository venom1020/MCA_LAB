#include"head.h"

int main()
{	PINSEL1=0x80000;
	int i=0,sine;
	while(i<50)
	{  sine=getSine(i);
		 write2Dac(sine);
		 delay_us(10);
		i++;
	}
	return 0;
}