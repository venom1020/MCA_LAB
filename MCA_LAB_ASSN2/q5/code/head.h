#include<lpc214x.h>
#include<stdio.h>
#define bit(x) (1<<x)

void delay_ms(int n)
{ while(n-->0)
	{
	 for(int i=0;i<2000;i++);
	}
}


void cmd(unsigned char a)
{
    IO1PIN&=0x00;
    IO1PIN=(a<<16);
    IO1CLR|=bit(25);               
    IO1CLR|=bit(26);               
    IO1SET|=bit(27);               
    delay_ms(2);
    IO1CLR|=bit(27);               
}

void dat(unsigned char b)
{
    IO1PIN&=0x00;
    IO1PIN=(b<<16);
    IO1SET|=bit(25);               
    IO1CLR|=bit(26);               
    IO1SET|=bit(27);              
    delay_ms(2);
    IO1CLR|=bit(27);               
}


void lcd_int(void)
{
    cmd(0x38);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

int readVolt()
{ int result;
	AD0CR = AD0CR | (1<<24);
	while ( !(AD0GDR & 0x80000000)); 
	AD0CR&=~0X01000000;
	result = AD0GDR;
	result = (result>>6);
	result = (result & 0x000003FF);
	return  result*100*3.3/1023;
}
 

void adc_init()
{ AD0CR = 0x00200402;
}

void displayString(char* s)
{ while(*s!='\0')
	{ dat(*s++);
	}
}	

void printVoltage()
{int volt,i,voltD;
	char str[20];
	volt=readVolt();
	i=volt/100;
	voltD=volt-i*100;
	sprintf(str,"%d.%d V",i,voltD);
	displayString(str);
}




