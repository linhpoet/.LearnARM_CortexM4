
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>
#include<stdint.h>

#define __ASM	__asm

void change_sp_to_psp(void);
void ReadStackFarme(uint32_t *pReadStackFarm);
uint8_t aStackFarm[8] = {0};
/* This function executes in THREAD MODE of the processor */
void generate_interrupt()
{
	uint32_t *pSTIR  = (uint32_t*)0xE000EF00;
	uint32_t *pISER0 = (uint32_t*)0xE000E100;

	//enable IRQ3 interrupt
	*pISER0 |= ( 1 << 3);

	//generate an interrupt from software for IRQ3
	*pSTIR = (3 & 0x1FF);

}

/* This function executes in THREAD MODE of the processor */
int main(void)
{
	/*change SP from MSP to PSP*/
	int control_reg = 0x2;
	uint32_t psp_value = 0x20008000;
	change_sp_to_psp();

	printf("In thread mode : before interrupt\n");

	generate_interrupt();

	printf("In thread mode : after interrupt\n");

	for(;;);
}

/* This function(ISR) executes in HANDLER MODE of the processor */
void RTC_WKUP_IRQHandler(void)
{
	printf("Handler mode\n");

	//__ASM ("IMPORT ReadStackFarme");

	//__ASM ("PRESERVE8 {1}");
	__ASM ("MRS R0, MSP");
	__ASM ("PUSH {LR}");
	__ASM ("BL ReadStackFarme");
	__ASM ("POP {LR}");
	__ASM ("BX LR");

}


/* this function changes SP to PSP */
void change_sp_to_psp(void)
{
	__ASM ("LDR R0,=0x20008000");
	__ASM ("MSR PSP, R0");
	__ASM ("MOV R0,#0x02");
	__ASM ("MSR CONTROL,R0");
	__ASM ("BX LR");
}

void ReadStackFarme(uint32_t *pReadStackFarm)
{
	uint8_t u8Count = 0;

	for (u8Count = 0U; u8Count < 8U; u8Count ++)
	{
		aStackFarm[u8Count] = *pReadStackFarm;
		pReadStackFarm ++;
	}
}

