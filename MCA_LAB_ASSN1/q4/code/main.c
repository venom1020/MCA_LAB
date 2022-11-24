#include"head.h"
int main(void)
{ IODIR0=0xffffffff;
	for(int i=99;i>=0;i--)
		{ writeData(i);
			delay_ms(5);
		}
	return 0;
}