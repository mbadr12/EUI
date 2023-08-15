#include<stdio.h>
#include"STD_TYPES.h"
u32 StringLen(char *str);
void main(void)
{
	printf("%d %d",StringLen("Badr"),StringLen("Badaar"));
}
u32 StringLen(char *str)
{
	u32 counter=0;
	while(str[counter]!='\0')
	{
		counter++;
	}
	return counter;
}