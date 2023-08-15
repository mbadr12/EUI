#include<stdio.h>
#include"STD_TYPES.h"
void main(void)
{
	u32 arr[10];
	u32* ptr=arr;
	for(u32 i=0;i<10;i++)
	{
		printf("Please Enter Element No. %d: ",(i+1));
		scanf("%d",(ptr+i));
	}
	printf("The Reversed Array:\n");
	for(u32 i=9;i>=0;i--)
	{
		printf("Element No. %d = %d\n",(10-i),*(ptr+i));
	}
}