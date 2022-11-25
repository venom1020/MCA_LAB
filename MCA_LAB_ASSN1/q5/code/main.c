#include"header.h"
int main(void)
{ IODIR0=0xffffffff;
	//msis in hex
	int arr[4][4]={{0x55,0x6D,0x06,0x6D},{0x6D,0x06,0x6D,0x55},{0x06,0x6D,0x55,0x6D},{0x6D,0x55,0x6D,0x06}};
	int j=1,count=0;
	while(j<=4)
	{
	while(count<15)
	{		
		for(int i=1;i<=4;i++)
		{ sevenSeg(arr[j-1][i-1],i);
		delay_ms(1);
		}
	count++;
	}
	j++;
	count=0;
	}
	return 0;
}