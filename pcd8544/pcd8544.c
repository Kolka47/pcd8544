/*
 * pcd8544.c
 *
 *  Created on: 1 dec 2018
 *      Author: Wojciech Kolisz
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include "pcd8544.h"

static uint8_t lcd_buffer[LCD_BUF_SIZE];
static uint16_t lcd_location;



//Lcd_Init() function initialize hardware SPI in MCU, and then sends some
//initializing commands
void Lcd_Init()
{
	//MOSI SCK outputs
	LCD_DDR |= (1<<LCD_MOSI) | (1<<LCD_SCK)|(1<<LCD_DC)|(1<<LCD_CS)|(1<<LCD_RST);
	//SPI enable, master, clk/4
	SPCR |= (1<<SPE)|(1<<MSTR);

	//reset signal
	LCD_PORT &= ~(1<<LCD_RST);
	_delay_ms(20);
	LCD_PORT |= (1<<LCD_RST);

	//basic instructions set (H = 0)
	Lcd_Send(CMD, 0b00100000);	//function set
	Lcd_Send(CMD, 0b00001100);	//display control
	Lcd_Send(CMD, 0b01000000);	//set y address of RAM
	Lcd_Send(CMD, 0b10000000);	//set x address od RAM

	//extended instructions (H = 1)
	Lcd_Send(CMD, 0b00100001);	//function set H = 1
	Lcd_Send(CMD, 0b00000110);	//temperature control 2
	Lcd_Send(CMD, 0b00010011);	//bias 1:48
	Lcd_Send(CMD, 0b11000000);	//contrast


}

//Lcd_Send(dc, data) function sends data/command to pcd8544.
//First argument decides which one data or command will be send (1 = Data, 0 = Command)
//Second argument is 8-bit value to send
void Lcd_Send(uint8_t dc, uint8_t data)
{
	LCD_PORT &= ~(1<<LCD_CS);

	if(dc == 0) LCD_PORT &= ~(1<<LCD_DC);
	else LCD_PORT |= (1<<LCD_DC);

	//start spi transmision
	SPDR = data;
	//wait for transmision completed
	while(!(SPSR & (1<<SPIF)));

	if(dc == 0) LCD_PORT |= (1<<LCD_DC);
	else LCD_PORT &= ~(1<<LCD_DC);

	LCD_PORT |= (1<<LCD_CS);
}

//Lcd_Upd() function, sends the lcd_buffer on screen using Lcd_Send() function.
//Whatewer is in the lcd_buffer, will be displayed on screen
void Lcd_Upd()
{
	for(uint16_t i = 0; i < LCD_BUF_SIZE; i++)
		Lcd_Send(DATA, lcd_buffer[i]);
}


//Lcd_Clr() function clears lcd_buffer by filling it with zeros.
//After using Lcd_Upd(), lcd screen will be cleared
void Lcd_Clr()
{

	for(uint16_t i = 0; i < LCD_BUF_SIZE; i++)
		lcd_buffer[i] = 0;

}

//Add letter to Lcd_buffer
void Lcd_Char(uint8_t a)
{

	a -= 32;	//convert to ascii

	for (uint8_t i = 0; i<5; i++, lcd_location++)
		lcd_buffer[lcd_location] = Font[a][i];

		lcd_buffer[lcd_location] = 0;	//add empty space after letter
		lcd_location++;

}

void Lcd_Str(char *string)
{
	uint8_t i = 0;

	while(string [i] != 0)
	{
		Lcd_Char(string[i]);
		i++;
	}
}

void Lcd_Int( int number)
{
	char temp[10];

	Lcd_Str(itoa(number,temp,10));

}

void Lcd_Locate(uint8_t x, uint8_t y)
{

	//limit location to max values
	if(x > 83) x = 83;
	if(y > 5) y = 5;

	lcd_location = 84*y + x;

}




