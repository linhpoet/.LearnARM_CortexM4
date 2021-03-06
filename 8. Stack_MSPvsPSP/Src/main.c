
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>


#define SRAM_START 				0x20000000U
#define SRAM_SIZE  				(128 * 1024)
#define SRAM_END  				( (SRAM_START) + (SRAM_SIZE) )
#define STACK_START SRAM_END

#define STACK_MSP_START 		 STACK_START
#define STACK_MSP_END   		(STACK_MSP_START - 512)
#define STACK_PSP_START 		STACK_MSP_END


int fun_add(int a, int b , int c , int d)
{
	return a+b+c+d;
}


/* this function changes SP to PSP */
void change_sp_to_psp(void)
{
	/*Initiate PSP at (0x20000000 + ( 128 * 1024)*/
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
	change_sp_to_psp();

/* from here onwards PSP will be used for stack activities */
	int ret;

	ret = fun_add(1, 4, 5, 6);

	printf("result = %d\n",ret);

	generate_exception();

	for(;;);
}


void SVC_Handler(void)
{
	/*MSP will be used in Handler interrupt function*/
	printf(" in SVC_Handler\n");
}
