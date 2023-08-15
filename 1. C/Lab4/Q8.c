#include<stdio.h>
#include"STD_TYPES.h"
/*a. */
#define UART_STATUS_R *((volatile u8*)0x48000000)
u8 Read_Status(void);
/*b*/
typedef struct
{
	u8 BIT0:1;
	u8 BIT1:1;
	u8 BIT2:1;
	u8 BIT3:1;
	u8 BIT4:1;
	u8 BIT5:1;
	u8 BIT6:1;
	u8 BIT7:1;
}Byte_t;
u8 Read_Status2(void);
Byte_t* UART_STATUS_R= *((Byte_t*)0x48000000);
/*C. */
typedef Union
{
	Byte_t BitAccess;
	u8 Byte;
}ByteAccess;
ByteAccess* UART_STATUS_R=*((ByteAccess*)0x48000000)
/*d.*/
typedef struct
{
	volatile ByteAccess StatusRegister;
	volatile u8 Reserved[7];
	volatile ByteAccess DataRegister;
	volatile ByteAccess ControlRegister;
}UartRegisters_t;

#define UartRegisters (UartRegisters_t* 0x48000000);
u8 Read_Status3(void);

u8 Read_Status(void)
{
	u8 State= (UART_STATUS_R>>1)&(0b11);
	return State;
}
u8 Read_Status2(void)
{
	u8 State = REGISTER->BIT1 | REGISTER->BIT2;
}
u8 Read_Status3(void)
{
	UartRegisters->StatusRegister.
}