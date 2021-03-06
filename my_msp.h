/*
 * my_msp.h
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#ifndef __MY_MSP_H__
#define __MY_MSP_H__


// Port 1
#define P1_0 BIT0  // P1.0

// Port 2
#define P2_0 BIT0  // P2.0
#define P2_1 BIT1  // P2.1
#define P2_2 BIT2  // P2.2
 
// Port 4
#define P4_0 BIT0  // P4.0
#define P4_1 BIT1  // P4.1
#define P4_2 BIT2  // P4.2
#define P4_3 BIT3  // P4.3
#define P4_4 BIT4  // P4.4
#define P4_5 BIT5  // P4.5
#define P4_6 BIT6  // P4.6

// Macro for disabling watchdog
#define DISABLE_WATCHDOG  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

// Initialize all used periphrials
inline void init(const unsigned int freq);

#endif
