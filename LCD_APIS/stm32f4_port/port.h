/**
  ******************************************************************************
  * @file    port.h
  * @author  Abdurahman_hamdi
  * @date    3-may-2020
  * @description  this file contains user/port specific configurations(data/cmd port ,rs,en,systic timer delay.....etc ) for LCD to run  .*/
#ifndef  _lcd_port_
#define  _lcd_port_
/* Includes */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

//user definitions..... when interfacing  lcd with disc_bord it is better for all data/cmd ,rs and en pins to be combined with the same gpio port as every port clock  need to be enabled before r/w operations
#define lcd_port       GPIOD //(pins 0,1...3)
#define port_clock     RCC_AHB1Periph_GPIOD
#define lcd_RS_pin     GPIO_Pin_4
#define lcd_EN_pin     GPIO_Pin_5
// definitions for identifiers data_types to be used as function /apis parameters during definitions
#define port_data_type  GPIO_TypeDef *
//end of user definition&configuration

// define delays to be used within apis which in unit of 1us as the systick_timer fires every 1us
#define    delay_uint           (uint32_t)168  ///168*(1\(168*10^6)) =1us
#define    delay_100us           (uint32_t)100
#define    delay_2000us         (uint32_t)2000
#define    delay_1us            (uint32_t)1
#define	   delay_10us           (uint32_t)10
//functions declaration
#define  rst_rs_port    GPIO_ResetBits(lcd_port,lcd_RS_pin)
#define  set_rs_port	GPIO_SetBits(lcd_port,lcd_RS_pin)
#define  rst_en_port	GPIO_ResetBits(lcd_port,lcd_EN_pin)
#define  set_en_port	GPIO_SetBits(lcd_port,lcd_EN_pin)

void delay_uint_config(uint32_t);
void delay(uint32_t);
void set_port_pin_output(port_data_type,uint16_t,uint16_t);
void write_port(port_data_type,uint8_t);
#endif
