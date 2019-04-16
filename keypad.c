/**
 * keypad.c
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#include "keypad.h"
#include "delay.h"
#include "msp.h"

void key_init(void){
    uint8_t col, row, key;
    P3->DIR = R1|R2|R3|R0;
    P3->REN = C1|C2|C3;
    P3->OUT &= ~(C1|C2|C3);
}

uint8_t keypad_getkey(void){
    uint8_t col, row;

    row_0_select()// put row high

    delay_ms(25); //delay for 25 cycles

    //col = P3->IN &(C1|C2|C3); // masks columns
    if(col_0_high())
       return 1;
    else if (col_1_high())
       return 2;
    else if (col_2_high())
       return 3;

    row_1_select()// put row high

    delay_ms(25); //delay for 25 cycles

    if(col_0_high())
       return 4;
    else if (col_1_high())
       return 5;
    else if (col_2_high())
       return 6;

    row_2_select()// put row high

    delay_ms(25); //delay for 25 cycles

    if(col_0_high())
        return 7;
    else if (col_1_high())
        return 8;
    else if (col_2_high())
        return 9;

    row_3_select()// put row high

    delay_ms(25); //delay for 25 cycles

    if(col_0_high())
        return 10;
    else if (col_1_high())
        return 0;
    else if (col_2_high())
        return 11;
}
