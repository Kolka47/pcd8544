/*
 * pcd8544.c
 *
 *  Created on: 1 dec 2018
 *      Author: Wojciech Kolisz
 */
#include <avr/io.h>
#include "pcd8544.h"


void Lcd_Init()
{
	//MOSI SCK outputs
	LCD_DDR |= (1<<LCD_MOSI) | (1<<LCD_SCK);
	LCD_PORT |= (1<<LCD_MOSI)|(1<<LCD_SCK);
	//SPI enable, master, clk/4
	SPCR |= (1<<SPE)|(1<<MSTR);

	//DC & CS outputs
	LCD_DDR |= (1<<LCD_DC)|(1<<LCD_CS);
	LCD_PORT &= ~(1<<LCD_CS);

	//basic instructions set
	Lcd_Send(CMD, 0b00100000);


}



void Lcd_Send(uint8_t dc, uint8_t data)
{
	if(dc == 0) LCD_PORT &= ~(1<<LCD_DC);
	else LCD_PORT |= (1<<LCD_DC);

	//start spi transmision
	SPDR = data;
	//wait for transmision completed
	while(!(SPSR & (1<<SPIF)));
}



