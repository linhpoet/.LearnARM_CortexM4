
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define IRQNO_TIMER2  28
#define IRQNO_I2C1    31

#include<stdint.h>
#include<stdio.h>

/* NVIC register addresses. Refer to the processor generic guide */
uint32_t *pNVIC_IPRBase =  (uint32_t*)0xE000E400;
uint32_t *pNVIC_ISERBase = (uint32_t*)0xE000E100;
uint32_t *pNVIC_ISPRBase = (uint32_t*)0XE000E200;


void configure_priority_for_irqs(uint8_t irq_number, uint8_t priority_value)
{
	//1. find out iprx
	uint8_t iprx = irq_number/4;

	//2. position in iprx
	uint8_t pos = (irq_number % 4) *8 +4;

	/*3. configure the priority*/
	//move 0 to 4 priority bit
	*(pNVIC_IPRBase + iprx) &= ~(0x0f << pos);
	//mvoe priority_value to 4 priority_bits
	*(pNVIC_IPRBase + iprx) |=  (priority_value << pos);

}

int main(void)
{
	//1. Lets configure the priority for the peripherals
	configure_priority_for_irqs(IRQNO_TIMER2, 8);
	configure_priority_for_irqs(IRQNO_I2C1, 7);
	//2. Set the interrupt pending bit in the NVIC PR- to generate interrupt
	*pNVIC_ISPRBase |= 1 << IRQNO_TIMER2;

	//3. Enable the IRQs in NVIC ISER
	*pNVIC_ISERBase |= 1 << IRQNO_I2C1;
	*pNVIC_ISERBase |= 1 << IRQNO_TIMER2;



}

//isrs

void TIM2_IRQHandler(void)
{
  printf("[TIM2_IRQHandler]\n");
  /*then, generate I2C interrupt */
  *pNVIC_ISPRBase |= ( 1 << IRQNO_I2C1);
  while(1);

}


void I2C1_EV_IRQHandler(void)
{
  printf("[I2C1_EV_IRQHandler]\n");
}
