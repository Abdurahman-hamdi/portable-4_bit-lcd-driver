/**
  ******************************************************************************
  * @file    LCD_INTERFACE.h
  * @author  Abdurahman_hamdi
  * @date    3-may-2020
  * @brief   character lcd Library interface file.*/

#ifndef _lcd_interface_
#define _lcd_interface_
/* Includes */
#include "port.h"

#define rst_RS   rst_rs_port
#define set_RS   set_rs_port
#define rst_EN   rst_en_port
#define set_EN   set_en_port


typedef enum
{
	clear_display_screen                     =0x01,
    return_home                              =0x02,
	decrement_cursor                         =0x04,
	increment_cursor                         =0x06,
	shift_display_right                      =0x05,
	shift_display_lift                       =0x07,
	display_off_cursor_off                   =0x08,
	display_off_cursor_on                    =0x0A,
	display_on_cursor_0ff                    =0x0C,
	display_off_cursor_blinking              =0x0E,
	display_on_cursor_blinking               =0x0F,
	shift_cursor_position_to_lift            =0x10,
	shift_cursor_position_to_right           =0x14,
	shift_the_entire_display_to_lift         =0x18,
	shift_the_entire_display_to_right        =0x1C,
	set_4bit_functionality                   =0x28,
	force_cursor_to_beginning__of_1st_line   =0x80,
	force_cursor_to_beginning__of_2st_line   =0xC0,
	set_2lines_5in7_matrix                   =0x38,
	lcd_wake_up_0                            =0x33,
	lcd_wake_up_1                            =0x32

}LCD_CMD;

typedef enum
{
	RS_CMD_SELECT =0X00,
	RS_DATA_SELECT=0X01
}REGISTER_SELECT;

typedef enum{

	lcd_write=0x00,
	lcd_read =0x01
} r_w_select;




//functions declaration

void lcd_init(port_data_type,uint16_t,uint16_t);
void lcd_cmd(LCD_CMD );
void lcd_data(uint8_t);

#endif
