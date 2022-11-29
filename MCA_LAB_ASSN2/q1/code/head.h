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

void uart_int(void)
{
  PINSEL0=0X5;
  U0LCR=0X83;            
  U0DLL=135;
  U0DLM=1;
  U0LCR=0X03;          
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

void displayString(char* s)
{ while(*s!='\0')
	{ dat(*s++);
	}
}	

int palindrome(char *s)
{ int len=0;
	char *temp;
	temp=s;
	while(*temp++!='\0') len++;
	for(int i=0;i<len/2;i++)
	{ if(s[i]!=s[len-i-1]) return 0;
	}
	return 1;
}
char recieve_char()
{	
  unsigned char a;
  while((U0LSR&(1<<0))==0);        
  a=U0RBR;
  return a;
}
char* rec_string()
{ int i=0; 
	char c,string[20];
		c=recieve_char(); 
		while(c!=13 && i<14) 
			{ string[i++]=c;  
				c=recieve_char();
			}
	  string[i]='\0';
		return string;
}
