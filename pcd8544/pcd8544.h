/*
 * pcd8544.h
 *
 *  Created on: 1 dec 2018
 *      Author: Wojciech Kolisz
 */

#ifndef PCD8544_PCD8544_H_
#define PCD8544_PCD8544_H_


#define LCD_DDR DDRB
#define LCD_PORT PORTB

#define LCD_DC PB1
#define LCD_CS PB2
#define LCD_MOSI PB3
#define LCD_MISO PB4
#define LCD_SCK PB5

#define LED_DDR DDRD
#define LED_PORT PORTD
#define LED PD5

#define DATA 1
#define CMD 0


void Lcd_Init();
void Lcd_Send(uint8_t dc, uint8_t data);


#endif /* PCD8544_PCD8544_H_ */
