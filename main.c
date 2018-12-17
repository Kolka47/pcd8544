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

	//_delay_ms(1000);



	Lcd_Clr();

	Lcd_Locate(0,0);
	Lcd_Str("adfgfdgfdgfdgfdfgfdgfdgfjhgjhgjhgjhgjhgjhgdgfdgfdgfdgdfgsgf");


	Lcd_Upd();

	_delay_ms(5000);

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
		Lcd_Char('~');

		Lcd_Upd();

		_delay_ms(1000);
		a++;
	}
}


