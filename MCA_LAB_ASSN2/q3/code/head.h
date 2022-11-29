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

void send_Char(char ch) 
{
	U0THR = ch;
	while( (U0LSR & 0x40) == 0 );	
}


char recieve_char()
{	
  unsigned char a;
  while((U0LSR&(1<<0))==0);        
  a=U0RBR;
  return a;
}


 int recv_num()
{ int num=0,i=0; 
	char c;
	c=recieve_char(); 
		while(c!=13 && i<3) 
			{ if(c>=48 && c<=57) 
					{ num=num*10+(c-48);
					}
					else return 0;
				c=recieve_char();
				i++;
			}
		return num;
}

void sendString(char*s)
{ while(*s!='\0')
	{send_Char(*s++);
	}
}

void armstrong(int num)
{ int soc=0,r,og=num;
	while(num!=0)
	{ r=num%10;
		soc+=r*r*r;
		num/=10;
	}
	if(og==soc) 
	{sendString("Armstrong");
	sendString("\r\n");
	}
	else
	{sendString("Not armstrong");
	 sendString("\r\n");
	}
}	