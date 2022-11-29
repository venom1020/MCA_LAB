#include"head.h"

int main()
{ pll_init();
	IODIR0=0x4;
	while(1)
	{ if((IO0PIN && (1<<0))==0)
		{ IOSET0|=(1<<2);
			delay_ms(1000);
			IOCLR0|=(1<<2);
			delay_ms(1000);
		}
		else
		{ IOSET0|=(1<<2);
			delay_ms(500);
			IOCLR0|=(1<<2);
			delay_ms(500);
		}
	}
 return 0;
}