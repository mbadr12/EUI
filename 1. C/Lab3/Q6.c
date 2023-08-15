#include<stdio.h>
#include"STD_TYPES.h"
void ScanArr(u32* Arr,u32 Arr_Size);
void PrintReverse(u32* Arr,u32 Arr_Size);
void main(void)
{
	u32 arr[10];
	ScanArr(arr,10);
	PrintReverse(arr,10);
}
void ScanArr(u32* Arr,u32 Arr_Size)
{
	for(u32 i=0;i<Arr_Size;i++)
	{
		printf("Please Enter Element No. %d: ",(i+1));
		scanf("%d",(Arr+i));
	}
}
void PrintReverse(u32* Arr,u32 Arr_Size)
{
	printf("The Reversed Array:\n");
	for(u32 i=(Arr_Size-1);i>=0;i--)
	{
		printf("Element No. %d = %d\n",(i+1),*(Arr+i));
	}
}