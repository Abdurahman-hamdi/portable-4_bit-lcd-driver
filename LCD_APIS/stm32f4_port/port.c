/**
  ******************************************************************************
  * @file    port.c
  * @author  Abdurahman_hamdi
  * @date    3-may-2020
  * @description  this file contains set of target dependent functions definitions used by lcd application routines  .*/

/* Includes */
#include "port.h"
volatile uint32_t delay_var;//holds current /remaining timing uints

// set SysTick to fire ever time unit specified by app

void delay_uint_config(uint32_t unit)
{
	SysTick_Config(unit);
	SysTick->CTRL = 0;
}
void delay(uint32_t uints)
{
	delay_var=0;//clear delay variable
	SysTick->CTRL = 7;//Enable SysTick timer with interruption generation clocked by processor clock
	while(delay_var<uints); // wait here for specified time uints
	SysTick->CTRL = 0;//disable SysTick

}

void set_port_pin_output(port_data_type port,uint16_t rs_pin,uint16_t en_pin)
{
	RCC_AHB1PeriphClockCmd(port_clock, ENABLE);
	GPIO_InitTypeDef GPIO_InitDef;
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|rs_pin|en_pin;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(port, &GPIO_InitDef);

	GPIO_ResetBits(port,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|rs_pin|en_pin);
}
void write_port(port_data_type gpio,uint8_t val)
{
	GPIO_Write(gpio,(uint16_t)val);
}
void SysTick_Handler(void)
{
	delay_var++;


}

