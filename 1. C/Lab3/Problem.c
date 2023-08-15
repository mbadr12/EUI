#include<stdio.h>
#include"STD_TYPES.h"
u8 ArrFind2Max(s32 *Arr,u32 ArrSize, s32 *Max2);
void Swap(s32 *ptr1,s32 *ptr2);
void main(void)
{
	u8 state=0;
	s32 Max[2];
	s32 arr[5]={5,5,5,5,5};
	state=ArrFind2Max(arr,5,Max);
	if(state==0)
	{
		printf("The array has the same value: %d",arr[0]);
	}
	else
	{
		printf("Max1=%d Max2=%d",Max[0],Max[1]);
	}
}
u8 ArrFind2Max(s32 *Arr,u32 ArrSize,s32 *Max2)
{
	u8 State=0;
	u32 i=0;
	for(i=0;i<ArrSize-1;i++)
	{
		for(u32 j=0;j<ArrSize-i-1;j++)
		{
			if(Arr[j]<Arr[j+1])
			{
				Swap(&Arr[j],&Arr[j+1]);
			}
		}
	}
	if(Arr[0]!=Arr[ArrSize-1])
	{
		for(i=0;i<ArrSize-1;i++)
		{
			if(Arr[i+1]!=Arr[i])
			{
				break;
			}
		}
		Max2[0]=Arr[0];
		Max2[1]=Arr[i+1];
		State=1;
	}
	return State;
}
void Swap(s32 *ptr1,s32 *ptr2)
{
	u32 temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}