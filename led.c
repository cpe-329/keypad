/**
 * led.c
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#include "msp.h"

#include "my_msp.h"

#include "led.h"
#include "delay.h"

// Setup LED1
inline void led_init(void){
    P1->SEL0 &= ~BIT0;  // Set sel0 bit low for GPIO
    P1->SEL1 &= ~BIT0;  // Set sel1 bit low for GPIO
    P1->DIR |= GPIO_1_MODE_OUTPUT;  // Set P1.0 to output mode 
    P1->OUT &= ~LED1_STATE_ON;  //  Set LED1 state to off
}

// Toggle LED1
inline void led_toggle(void){
    P1->OUT ^= LED1_STATE_ON;  // XOR LED1 state to toggle
}

inline void led_on(void){
    P1->OUT |= LED1_STATE_ON;
}

inline void led_off(void){
    P1->OUT &= ~LED1_STATE_ON;
}

// Setup RGB LED
void rgb_init(void){
    P1->SEL0 &= ~PIN_RGB_SEL0_GPIO;  // Set sel0 bits low for GPIO
    P1->SEL1 &= ~PIN_RGB_SEL1_GPIO;  // Set sel1 bits low for GPIO
    P2->DIR |= GPIO_RGB_MODE_OUTPUT;  // Set P2.0 - P2.2 to output mode
    P2->OUT &= ~LED_RGB_STATE_ON;  // Set RGB LED state to off
}

// Set 3 bits of RGB LED
void rgb_set(int value){
    P2->OUT &= ~LED_RGB_STATE_ON;  // Clear previous RGB LED state
    P2->OUT |= (value & LED_RGB_STATE_ON);  // Set RGB LED state
}

