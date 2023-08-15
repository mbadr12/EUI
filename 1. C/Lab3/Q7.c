#include<stdio.h>
#include"STD_TYPES.h"
s32 Search(char *Str,char Character);
void main(void)
{
	printf("%d",Search("BAdaAara",'A'));
}
s32 Search(char *Str,char Character)
{
	s32 Occurance=0;
	char val;
	if((Character >='a') && (Character <='z'))
	{
		val=Character-0x20;
	}
	else if((Character >='A') && (Character <='Z'))
	{
		val=Character+0x20;
	}
	else
	{
		Occurance=-1;
	}
	if(Occurance!= -1)
	{
		for(u32 i=0;Str[i]!='\0';i++)
		{
			if((Str[i]==Character) || (Str[i]==val))
			{
				Occurance++;
			}
		}
	}
	return Occurance;
}