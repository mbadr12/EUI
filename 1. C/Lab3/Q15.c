#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"
typedef enum
{
	Ascending=0,
	Descending
}Sort_t;
void Swap(s32 *ptr1,s32 *ptr2);
void Sort(s32 *Arr,u32 ArrSize);
void SortSpecifc(s32 *Arr,u32 ArrSize,Sort_t Sort);
void SortSum(s32 *Arr,u32 ArrSize);
void main(void)
{
	
}
void Swap(u32 *ptr1,u32 *ptr2)
{
	u32 temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}
void Sort(s32 *Arr,u32 ArrSize)
{
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
}
void SortSpecifc(s32 *Arr,u32 ArrSize,Sort_t Sort)
{
	for(u32 i=0;i<ArrSize-1;i++)
	{
		for(u32 j=0;j<ArrSize-i-1;j++)
		{
			switch(Sort)
			{
				case Ascending:
				if(Arr[j]<Arr[j+1])
				{
					Swap(&Arr[j],&Arr[j+1]);
				}break;
				case Descending:
				if(Arr[j]>Arr[j+1])
				{
					Swap(&Arr[j],&Arr[j+1]);
				}break;
			}
		}
	}
}
void SortSum(s32 *Arr,u32 ArrSize)
{
	u32 temp=0;
	u32* ptrArr=(u32*)calloc(ArrSize,sizeof(u32));
	for(u32 i=0;i<ArrSize;i++)
	{
		ptrArr[i]=((Arr[i]>>24)&0xff)+((Arr[i]>>16)&0xff)+((Arr[i]>>8)&0xff)+(Arr[i]&0xff); 
	}
	for(u32 i=0;i<ArrSize-1;i++)
	{
		for(u32 j=0;j<ArrSize-i-1;j++)
		{
			switch(Sort)
			{
				if(ptrArr[j]<ptrArr[j+1])
				{
					Swap(&Arr[j],&Arr[j+1]);
				}
			}
		}
	}
}