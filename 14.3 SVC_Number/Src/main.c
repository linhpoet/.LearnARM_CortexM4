/*
Write a program to execute an SVC instruction from thread mode,
implement the svc handler to print the SVC number used.
Also,  increment the SVC number by 4 and return it to the thread mode code and print it.
Hints :
1)Write a main() function where you should execute the SVC instruction with an argument.
let's say SVC #0x25
2)Implement the SVC handler
3)In the SVC handler extract the SVC number and print it using printf
4) Increment the SVC number by 4 and return it to the thread mode
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>
#include<stdint.h>
int main(void)
{
	__asm volatile ("SVC #25");

	//register uint32_t data __asm("r0");

	uint32_t data;

	__asm volatile ("MOV %0,R0": "=r"(data) ::);

	printf(" data = %ld\n",data);

	for(;;);
}


__attribute__ ((naked)) void SVC_Handler(void)
{
	//1 . get the value of the MSP
	__asm("MRS R0,MSP");
	//nacked là function: nếu dùng c code thì có thể bị sai
	__asm("B SVC_Handler_c");
}

void SVC_Handler_c(uint32_t *pBaseOfStackFrame)
{
	printf("in SVC handler\n");
	//store value of stack PC (return address)
	uint8_t *pReturn_addr = (uint8_t*)pBaseOfStackFrame[6];

	//2. decrement the return address by 2 to point to
	//opcode of the SVC instruction in the program memory
	//3. extract the SVC number (LSByte of the opcode)
	//tại 1 địa chỉ chỉ lưu được 8 bit data, và ngay tại địa chỉ của svc instruction lưu svc_number
    uint8_t svc_number = *(pReturn_addr - 2);

    printf("Svc number is : %d\n",svc_number);

    svc_number+=4;

    //R0 = svc_number
    pBaseOfStackFrame[0] = svc_number;

}
