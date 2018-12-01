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
	PORTD &= ~(1<<PD5);


	while(1)
	{

		PORTD ^= (1<<PD5);

		_delay_ms(1000);
	}
}


