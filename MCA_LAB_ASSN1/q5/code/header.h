#include<lpc214x.h>
#define bit(x) (1<<x)


void sevenSeg(int,int);

void pll_init(void)                  
{
    PLL0CON=0x01;
    PLL0CFG=0x24;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    while(!(PLL0STAT&(1<<10)));
    PLL0CON=0x03;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    VPBDIV=0x01;
}

void delay_ms(unsigned int ms)
{
    T0CTCR=0x0;                                 
    T0TCR=0x00;                
    T0PR=59999;                 
    T0TCR=0x01;                
    while(T0TC<ms);           
    T0TCR=0x00;                 
    T0TC=0;   
}

void sevenSeg(int a,int b)
{ IOSET0|=0XF000;
	IOCLR0|=0XFF0000;
	switch(b)
	{ case 1: IOCLR0|=bit(12);
						IOSET0|=a<<16;
						break;
		case 2: IOCLR0|=bit(13);
						IOSET0|=a<<16;
						break;
		case 3: IOCLR0|=bit(14);
						IOSET0|=a<<16;
						break;
		case 4: IOCLR0|=bit(15);
						IOSET0|=a<<16;
						break;
		default:  break;
	}
	
}
