#include "msp.h"

#include "watchdog.h"
#include "lcd.h"
#include "led.h"
#include "delay.h"

#define FREQ FREQ_24_MHZ

void main(void)
{
	DISABLE_WATCHDOG  // stop watchdog timer
	
    led1_on();  // Turn on LED

    lcd_blink_on();  // Turn on blinking cursor

	Write_char_LCD('A');  // Write character to LCD
    
    led1_off();  // Turn off LED
}
