#include<stdio.h>
#include"STD_TYPES.h"
void SwapPtr(u32 **ptr1,u32 **ptr2);
void main(void)
{
	u32 x=10,y=20;
	u32 *ptr1=&x;
	u32 *ptr2=&y;
	SwapPtr(&ptr1,&ptr2);
	printf("*ptr1=%d *ptr2=%d",*ptr1,*ptr2);
}
void SwapPtr(u32 **ptr1,u32 **ptr2)
{
	u32 *temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}
	