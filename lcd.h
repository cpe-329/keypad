/**
 * lcd.h
 * 
 * Danica Fujiwara & Spencer Shaw
 * 
 * CPE 329-17/18 Spring 2019
 */

#ifndef LCD_H_
#define LCD_H_

//  1   2  3   4   5     6    7   8   9  10   11   12  13    14   15   16 
// VSS VDD V0  RS  RW    E   DB0 DB1 DB2 DB3  DB4  DB5  DB6  DB7 LED+ LED- 
// GND 3V3    P4.4 P4.5 P4.6                 P4.0 P4.1 P4.2 P4.3  5V  GND

#define DB4 P4_0  // P4.0
#define DB5 P4_1  // P4.1
#define DB6 P4_2  // P4.2
#define DB7 P4_3  // P4.3
#define RS  P4_4  // P4.4 aka Data/Instr
#define RW  P4_5  // P4.5
#define EN  P4_6  // P4.6

#define LCD_DB_PINS (DB7 | DB6 | DB5 | DB4)
#define LCD_PINS_MASK (EN | RW | RS| LCD_DB_PINS)  // P4.0-4.6

//  lcd Mode options
#define CMD_STARTUP       (0b00100000)
#define CMD_SET_2L_4B     (0b11000000)
#define CMD_DISP_CTL_OFF  (0b00001000)
#define CMD_DISP_CTL_D    (0b00001100)
#define CMD_DISP_CTL_DC   (0b00001110)
#define CMD_DISP_CTL_DCB  (0b00001111)
#define CMD_DISP_CTL_INIT CMD_DISP_CTL_D 
#define CMD_DISP_CLR      (0b00000001)
#define CMD_ENTRY_MODE    (0b00000110)
#define CMD_HOME          (0b00000010)


void lcd_init();
void lcd_command(char i);
void lcd_write(char i);
void lcd_write_str(char *s, int len);

inline void lcd_home();
inline void lcd_clear();
inline void lcd_disp_on();
inline void lcd_disp_off();
inline void lcd_blink_on();
inline void lcd_blink_off();
inline void lcd_cursor_on();
inline void lcd_cursor_off();

static inline void Nybble();
static inline void lcd_db_write(unsigned char i);

static inline void lcd_set_rs();
static inline void clear_RS();
// static inline void set_RW();
static inline void clear_RW();

inline void lcd_display_keypad(u8 key);
#endif /* LCD_H_ */
