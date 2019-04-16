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
#include "keypad.h"

#define DCO_FREQ FREQ_24_MHZ

void main(void)
{
	init(DCO_FREQ);

	while(1){
		rgb_set(translate_keypad_rgb(keypad_getkey()));
	}
}
