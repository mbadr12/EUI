#include<stdio.h>
#include"STD_TYPES.h"
typedef enum
{
	ADD=0,
	SUB,
	MUL,
	DIV
}Op_t;
f32 Add(f32 Op1,f32 Op2);
f32 sub(f32 Op1,f32 Op2);
f32 mul(f32 Op1,f32 Op2);
f32 div(f32 Op1,f32 Op2);
f32 (*pf[4])(f32,f32)={&Add,&sub,&mul,&div};
f32 Op(Op_t Operation, f32 op1,f32 op2);
void main(void)
{
	printf("%.1f",Op(MUL,3,4));
}
f32 Add(f32 Op1,f32 Op2)
{
	return Op1+Op2;
}
f32 sub(f32 Op1,f32 Op2)
{
	return Op1-Op2;
}
f32 mul(f32 Op1,f32 Op2)
{
	return Op1*Op2;
}
f32 div(f32 Op1,f32 Op2)
{
	return Op1/Op2;
}
f32 Op(Op_t Operation, f32 op1,f32 op2)
{
	f32 Result=pf[Operation](op1,op2);
	return Result;
}