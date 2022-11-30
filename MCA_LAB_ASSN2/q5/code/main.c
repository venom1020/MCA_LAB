#include"head.h"
#include<stdio.h>
int main()
{ IODIR1=0xffffffff;
	PINSEL1 = 0x01000000;
	adc_init();
	lcd_int();
	while(1)
	{ cmd(0x01);
		cmd(0x80);
		displayString("Voltage:");
		printVoltage();
		delay_ms(100);
	}	
 return 0;
}


