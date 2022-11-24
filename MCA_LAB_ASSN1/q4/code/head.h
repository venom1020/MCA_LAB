#include<lpc214x.h>
#define bit(x) (1<<x)


void writeData(int);
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

void writeData(int a)
{ int x,y;
	x=a%10;
	y=a/10;
	sevenSeg(y,1);
	delay_ms(5);
	sevenSeg(x,2);
	
}

void sevenSeg(int a,int b)
{ int table[10]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	if(b==2)
	{  IOCLR0=0xffffffff;
		 IOSET0|=bit(14);
		 IOSET0|=table[a]<<16;
	}
	else
	{ 
		 IOCLR0=0xffffffff;
		 IOSET0|=bit(15);
		 IOSET0|=table[a]<<16;
	}
}
