#include<stdio.h>
#include"STD_TYPES.h"
#include<stdbool.h>
bool IsEven(u32 Num);
bool IsOdd(u32 Num);
u32 SumArr(u32* Arr,u32 ArrSize,bool(*pf)(u32));
void main(void)
{
	u32 arr[5]={1,3,4,5,2};
	printf("%d",SumArr(arr,5,IsOdd));
}
bool IsEven(u32 Num)
{
	bool flag=true;
	if(Num&1)
	{
		flag=false;
	}
	else
	{
		/*Do nothing*/
	}
	return flag;
}
bool IsOdd(u32 Num)
{
	bool flag=false;
	if(Num&1)
	{
		flag=true;
	}
	else
	{
		/*Do nothing*/
	}
	return flag;
}
u32 SumArr(u32* Arr,u32 ArrSize,bool(*pf)(u32))
{
	u32 sum=0;
	bool state;
	for(u32 i=0;i<ArrSize;i++)
	{
		state=pf(Arr[i]);
		if(state==true)
		{
			sum+=Arr[i];
		}
		else
		{
			/*Do nothing*/
		}
	}
	return sum;
}