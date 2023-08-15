#include<stdio.h>
#include"STD_TYPES.h"
void Reverse(u32* Arr,u32 Arr_Size);
void main(void)
{
	u32 arr[5]={1,2,3,4,5};
	Reverse(arr,5);
	for(u32 i=0;i<5;i++)
	{
		printf("%d\n",arr[i]);
	}
}
void Reverse(u32* Arr,u32 Arr_Size)
{
	u32 temp;
	for(u32 i=0;i<(Arr_Size/2);i++)
	{
		temp=Arr[i];
		Arr[i]=Arr[(Arr_Size-i-1)];
		Arr[Arr_Size-i-1]=temp;
	}
}