#include<stdio.h>

#define ADD(x,y)	(x+y)
#define SUB(x,y)    (x-y)
#define MUL(x,y)    (x*y)
#define DIV(x,y)    (x/y)

void main(void)
{
	printf("%.1f\n",ADD(20.0,5.0));
	printf("%.1f\n",SUB(20.0,5.0));
	printf("%.1f\n",MUL(20.0,5.0));
	printf("%.1f\n",DIV(20.0,5.0));
}