/**
 * main.c
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#include "stdint.h"

#include "msp.h"

#include "my_msp.h"
#include "delay.h"
#include "lcd.h"
#include "led.h"
#include "keypad.h"

#define FREQ FREQ_48_MHZ

void main(void)
{
//   char *hello_str = "A4 keypad";
	init(FREQ);

	test_leds();
	lcd_write('A');
	delay_ms(500, FREQ);
//    lcd_write_str(hello_str, 9);
    delay_ms(1000, FREQ);

	 while(1){
	    uint8_t key = keypad_getkey();
	 	leds_display_keypad(key);
	 	lcd_display_keypad(key);
	 }
}
