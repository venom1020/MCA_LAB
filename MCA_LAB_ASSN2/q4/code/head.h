#include<lpc214x.h>
#define bit(x) (1<<x)

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

void delay_us(unsigned int ms)
{
    T0CTCR=0x0;                                 
    T0TCR=0x00;                
    T0PR=59;                 
    T0TCR=0x01;                
    while(T0TC<ms);           
    T0TCR=0x00;                 
    T0TC=0;   
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
void write2Dac(int i)
{ 
	DACR=(1<<16)|(i<<6);
}
int getSine(int i)
{ int arr[]={512,574,635,695,752,805,854,898,936,968,993,1010,1021,1023,1019,1006,986,960,926,886,841,791,737,679,619,512,449,388,328,271,218,169,125,87,55,30,13,2,0,4,17,37,63,97,137,182,232,286,344,404};
	if(i<50) return arr[i];
	else 
	return 0;
}
