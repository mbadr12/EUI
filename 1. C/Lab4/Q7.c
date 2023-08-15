#include<stdio.h>
#include"STD_TYPES.h"
void enableInterrupt(u8 interruptNumber);
void setInterruptPriority(u8 interruptNumber, u8 priority);
u32 x=0,y=0,z=0,a=0;
u32* NVIC_ISER0=&x;
u32* NVIC_ISER1=&y;
u32* NVIC_ISER2=&z;
u32* NVIC_ISER3=&a;
u32 *ISER_Regs[4]={NVIC_ISER0,NVIC_ISER1,NVIC_ISER2,NVIC_ISER3};
u32 *PR_Regs[25]={NULL};
void main(void)
{
	
}
void enableInterrupt(u8 interruptNumber)
{
	u8 Reg_num=interruptNumber/32;
	u8 Bit_num=interruptNumber%32;
	*ISER_Regs[Reg_num] |= (1<<interruptNumber)
}
void setInterruptPriority(u8 interruptNumber, u8 priority)
{
	u8 Reg_num=interruptNumber/8;
	u8 Bit_num=interruptNumber%8;
	*PR_Regs[Reg_num] |= (priority<<interruptNumber);
}