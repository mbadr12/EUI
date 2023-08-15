#include<stdio.h>
#include"STD_TYPES.h"
void SendByte(u8 Byte);
void SendFloat(u32 f);
u32 y=0;
void main(void)
{
	SendFloat(500);
	printf("%d",y);
}
void SendFloat(u32 f)
{
	for(u16 i=0;i<4;i++)
	{
		SendByte((char)((f>>(8*i))));
	}
}
void SendByte(u8 Byte)
{
	static u16 shift=0;
	y|=(u32)(Byte<<shift);
	shift+=8;
}