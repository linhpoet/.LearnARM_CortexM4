#include "stm32f10x.h"


void RTC_Config();

int cnt;

int main()
{
	RTC_Config();
	void (*pFunctionPointer)(void) = &RTC_Config;				//&RTC_Config la gtri chan, nhung compiler se + 1 vi Tbit =1
	//void (*pFunctionPointer)(void) = (void *)(0x8000244 + 1);		//Kieu thumb: Tbit = 1 => must + 1
	pFunctionPointer();
}

void RTC_Config()
{
	/*BKPEN = 1- enable backup interface*/
	RCC->APB1ENR |= 1<<27;
	/*PWREN = 1- enable power interface*/
	RCC->APB1ENR |= 1<<28;
	/*DPB = 1- access rtc and backup register enable*/
	PWR->CR |= 1<<8;
	
	/*LSEON = 1- external 32khz osc on (lse on)*/
	RCC->BDCR |=0x01;
	/*LSEDRY = 1: External 32 kHz oscillator ready, so wait until LSEDRY != 0*/
	while (((RCC->BDCR >> 1) & 0x01) != 1);
	/*	while ((RCC->BDCR & 1<<1) != 1); 2cau lenh tuong tu nhau */
	
	/*RTC clock source selection*/
	/*RTCSEL = 01- : LSE oscillator clock used as RTC clock*/
	RCC->BDCR |= 1<<8;
	RCC->BDCR &= ~(1<<9);
	
	/*RTC enable*/
	RCC->BDCR |= 1<<15;
	
	/*1. Poll RTOFF, wait until its value goes to ‘1’*/
	while (((RTC->CRL >> 5) & 0x01) != 1);
	/*2. Set the CNF bit to enter configuration mode*/
	RTC->CRL |= 1<<4;
	/*3. Write to one or more RTC registers*/
	/*fTR_CLK = fRTCCLK/(PRL[19:0]+1)*/
	RTC->PRLL = 0x7FFF;
	RTC->PRLH = 0x00;
	
	/*4. Clear the CNF bit to exit configuration mode*/
	RTC->CRL &= ~(1<<4);
	/*5. Poll RTOFF, wait until its value goes to ‘1’ to check the end of the write operation.*/
	while (((RTC->CRL >> 5) & 0x01) != 1);
}