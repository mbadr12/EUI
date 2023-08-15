#include<stdio.h>
#include<stdarg.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
void SetBits(u8* Reg,u8 BitNum, ...);
void main(void)
{
	u8 x=0;
	INSERT_VALUE(x,1,2,3);
	//SetBits(&x,3,0,1,2);
	printf("%d\n",x);
	printf("%d",GET_VALUE(x,1,2));
}
void SetBits(u8* Reg,u8 BitNum, ...)
{
	u8 Bit;
	va_list args;
	va_start(args,BitNum);
	for(u8 i=0;i<BitNum;i++)
	{
		Bit=va_arg(args,int);
		*Reg |= 1<<Bit;
	}
	va_end(args);
}