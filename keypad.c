/**
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

inline void keypad_init(void){
    P2->SEL0 &= ~COL_MASK;
    P2->SEL1 &= ~COL_MASK;
    P2->DIR |= COL_MASK;
    P2->REN |= COL_MASK;
    P2->OUT &= ~COL_MASK;

    P5->SEL0 &= ~ROW_MASK;
    P5->SEL1 &= ~ROW_MASK;
    P5->DIR &= ~ROW_MASK;   
}

uint8_t keypad_getkey(void){
    row_all_select();
    delay_ms_auto(1);
    if (col_all_read())
        return 12;

    row_0_select();  // put row high
    delay_ms_auto(1); //delay for 25 cycles
    if(col_0_read())
       return 1;
    else if (col_1_read())
       return 2;
    else if (col_2_read())
       return 3;

    row_1_select();  // put row high
    delay_ms_auto(1); //delay for 25 cycles
    if(col_0_read())
       return 4;
    else if (col_1_read())
       return 5;
    else if (col_2_read())
       return 6;

    row_2_select();  // put row high
    delay_ms_auto(1); //delay for 25 cycles
    if(col_0_read())
        return 7;
    else if (col_1_read())
        return 8;
    else if (col_2_read())
        return 9;

    row_3_select();  // put row high
    delay_ms_auto(1);  //delay for 25 cycles
    if(col_0_read())
        return 10;
    else if (col_1_read())
        return 0;
    else if (col_2_read())
        return 11;
    return 12;
}

inline static void row_all_select(){
    P2->OUT |= COL_MASK;
}

inline static void row_0_select(){
    P2->OUT |= ROW0;
    P2->OUT &= ~(ROW1 | ROW2 | ROW3);
}

inline static void row_1_select(){
    P2->OUT |= ROW1;
    P2->OUT &= ~(ROW0 | ROW2 | ROW3);
}

inline static void row_2_select(){
    P2->OUT |= ROW2;
    P2->OUT &= ~(ROW0 | ROW1 | ROW3);
}

inline static void row_3_select(){
    P2->OUT |= ROW3;
    P2->OUT &= ~(ROW0 | ROW1 | ROW2);
}

inline static u8 col_all_read(){
    return P5->IN & COL_MASK;
}

inline static u8 col_0_read(){
    return P5->IN & COL0;
}

inline static u8 col_1_read(){
    return P5->IN & COL1;
}

inline static u8 col_2_read(){
    return P5->IN & COL2;
}
