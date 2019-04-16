/*
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

/* Keypad Pins: NC  A     B     C     D     E     F     G    NC
 * MSP Pins:       Px.y  Px.y  Px.y  Px.y  Px.y  Px.y  Px.y
 * Pin Name:       COL1  ROW0  COL0  ROW3  COL2  ROW2  ROW1
 *     
 */


#define ROW_MASK (P | P | P | P)
// Enumeration of rows
#define ROW_0_SELECT (BIT0)
#define ROW_1_SELECT (BIT1)
#define ROW_2_SELECT (2)
#define ROW_3_SELECT (3)


void key_init(void);
uint8_t keypad_getkey(void);

inline static void row_0_select();
inline static void row_1_select();
inline static void row_2_select();
inline static void row_2_select();

inline static u8 col_0_high();
inline static u8 col_1_high();
inline static u8 col_2_high();

inline u8 translate_keypad_rgb();

#endif
