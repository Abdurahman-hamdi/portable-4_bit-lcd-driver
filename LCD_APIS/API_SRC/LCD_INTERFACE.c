/**
  ******************************************************************************
  * @file    LCD_INTERFACE.c
  * @author  Abdurahman_hamdi
  * @date    3-may-2020
  * @brief   character lcd Library interface implementation  file.*/


/*includes*/
#include "LCD_INTERFACE.h"





void lcd_init(port_data_type port,uint16_t rs_pin,uint16_t en_pin)
{
	delay_uint_config(delay_uint);
	set_port_pin_output(port,rs_pin,en_pin);//A target dependent function to configure lcd port and control pins as output

	rst_EN;
	lcd_cmd(lcd_wake_up_0);
	lcd_cmd(lcd_wake_up_1);
	lcd_cmd(set_4bit_functionality);
	lcd_cmd(display_off_cursor_blinking);
	lcd_cmd(clear_display_screen);
	delay(delay_2000us);
	lcd_cmd(increment_cursor);






}


void lcd_cmd(LCD_CMD cmd)
{
	uint8_t val=(uint8_t)(cmd>>4);
	write_port(lcd_port,val);
	rst_RS;
	set_EN;
	delay(delay_1us);
	rst_EN;
	delay(delay_100us);
	val=(uint8_t)(cmd&0x0f);
	write_port(lcd_port,val);
	rst_RS;
	set_EN;
	delay(delay_1us);
	rst_EN;
	delay(delay_100us);

}
void lcd_data(uint8_t character){
	uint8_t val=(uint8_t)(character>>4);
	write_port(lcd_port,val);
	set_RS;
	set_EN;
	delay(delay_1us);
	rst_EN;
	delay(delay_100us);
	val=(uint8_t)(character&0x0f);
	write_port(lcd_port,val);
	set_EN;
	delay(delay_1us);
	rst_EN;
	delay(delay_100us);



}
