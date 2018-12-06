/*
 * main.c
 *
 *  Created on: 1 dec 2018
 *      Author: Wojciech Kolisz
 */

#include <avr/io.h>
#include <util/delay.h>

#include "pcd8544/pcd8544.h"

int main()
{

	DDRD |= (1<<PD5);
	PORTD |= (1<<PD5);

	Lcd_Init();

	//_delay_ms(1000);

	Lcd_Clr();

	Lcd_Locate(0,0);
	Lcd_Char('A');
	Lcd_Locate(1,1);
	Lcd_Char('B');
	Lcd_Locate(2,2);
	Lcd_Char('C');
	Lcd_Locate(3,3);
	Lcd_Char('D');
	Lcd_Locate(4,4);
	Lcd_Char('E');
	Lcd_Locate(5,5);
	Lcd_Char('T'); 	Lcd_Char('E'); Lcd_Char('S'); Lcd_Char('T');


	Lcd_Upd();


	while(1)
	{

		//PORTD |= (1<<PD5);
		//_delay_ms(1000);
		//PORTD &= ~(1<<PD5);


	}
}


