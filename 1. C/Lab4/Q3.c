#include<stdio.h>
#define CONC(x,y)	x##y
#define STR(x)		#x

void main(void)
{
	printf("%d\n",CONC(10,15));
	printf(STR(Badr));
}