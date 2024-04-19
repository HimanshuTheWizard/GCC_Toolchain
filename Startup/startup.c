#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "stm32f407xx.h"

//function declaration
void Default_Handler(void);

void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);

extern void main(void);

//externally imported symbols
extern unsigned int _stack_start;
extern unsigned int __vectors_start;

//definition of weak alias
void __attribute__ ((weak, alias ("Default_Handler")))
SVC_Handler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DebugMon_Handler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
PendSV_Handler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SysTick_Handler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
WWDG_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
PVD_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TAMP_STAMP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FLASH_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RCC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ADC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_TX_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_RX0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_RX1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_SCE_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI9_5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_BRK_TIM9_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_UP_TIM10_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_TRG_COM_TIM11_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_CC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI15_10_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_Alarm_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_FS_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM8_BRK_TIM12_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM8_UP_TIM13_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM8_TRG_COM_TIM14_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM8_CC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FMC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SDIO_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
UART4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
UART5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM6_DAC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ETH_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ETH_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN2_TX_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN2_RX0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN2_RX1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN2_SCE_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_FS_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C3_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C3_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_HS_EP1_OUT_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_HS_EP1_IN_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_HS_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_HS_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DCMI_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
HASH_RNG_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FPU_IRQHandler(void);

//creating vector table
uint32_t __isr_vectors[] __attribute__ ((section(".isr_vector"),used))=
{
	(uint32_t)&_stack_start,				   //set the stack pointer
	(uint32_t)Reset_Handler,		   		   //reset handler
	(uint32_t)NMI_Handler,            		   // The NMI handler
	(uint32_t)HardFault_Handler,                 // The hard fault handler
	(uint32_t)MemManage_Handler,                 // The MPU fault handler
	(uint32_t)BusFault_Handler,                  // The bus fault handler
	(uint32_t)UsageFault_Handler,                // The usage fault handler
    0U,                                 // Reserved
    0U,                                 // Reserved
    0U,                                 // Reserved
    0U,                                 // Reserved
	(uint32_t)SVC_Handler,                       // SVCall handler
	(uint32_t)DebugMon_Handler,                  // Debug monitor handler
    0U,                                 // Reserved
	(uint32_t)PendSV_Handler,                    // The PendSV handler
	(uint32_t)SysTick_Handler,                   // The SysTick handler

	(uint32_t)WWDG_IRQHandler,                   // Window WatchDog
	(uint32_t)PVD_IRQHandler,                    // PVD through EXTI Line detection
	(uint32_t)TAMP_STAMP_IRQHandler,             // Tamper and TimeStamps through the EXTI line
	(uint32_t)RTC_WKUP_IRQHandler,               // RTC Wakeup through the EXTI line
	(uint32_t)FLASH_IRQHandler,                  // FLASH
	(uint32_t)RCC_IRQHandler,                    // RCC
	(uint32_t)EXTI0_IRQHandler,                  // EXTI Line0
	(uint32_t)EXTI1_IRQHandler,                  // EXTI Line1
	(uint32_t)EXTI2_IRQHandler,                  // EXTI Line2
	(uint32_t)EXTI3_IRQHandler,                  // EXTI Line3
	(uint32_t)EXTI4_IRQHandler,                  // EXTI Line4
	(uint32_t)DMA1_Stream0_IRQHandler,           // DMA1 Stream 0
	(uint32_t)DMA1_Stream1_IRQHandler,           // DMA1 Stream 1
	(uint32_t)DMA1_Stream2_IRQHandler,           // DMA1 Stream 2
	(uint32_t)DMA1_Stream3_IRQHandler,           // DMA1 Stream 3
	(uint32_t)DMA1_Stream4_IRQHandler,           // DMA1 Stream 4
	(uint32_t)DMA1_Stream5_IRQHandler,           // DMA1 Stream 5
	(uint32_t)DMA1_Stream6_IRQHandler,           // DMA1 Stream 6
	(uint32_t)ADC_IRQHandler,                    // ADC1, ADC2 and ADC3s
	(uint32_t)CAN1_TX_IRQHandler,                // CAN1 TX
	(uint32_t)CAN1_RX0_IRQHandler,               // CAN1 RX0
	(uint32_t)CAN1_RX1_IRQHandler,               // CAN1 RX1
	(uint32_t)CAN1_SCE_IRQHandler,               // CAN1 SCE
	(uint32_t)EXTI9_5_IRQHandler,                // External Line[9:5]s
	(uint32_t)TIM1_BRK_TIM9_IRQHandler,          // TIM1 Break and TIM9
	(uint32_t)TIM1_UP_TIM10_IRQHandler,          // TIM1 Update and TIM10
	(uint32_t)TIM1_TRG_COM_TIM11_IRQHandler,     // TIM1 Trigger and Commutation and TIM11
	(uint32_t)TIM1_CC_IRQHandler,                // TIM1 Capture Compare
	(uint32_t)TIM2_IRQHandler,                   // TIM2
	(uint32_t)TIM3_IRQHandler,                   // TIM3
	(uint32_t)TIM4_IRQHandler,                   // TIM4
	(uint32_t)I2C1_EV_IRQHandler,                // I2C1 Event
	(uint32_t)I2C1_ER_IRQHandler,                // I2C1 Error
	(uint32_t)I2C2_EV_IRQHandler,                // I2C2 Event
	(uint32_t)I2C2_ER_IRQHandler,                // I2C2 Error
	(uint32_t)SPI1_IRQHandler,                   // SPI1
	(uint32_t)SPI2_IRQHandler,                   // SPI2
	(uint32_t)USART1_IRQHandler,                 // USART1
	(uint32_t)USART2_IRQHandler,                 // USART2
	(uint32_t)USART3_IRQHandler,                 // USART3
	(uint32_t)EXTI15_10_IRQHandler,              // External Line[15:10]s
	(uint32_t)RTC_Alarm_IRQHandler,              // RTC Alarm (A and B) through EXTI Line
	(uint32_t)OTG_FS_WKUP_IRQHandler,            // USB OTG FS Wakeup through EXTI line
	(uint32_t)TIM8_BRK_TIM12_IRQHandler,         // TIM8 Break and TIM12
	(uint32_t)TIM8_UP_TIM13_IRQHandler,          // TIM8 Update and TIM13
	(uint32_t)TIM8_TRG_COM_TIM14_IRQHandler,     // TIM8 Trigger and Commutation and TIM14
	(uint32_t)TIM8_CC_IRQHandler,                // TIM8 Capture Compare
	(uint32_t)DMA1_Stream7_IRQHandler,           // DMA1 Stream7
	(uint32_t)FMC_IRQHandler,                    // FMC
	(uint32_t)SDIO_IRQHandler,                   // SDIO
	(uint32_t)TIM5_IRQHandler,                   // TIM5
	(uint32_t)SPI3_IRQHandler,                   // SPI3
	(uint32_t)UART4_IRQHandler,                  // UART4
	(uint32_t)UART5_IRQHandler,                  // UART5
	(uint32_t)TIM6_DAC_IRQHandler,               // TIM6 and DAC1&2 underrun errors
	(uint32_t)TIM7_IRQHandler,                   // TIM7
	(uint32_t)DMA2_Stream0_IRQHandler,           // DMA2 Stream 0
	(uint32_t)DMA2_Stream1_IRQHandler,           // DMA2 Stream 1
	(uint32_t)DMA2_Stream2_IRQHandler,           // DMA2 Stream 2
	(uint32_t)DMA2_Stream3_IRQHandler,           // DMA2 Stream 3
	(uint32_t)DMA2_Stream4_IRQHandler,           // DMA2 Stream 4
	(uint32_t)ETH_IRQHandler,                    // Ethernet
	(uint32_t)ETH_WKUP_IRQHandler,               // Ethernet Wakeup through EXTI line
	(uint32_t)CAN2_TX_IRQHandler,                // CAN2 TX
	(uint32_t)CAN2_RX0_IRQHandler,               // CAN2 RX0
	(uint32_t)CAN2_RX1_IRQHandler,               // CAN2 RX1
	(uint32_t)CAN2_SCE_IRQHandler,               // CAN2 SCE
	(uint32_t)OTG_FS_IRQHandler,                 // USB OTG FS
	(uint32_t)DMA2_Stream5_IRQHandler,           // DMA2 Stream 5
	(uint32_t)DMA2_Stream6_IRQHandler,           // DMA2 Stream 6
	(uint32_t)DMA2_Stream7_IRQHandler,           // DMA2 Stream 7
	(uint32_t)USART6_IRQHandler,                 // USART6
	(uint32_t)I2C3_EV_IRQHandler,                // I2C3 event
	(uint32_t)I2C3_ER_IRQHandler,                // I2C3 error
	(uint32_t)OTG_HS_EP1_OUT_IRQHandler,         // USB OTG HS End Point 1 Out
	(uint32_t)OTG_HS_EP1_IN_IRQHandler,          // USB OTG HS End Point 1 In
	(uint32_t)OTG_HS_WKUP_IRQHandler,            // USB OTG HS Wakeup through EXTI
	(uint32_t)OTG_HS_IRQHandler,                 // USB OTG HS
	(uint32_t)DCMI_IRQHandler,                   // DCMI
    0U,                                 // Reserved
	(uint32_t)HASH_RNG_IRQHandler,               // Hash and Rng
	(uint32_t)FPU_IRQHandler,                    // FPU
};

void Default_Handler(void)
{
	while(1);
}

void NMI_Handler(void)
{
	while(1);
}
void HardFault_Handler(void)
{
	while(1);
}
void MemManage_Handler(void)
{
	while(1);
}
void BusFault_Handler(void)
{
	while(1);
}
void UsageFault_Handler(void)
{
	while(1);
}
extern uint32_t _edata;
extern uint32_t _sdata;
extern uint32_t _sidata;
extern uint32_t _sbss;
extern uint32_t _ebss;
void Reset_Handler(void)
{
	uint32_t i;

	//==========initialize the vector table address from linker==========
	SCB->VTOR = (uint32_t)(&__vectors_start);

	//==========copy data section from flash to RAM=========
	uint32_t data_size = &_edata - &_sdata;

	uint8_t *pSrc = (uint8_t *)&_sidata;
	uint8_t *pDst = (uint8_t *)&_sdata;

	for(i = 0; i<data_size; i++)
	{
		*pDst++ = *pSrc++;
	}

	//===========zero fill .bss section==============
	uint32_t bss_size = &_ebss - &_sbss;

	pDst = (uint8_t *)&_sbss;

	for(i = 0; i< bss_size; i++)
	{
		*pDst++ = 0;
	}

	//by default HSI is used as default clock
	//if user wants to use HSE or PLL it can be updated here

	//===========call main============
	main();
}




