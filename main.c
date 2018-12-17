/*
 * main.c
 *
 *  Created on: 1 dec 2018
 *      Author: Wojciech Kolisz
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "pcd8544/pcd8544.h"
#include "picture_bmp.h"

int main()
{

	DDRD |= (1<<PD5);
	PORTD |= (1<<PD5);

	Lcd_Init();
	Lcd_Clr();

	//examples of use

	Lcd_Locate(0,0);
	Lcd_Char('A');
	Lcd_Locate(1,1);
	Lcd_Char(66);
	Lcd_Locate(2,2);
	Lcd_Str("T");
	Lcd_Locate(3,3);
	Lcd_Str("Test");
	Lcd_Locate(4,4);
	Lcd_Str("Test RanD0m");
	Lcd_Locate(5,5);
	Lcd_Int(123, DEC);

	Lcd_Upd();

	_delay_ms(2000);

	Lcd_Img(Picture_Img);
	Lcd_Upd();

	_delay_ms(2000);


	uint8_t a = 0;

	while(1)
	{

		Lcd_Clr();
		Lcd_Locate(0,0);
		Lcd_Str("var ");
		Lcd_Int(a, HEX);
		Lcd_Locate(0,1);
		Lcd_Str("var ");
		Lcd_Int(a, DEC);
		Lcd_Locate(0,2);
		Lcd_Str("var ");
		Lcd_Int(a, BIN);
		Lcd_Locate(0,3);

		Lcd_Upd();

		_delay_ms(1000);
		a++;
	}
}


