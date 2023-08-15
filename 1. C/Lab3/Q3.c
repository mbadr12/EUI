#include<stdio.h>
#include"STD_TYPES.h"
void Swap(u32 *ptr1,u32 *ptr2);
void main(void)
{
	int x=10,y=20;
	Swap(&x,&y);
	printf("x=%d y=%d",x,y);
}
void Swap(u32 *ptr1,u32 *ptr2)
{
	u32 temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}