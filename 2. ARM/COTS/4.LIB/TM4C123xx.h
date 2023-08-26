/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  TM4C123xx.h
 *		  Layer:  LIB
 *       Module:  TM4C123xx
 *		Version:  1.00
 *	
 *  Description:  Register Defination       
 *  
 *********************************************************************************************************************/
 #ifndef TM4C123XX_H
 #define TM4C123XX_H
 
/******************************************** SC Peripheral Definition  **********************************************/

#define SYSCTL_BASE_ADDRESS                         0x400FE000UL

#define SYSCTL_GPIOHBCTL                            *((volatile u32*)(SYSCTL_BASE_ADDRESS+0x06c))

#define SYSCTL_RCGCGPIO                             *((volatile u32*)(SYSCTL_BASE_ADDRESS+0x608))

#define SYSCTL_RCGCWD                               *((volatile u32*)(SYSCTL_BASE_ADDRESS+0x600))

/******************************************** SYSCTL Registers Definition    *********************************************/
typedef struct
{
    volatile u32 DID[2];                  /* Device Identification */
    u32 Reserved[10];                     
    volatile u32 PBORCTL;                /* Brown-Out Reset Control */ 
    u32 Reserved2[7];                     
    volatile u32 RIS;                     /* Raw Interrupt Status */
    volatile u32 IMC;                     /* Interrupt Mask Control */
    volatile u32 MISC;                    /* Masked Interrupt Status and Clear */
    volatile u32 RESC;                    /* Reset Cause */
    volatile u32 RCC;                     /* Run-Mode Clock Configuration */
    u32 Reserved3[2];                   
    volatile u32 GPIOHBCTL;               /* GPIO High-Performance Bus Control */
    volatile u32 RCC2;                    /* Run-Mode Clock Configuration 2 */
    u32 Reserved4[2];                   
    volatile u32 MOSCCTL;                 /* Main Oscillator Control */
    u32 Reserved5[49];                   
    volatile u32 DSLPCLKCFG;              /* Deep Sleep Clock Configuration */
    u32 Reserved6;                       
    volatile u32 SYSPROP;                 /* System Properties */
    volatile u32 PIOSCCAL;                /* Precision Internal Oscillator Calibration */
    volatile u32 PIOSCSTAT;               /* Precision Internal Oscillator Statistics */
    u32 Reserved7[2];                    
    volatile u32 PLLFREQx[2];             /* PLL Frequency */
    volatile u32 PLLSTAT;                 /* PLL Status */
    u32 Reserved8[7];                     
    volatile u32 SLPPWRCFG;               /* Sleep Power Configuration */
    volatile u32 DSLPPWRCFG;              /* Deep-Sleep Power Configuration */
	u32 Reserved9[9];                    
    volatile u32 LDOSPCTL;                /* LDO Sleep Power Control */
    volatile u32 LDOSPCAL;                /* LDO Sleep Power Calibration */
    volatile u32 LDODPCTL;                /* LDO Deep-Sleep Power Control */
    volatile u32 LDODPCAL;                /* LDO Deep-Sleep Power Calibration */
	u32 Reserved10[2];                   
    volatile u32 SDPMST;                  /* Sleep / Deep-Sleep Power Mode Status */
	u32 Reserved11[76];                  
    volatile u32 PP[24];                  /* Peripherals Present */
    volatile u32 Reserved12[104];        
    volatile u32 SR[24];                  /* Peripherals Software Reset */
    volatile u32 Reserved13[40];          
    volatile u32 RCGC[24];                /* Peripherals RunMode ClockGating Control*/
    volatile u32 Reserved14[40];         
    volatile u32 SCGC[24];                /* Peripherals Sleep Mode Clock Gating Control */
    volatile u32 Reserved15[40];          
    volatile u32 DCGC[24];                /* Peripherals Deep-Sleep Mode Clock Gating Control */
    volatile u32 Reserved16[104];         
    volatile u32 PR[24];                  /* Peripheral Ready */
}SYSCRL_RegDef_t;

#define SYSCRL					((volatile SYSCRL_RegDef_t*) SYSCTL_BASE_ADDRESS)
/******************************************** GPIO Peripheral Definition *********************************************/

#define GPIOA_BASE_ADDRESS					0x40004000UL
#define GPIOB_BASE_ADDRESS					0x40005000UL
#define GPIOC_BASE_ADDRESS					0x40006000UL
#define GPIOD_BASE_ADDRESS					0x40007000UL
#define GPIOE_BASE_ADDRESS					0x40024000UL
#define GPIOF_BASE_ADDRESS					0x40025000UL


/******************************************** GPIO Registers Definition **********************************************/

typedef struct
{
	volatile u32 DATA[256];           /* GPIO Data */
	volatile u32 DIR;                 /* GPIO Direction */
	volatile u32 IS;                  /* GPIO Interrupt Sense */
	volatile u32 IBE;                 /* GPIO Interrupt Both Edges */
	volatile u32 IEV;                 /* GPIO Interrupt Event */
	volatile u32 IM;                  /* GPIO Interrupt Mask */
	volatile u32 RIS;                 /* GPIO Raw Interrupt Status */
	volatile u32 MIS;                 /* GPIO Masked Interrupt Status */
	volatile u32 ICR;                 /* GPIO GPIO Interrupt Clear */
	volatile u32 AFSEL;               /* GPIO Alternate Function Select */
	u32 Reserved[55];                    
	volatile u32 DRxR[3];             /* GPIO x-mA Drive Select */
	volatile u32 ODR;                 /* GPIO Open Drain Select */
	volatile u32 PxR[2];              /* GPIO Pull-Up-Down Select */
	volatile u32 SLR;                 /* GPIO Slew Rate Control Select */
	volatile u32 DEN;                 /* GPIO Digital Enable */
	volatile u32 LOCK;                /* GPIO Lock */
	volatile u32 CR;                  /* GPIO Commit */
	volatile u32 AMSEL;               /* GPIO Analog Mode Select */
	volatile u32 PCTL;                /* GPIO Port Control */
	volatile u32 ADCCTL;              /* GPIO ADC Control */
	volatile u32 DMACTL;              /* GPIO DMA Control */
}GPIO_RegDef_t;

#define GPIOA							((GPIO_RegDef_t*) GPIOA_BASE_ADDRESS)
#define GPIOB                           ((GPIO_RegDef_t*) GPIOB_BASE_ADDRESS)
#define GPIOC                           ((GPIO_RegDef_t*) GPIOC_BASE_ADDRESS)
#define GPIOD                           ((GPIO_RegDef_t*) GPIOD_BASE_ADDRESS)
#define GPIOE                           ((GPIO_RegDef_t*) GPIOE_BASE_ADDRESS)
#define GPIOF                           ((GPIO_RegDef_t*) GPIOF_BASE_ADDRESS)

/******************************************** STK Peripheral Definition *********************************************/

#define STK_BASE_ADDRESS					0xE000E010UL

/******************************************** STK Registers Definition **********************************************/

typedef struct
{
	volatile u32 CTRL;				/* SysTick Control and Status Register */
	volatile u32 LOAD;              /* SysTick Reload Value Register */
	volatile u32 CURRENT;           /* SysTick Current Value Register */
}STK_RegDef_t;

#define STK                             ((STK_RegDef_t*) STK_BASE_ADDRESS)

/******************************************** NVIC Peripheral Definition *********************************************/

#define NVIC_BASE_ADDRESS					0xE000E100UL

/******************************************** NVIC Registers Definition **********************************************/

typedef struct
{
	volatile u32 EN[5];                    /* Interrupt Set Enable */
	u32 Reserved[27];                         
	volatile u32 DIS[5];                   /* Interrupt clear Enable */
	u32 Reserved2[27];                        
	volatile u32 PEND[5];                  /* Interrupt Set Pending */
	u32 Reserved3[27];                        
	volatile u32 UNPEND[5];                /* Interrupt clear Pending */
	u32 Reserved4[27];                        
	volatile u32 ACTIVE[5];                /* Interrupt Active Bit */
	u32 Reserved5[59];                        
	volatile u8 PRI[140];                  /* Interrupt Priority */
	volatile u32 SWTRIG;				   /* Software Trigger Interrupt */
}NVIC_RegDef_t;

#define NVIC						((NVIC_RegDef_t*) NVIC_BASE_ADDRESS)

/******************************************** SCB Peripheral Definition *********************************************/

#define SCB_BASE_ADDRESS					0xE000ED00UL

/******************************************** NVIC Registers Definition **********************************************/

typedef struct
{
	volatile u32 CPUID;                     /* CPU ID Base */
	volatile u32 INTCTRL;                   /* Interrupt Control and State */
	volatile u32 VTABLE;                    /* Vector Table Offset */
	volatile u32 APINT;                     /* Application Interrupt and Reset Control */
	volatile u32 SYSCTRL;                   /* System Control */
	volatile u32 CFGCTRL;                   /* Configuration and Control */
	volatile u32 SYSPRI[3];                 /* System Handler Priority */
	volatile u32 SYSHNDCTRL;                /* System Handler Control and State */
	volatile u32 FAULTSTAT;                 /* Configurable Fault Status */
	volatile u32 HFAULTSTAT;                /* Hard Fault Status */
	u32 Reserved[2];                           
	volatile u32 MMADDR;                    /* Memory Management Fault Address */
	volatile u32 FAULTADDR;                 /* Bus Fault Address */
}SCB_RegDef_t;

#define SCB							((SCB_RegDef_t*)SCB_BASE_ADDRESS)

/******************************************** GPTM Peripheral Definition *********************************************/

#define GPTM0_BASE_ADDRESS					0x40030000UL
#define GPTM1_BASE_ADDRESS					0x40031000UL
#define GPTM2_BASE_ADDRESS					0x40032000UL
#define GPTM3_BASE_ADDRESS					0x40033000UL
#define GPTM4_BASE_ADDRESS					0x40034000UL
#define GPTM5_BASE_ADDRESS					0x40035000UL
#define WGPTM0_BASE_ADDRESS					0x40036000UL
#define WGPTM1_BASE_ADDRESS					0x40037000UL
#define WGPTM2_BASE_ADDRESS					0x4003c000UL
#define WGPTM3_BASE_ADDRESS					0x4003d000UL
#define WGPTM4_BASE_ADDRESS					0x4003E000UL
#define WGPTM5_BASE_ADDRESS					0x4003F000UL

/******************************************** GPTM Registers Definition **********************************************/
typedef struct
{
	volatile u32 CFG;						/* GPTM Configuration */
	volatile u32 TxMR[2];		            /* GPTM Timer A - B Mode */
	volatile u32 CLT;                       /* GPTM Control */
	volatile u32 SYNC;                      /* GPTM Synchronize Only in GPTM0 */
	u32 Reserved[2];                            
	volatile u32 IMR;                       /* GPTM Interrupt Mask */
	volatile u32 RIS;                       /* GPTM Raw Interrupt Status */
	volatile u32 MIS;                       /* GPTM Masked Interrupt Status */
	volatile u32 ICR;                       /* GPTM Interrupt Clear */
	volatile u32 xILR[2];                   /* GPTM Timer A - B Interval Load */
	volatile u32 xMATCHR[2];                /* GPTM Timer A - B Interval Load */
	volatile u32 TxPR[2];                   /* GPTM Timer A - B Prescale Match */
	volatile u32 TxPMR[2];                  /* GPTM Timer A - B Prescale Match */
	volatile u32 TxR[2];                    /* GPTM Timer A - B */
	volatile u32 TxV[2];                    /* GPTM Timer A - B Value */
	volatile u32 RTCPD;                     /* GPTM RTC Predivide */
	volatile u32 TxPS[2];                   /* GPTM Timer A - B Prescale Snapshot */
	volatile u32 TxPV[2];                   /* GPTM Timer A - B Prescale Value */
}GPTM_RegDef_t;

#define GPTM0				((volatile GPTM_RegDef_t*) GPTM0_BASE_ADDRESS)
#define GPTM1               ((volatile GPTM_RegDef_t*) GPTM1_BASE_ADDRESS)
#define GPTM2               ((volatile GPTM_RegDef_t*) GPTM2_BASE_ADDRESS)
#define GPTM3               ((volatile GPTM_RegDef_t*) GPTM3_BASE_ADDRESS)
#define GPTM4               ((volatile GPTM_RegDef_t*) GPTM4_BASE_ADDRESS)
#define GPTM5               ((volatile GPTM_RegDef_t*) GPTM5_BASE_ADDRESS)

#define WGPTM0              ((volatile GPTM_RegDef_t*) WGPTM0_BASE_ADDRESS)
#define WGPTM1              ((volatile GPTM_RegDef_t*) WGPTM1_BASE_ADDRESS)
#define WGPTM2              ((volatile GPTM_RegDef_t*) WGPTM2_BASE_ADDRESS)
#define WGPTM3              ((volatile GPTM_RegDef_t*) WGPTM3_BASE_ADDRESS)
#define WGPTM4              ((volatile GPTM_RegDef_t*) WGPTM4_BASE_ADDRESS)
#define WGPTM5              ((volatile GPTM_RegDef_t*) WGPTM5_BASE_ADDRESS)

#endif	/*TM4C123XX_H*/
/**********************************************************************************************************************
 *  END OF FILE: TM4c123xx.h
 *********************************************************************************************************************/
