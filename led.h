/**
 * led.h
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#ifndef __LED_H__
#define __LED_H__

#include "msp.h"

#include "my_msp.h"

#define LED1_PIN P1_0
#define RGB_LED_PINS (P2_0 | P2_1 | P2_2)

#define PIN_SEL0_GPIO      LED1_PIN
#define PIN_SEL1_GPIO      LED1_PIN
#define GPIO_1_MODE_OUTPUT LED1_PIN
#define LED1_STATE_ON      LED1_PIN

#define PIN_RGB_SEL0_GPIO    RGB_LED_PINS
#define PIN_RGB_SEL1_GPIO    RGB_LED_PINS
#define GPIO_RGB_MODE_OUTPUT RGB_LED_PINS
#define LED_RGB_STATE_ON     RGB_LED_PINS

// Setup LED1
inline void led_init(void);

// Toggle LED1
inline void led_toggle(void);
inline void led_on(void);
inline void led_off(void);

// Setup RGB LED
void rgb_init(void);

// Set 3 bits of RGB LED
void rgb_set(int value);

#endif
