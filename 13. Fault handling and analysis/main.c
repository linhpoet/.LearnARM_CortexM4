#include "stdint.h"

main()
{
	//1. Enable all configurable exceptions like usage fault, mem manage fault and bus fault
	uint32_t *pSHCSR = (uint32_t*)0xE000ED24;
	*pSHCSR |= 1<<16;
	*pSHCSR |= 1<<17;
	*pSHCSR |= 1<<18;
	
	//3. Lets force the processor to execute some undefined instruction
	uint32_t *pSRAM = (uint32_t*)0x20010000;
	*pSRAM = 0xffffffff;
	
	void (*some_address)(void);
	
	some_address = (void*)pSRAM;
	
	some_address();
	
	//4. analyze the fault
	
	while(1);
	
}

//2. Implement the fault handlers
void HardFault_Handler(void)
{
	
}

void MemManage_Handler(void)
{
	
}

void BusFault_Handler(void)
{
	
}

void UsageFault_Handler(void)
{
	
}
