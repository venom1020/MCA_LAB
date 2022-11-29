#include"head.h"
int main()
{ IODIR1=0xffffffff;
	IOPIN1=0;
	pll_init();
	lcd_int();
	uart_int();
	char *s;
	while(1)
	{ s=rec_string();
		cmd(0x01);
		cmd(0x80);
		displayString(s);
		cmd(0xC0);
		if(palindrome(s))
		{ 
			displayString("Is palindrome!");
		}
		else
		{
			displayString("Not palindrome!");
		}
	}
 return 0;
}