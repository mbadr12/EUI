#include<stdio.h>
#include"Func.h"
#include"Func.h"
#include"STD_TYPES.h"
void main(void)
{
	printf("%d",Add(20,10));
	printf("%d",Sub(20,10));
}
u32 Add(u32 x,u32 y)
{
	return x+y;
}
u32 Sub(u32 x,u32 y)
{
	return x-y;
}