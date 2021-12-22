/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdio.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE (128*1024)
#define SRAM_END 	((SRAM_START) + (SRAM_SIZE))

#define STACK_START 		SRAM_END

#define STACK_MSP_START  	STACK_START
#define STACK_MSP_END  		(STACK_START + 512)
#define STACK_PSP_START		STACK_MSP_END

int fun_add(int a, int b, int c)
{
	return a+b+c;
}

__attribute__ ((nack)) void change_msp_to_psp(void)
{
	__asm volatile(".equ SRAM_END, (0x20000000 + ( 128 * 1024))");
	__asm volatile(".equ PSP_START , (SRAM_END-512)");
	__asm volatile("LDR R0,=PSP_START");
	__asm volatile("MSR PSP, R0");
	__asm volatile("MOV R0,#0X02");
	__asm volatile("MSR CONTROL,R0");
	__asm volatile("BX LR");
}

void generate_exception(void)
{
	/* execute SVC instruction to cause SVC exception */
	__asm volatile("SVC #0X2");
}


int main(void)
{
	change_msp_to_psp();
	int ret;

	ret = fun_add(4, 5, 6);
	printf("result = ", ret);

	generate_exception();
    /* Loop forever */
	for(;;);
}

void SVC_Handler(void)
{
	printf(" in SVC_Handler\n");
}
