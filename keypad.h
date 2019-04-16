/**
 * keypad.h
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "msp.h"
#include <stdint.h>

#include "my_msp.h"

void key_init(void);
uint8_t keypad_getkey(void);

#endif
