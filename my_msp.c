/**
 * my_msp.c
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#include "msp.h"

#include "my_msp.h"

#include "led.h"
#include "delay.h"
#include "lcd.h"


void init(unsigned int freqeuncy){
    DISABLE_WATCHDOG

    init_dco();
	set_dco(freqeuncy);

	led_init();

	lcd_init();
}