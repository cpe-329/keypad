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
 * MSP Pins:       P2.6  P5.0  P2.5  P5.7  P2.7  P5.6  P5.1
 * Pin Name:       COL1  ROW0  COL0  ROW3  COL2  ROW2  ROW1
 *     
 */

#define COL0 BIT5
#define COL1 BIT6
#define COL2 BIT7

#define ROW0 BIT0
#define ROW1 BIT1
#define ROW2 BIT2
#define ROW3 BIT3

#define COL_MASK (COL2 | COL1 | COL0)
#define ROW_MASK (ROW3 | ROW2 | ROW1 | ROW0)

#define SETTLE_DELAY 30

inline void keypad_init(void);
u8 keypad_getkey(void);

inline static void row_all_select();
inline static void row_0_select();
inline static void row_1_select();
inline static void row_2_select();
inline static void row_3_select();

inline static u8 col_all_read();
inline static u8 col_0_read();
inline static u8 col_1_read();
inline static u8 col_2_read();


#endif
