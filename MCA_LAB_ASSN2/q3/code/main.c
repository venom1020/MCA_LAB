#include"head.h"
int main()
{ pll_init();
	uart_int();
	int num=0;
	while(1)
	{
	num=recv_num();
	if(num==0) continue;
	else
	armstrong(num);
	}
	return 0;
}