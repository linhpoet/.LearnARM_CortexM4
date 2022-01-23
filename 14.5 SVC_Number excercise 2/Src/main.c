/*
	Viết 1 chương trình cộng trừ nhân chia 2 số dùng svc_handler rồi return kết quả về
	thread mode
	svc_number		phép toán
	36					cộng
	37					trừ
	38					nhân
	39					chia
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>
#include<stdint.h>
void SVC_Handle_c(uint32_t *pBaseStackFrame);

int32_t add_numbers(int32_t x , int32_t y )
{
	int32_t res;
	__asm volatile("SVC #36");
	__asm volatile ("MOV %0,R0": "=r"(res) ::);
	return res;

}


int32_t sub_numbers(int32_t x , int32_t y )
{
	int32_t res;
	__asm volatile("SVC #37");
	__asm volatile ("MOV %0,R0": "=r"(res) ::);
	return res;


}

int32_t mul_numbers(int32_t x , int32_t y )
{
	int32_t res;
	__asm volatile("SVC #38");
	__asm volatile ("MOV %0,R0": "=r"(res) ::);
	return res;


}

int32_t div_numbers(int32_t x , int32_t y )
{
	int32_t res;
	__asm volatile("SVC #39");
	__asm volatile ("MOV %0,R0": "=r"(res) ::);
	return res;

}


int main(void)
{
	int32_t res;

	res = add_numbers(40, -90);
	printf("Add result = %ld\n",res);

	res = sub_numbers(25,150);
	printf("Sub result = %ld\n",res);

    res = mul_numbers(374,890);
	printf("mul result = %ld\n", res);

	res = div_numbers(67,-3);
	printf("div result = %ld\n",res);



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

	uint16_t arg0, arg1, res;
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
    arg0 = pBaseOfStackFrame[0];
    arg1 = pBaseOfStackFrame[1];

    switch (svc_number)
    {
    case 36:
    	res = arg0 + arg1;
    	break;
    case 37:
        	res = arg0 - arg1;
        	break;
    case 38:
        	res = arg0 * arg1;
        	break;
    case 39:
        	res = arg0 / arg1;
        	break;
    default:
    	printf("invalid");
    }

    pBaseOfStackFrame[0] = res;


}
