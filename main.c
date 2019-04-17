/*
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
	init(FREQ);  // Initialize periphrials
	test_leds();  // Blink LEDs to say hellow
	
	while(1){  // Loop
		uint8_t key = keypad_getkey();  // Read key from keypad
	 	leds_display_keypad(key);  // Display key on LEDs
	 	lcd_display_keypad(key);  // Display key on LCD
	}
}
