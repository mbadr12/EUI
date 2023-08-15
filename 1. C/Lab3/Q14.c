#include<stdio.h>
#include"STD_TYPES.h"
#define GetBit(var,no) ((var>>no)&1)
u32 ReceiveReverseIndean(u32 value);
void main(void)
{
	u32 rec=ReceiveReverseIndean(20);
	printf("%d",rec);
}
u32 ReceiveReverseIndean(u32 value)
{
	u32 rec=0;
	for(u16 i=0;i<16;i++) //20    00010100//00101000     0<<6 0000000
	{
		rec |= GetBit(value,i)<<(31-i); //001xx000
		rec|=GetBit(value,(31-i))<<i;
	}
	return rec;
}