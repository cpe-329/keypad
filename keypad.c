/*
 * keypad.c
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#include "msp.h"
#include "my_msp.h"
#include "keypad.h"
#include "delay.h"
#include "led.h"

// Initialize keypad
inline void keypad_init(void){
    P2->SEL0 &= ~COL_MASK;  // Select GPIO mode
    P2->SEL1 &= ~COL_MASK;  // Select GPIO mode
    P2->DIR &= ~COL_MASK;  // Set columns to input mode
    P2->REN |= COL_MASK;  // Enable builtin resistors
    P2->OUT &= ~COL_MASK; // Set rows low  

    P5->SEL0 &= ~ROW_MASK;  // Select GPIO mode
    P5->SEL1 &= ~ROW_MASK;  // Select GPIO mode
    P5->DIR |= ROW_MASK;  // Set rows to output mode
    P5->OUT &= ~ROW_MASK; // Set rows low   
}

// Read the currently pressed key from the keypad
// Non-blocking, prioritizes some keys
uint8_t keypad_getkey(void){
    // Check all for no input
    row_all_select(); 
    delay_ms_auto(SETTLE_DELAY);
    if (col_all_read() == 0){
        // Nothing was pressed
        return 12;
    }

    // Check first row
    row_0_select();  // put row high
    delay_ms(SETTLE_DELAY, FREQ_48_MHZ); //delay for 25 cycles
    if(col_0_read())
       return 1;
    else if (col_1_read())
       return 2;
    else if (col_2_read())
       return 3;

    // Check second row
    row_1_select();  // put row high
    delay_ms_auto(SETTLE_DELAY); //delay for 25 cycles
    if(col_0_read())
       return 4;
    else if (col_1_read())
       return 5;
    else if (col_2_read())
       return 6;

    // Check thrid row
    row_2_select();  // put row high
    delay_ms_auto(SETTLE_DELAY); //delay for 25 cycles
    if(col_0_read())
        return 7;
    else if (col_1_read())
        return 8;
    else if (col_2_read())
        return 9;

    // Check fourth row
    row_3_select();  // put row high
    delay_ms_auto(SETTLE_DELAY);  //delay for 25 cycles
    if(col_0_read())
        return 10;
    else if (col_1_read())
        return 0;
    else if (col_2_read())
        return 11;
    // Nothing was pressed
    return 12;
}

inline static void row_all_select(){
    P5->OUT |= ROW_MASK;
}

inline static void row_0_select(){
    P5->OUT |= ROW0;
    P5->OUT &= ~(ROW1 | ROW2 | ROW3);
}

inline static void row_1_select(){
    P5->OUT |= ROW1;
    P5->OUT &= ~(ROW0 | ROW2 | ROW3);
}

inline static void row_2_select(){
    P5->OUT |= ROW2;
    P5->OUT &= ~(ROW0 | ROW1 | ROW3);
}

inline static void row_3_select(){
    P5->OUT |= ROW3;
    P5->OUT &= ~(ROW0 | ROW1 | ROW2);
}

inline static uint8_t col_all_read(){
    return P2->IN & COL_MASK;
}

inline static uint8_t col_0_read(){
    return P2->IN & COL0;
}

inline static uint8_t col_1_read(){
    return P2->IN & COL1;
}

inline static uint8_t col_2_read(){
    return P2->IN & COL2;
}
