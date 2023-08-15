#include<stdio.h>
#include"STD_TYPES.h"
u32 StringLen(char str[]);
void main(void)
{
	char str1[]={'B','a','d','r','\0'};
	printf("%d",StringLen(str1));
}
u32 StringLen(char str[])
{
	u32 counter=0;
	while(str[counter]!='\0')
	{
		counter++;
	}
	return counter;
}