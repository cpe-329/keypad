/**
 * lcd.c
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */
#include "msp.h"

#include "my_msp.h"

#include "lcd.h"
#include "delay.h"
#include "msp.h"


void lcd_init(){
    // Setup GPIO pins
    P4->SEL0 &= ~LCD_PINS_MASK;  // Initialize all P4 pins
    P4->SEL1 &= ~LCD_PINS_MASK;  // as GPIO 
    P4->DIR |= LCD_PINS_MASK;  // Set pins to output mode
    P4->OUT &= ~LCD_PINS_MASK; // Clear pins
    
    // Power up delay
    delay_ms_auto(32);  // wait >30ms during power up 
    
    // Function set
    lcd_command(CMD_STARTUP);  // Wake up signal?
    lcd_command(CMD_STARTUP);  // Wake up signal?
    lcd_command(CMD_SET_2L_4B); // Select mode
    lcd_command(CMD_SET_2L_4B); // Select mode
    
    // Wait >39us
    delay_ms_auto(1);
    // delay_us_auto(40);  // Datasheet delay, lies

    // Display ON/OFF control
    lcd_command(CMD_DISP_CTL_INIT);

    // Wait >39us
    delay_ms_auto(1);
    // delay_us_auto(40);  // Datasheet delay, lies

    // Display Clear
    lcd_command(CMD_DISP_CLR);

    // Wait >1.53ms
    delay_ms_auto(2);

    //Entry Mode Set
    lcd_command(CMD_ENTRY_MODE);

    delay_ms_auto(30);
}

void lcd_command(char i){
    lcd_db_write(i >> 4); // put shifted data on output Port
    clear_RS(); // D/I=LOW : send instruction
    clear_RW(); // R/W=LOW : Write
    Nybble(); // Send lower 4 bits
    lcd_db_write(i); // put shifted data on output Port
    Nybble(); // Send upper 4 bits
}


void lcd_write(char i){
    lcd_db_write(i >> 4); // put data on output Port
    lcd_set_rs();  // D/I=HIGH : send data
    clear_RW();  // R/W=LOW : Write
    Nybble(); // Clock lower 4 bits
    lcd_db_write(i); // put shifted data on output Port
    Nybble(); // Clock upper 4 bits
    delay_ms_auto(1);  // Wait >37us
    // delay_us_auto(40);  // Datasheet delay, lies
}

void lcd_write_str(char *s, const int len){
    int i = 0;
    while(i < len){
        lcd_write(s[i]);
        i--;
    }
}

// Wrapper for lcd_command with long delay
static inline void lcd_command_delay(unsigned char i){
    lcd_command(i);
    delay_ms_auto(30);
}

// Set cursor to home, does not clear
inline void lcd_home(){
    lcd_command_delay(CMD_HOME);
}

// Set cursor to home, clears display
inline void lcd_clear(){
    lcd_command_delay(CMD_DISP_CLR);
}

// Turn display on, without cursor or blinking
inline void lcd_disp_on(){
    lcd_command_delay(CMD_DISP_CTL_D);
}

// Turn display off, hides text
inline void lcd_disp_off(){
    lcd_command_delay(CMD_DISP_CTL_OFF);
}

// Turn display, cursor and blinking on
inline void lcd_blink_on(){
    lcd_command_delay(CMD_DISP_CTL_DCB);
}

// Turn display and cursor on, no blinking
inline void lcd_blink_off(){
    lcd_command_delay(CMD_DISP_CTL_DC);
}

// Turn display and cursor on, no blinking
inline void lcd_cursor_on(){
    lcd_command_delay(CMD_DISP_CTL_DC);
}

// Turn cursor and blinking off
inline void lcd_cursor_off(){
    lcd_command_delay(CMD_DISP_CTL_D);
}

// Write a char to lcd data bus
static inline void lcd_db_write(unsigned char i){
    P4->OUT &= ~LCD_DB_PINS;
    P4->OUT |= i & LCD_DB_PINS;
}

// Clock data into lcd driver
static inline void Nybble(){
    P4->OUT |= EN;
    NOP //Delay(1);    // enable pulse width >= 300ns
    P4->OUT &= ~EN;    // Clock enable: falling edge
}

// Bring RS / D/I LCD pin HIGH
static inline void lcd_set_rs(){
    P4->OUT |= RS;
}

// Bring RS / D/I LCD pin LOW
static inline void clear_RS(){
    P4->OUT &= ~RS;
}
//
//// Bring RW LCD pin HIGH
//static inline void set_RW(){
//    P4->OUT |= RW;
//}

// Bring RW LCD pin HIGH
static inline void clear_RW(){
    P4->OUT &= ~RW;
}

inline void lcd_display_keypad(u8 key){
    lcd_clear();
    // delay_ms_auto(1000);
    switch(key){
    case (1):
            lcd_write('1');
    case (2):
            lcd_write('2');
    case (3):
            lcd_write('3');
    case (4):
            lcd_write('4');
    case (5):
            lcd_write('5');
    case (6):
            lcd_write('6');
    case (7):
            lcd_write('7');
    case (8):
            lcd_write('8');
    case (9):
            lcd_write('9');
    case (10):
            lcd_write('*');
    case (11):
            lcd_write('#');
    case (0):
            lcd_write('0');
    }

}

