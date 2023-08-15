#include<stdio.h>
#include"STD_TYPES.h"
void concat(char* str1,char*str2,char Concstr[]);
void main(void)
{
	char conc[15];
	concat("Mahmoud ","Badr",conc);
	printf("%s",conc);
}
void concat(char* str1,char* str2,char Concstr[])
{
	u32 i=0;
	for( ;str1[i]!='\0';i++)
	{
		Concstr[i]=str1[i];
	}
	for(u32 j=0;str2[j];j++,i++)
	{
		Concstr[i]=str2[j];
	}
	Concstr[i]='\0';
}