#include<stdio.h>
#include"STD_TYPES.h"
void SwapBytes(u16 *Var);
void main(void)
{
	u16 var=0xdaba;
	SwapBytes(&var);
	printf("%x",var);
}
void SwapBytes(u16 *Var)
{
	*Var=(*Var>>8)|(*Var<<8);
}