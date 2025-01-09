#ifndef LCD_H
#define LCD_H

#include "SETUP.h"

/* Computes transition of two messages leaving the screen. */
void transitionLcd(String message1, String message2, int delayValue);

/* Computes display waiting effect while collecting data. */
void waitingEffect(String message, int delayValue);

/* Displays two messages on the two rows of the 1602 LCD. */
void displayLcd(String message1, String message2, int delayValue);

/* Displays initial LCD message when starting the circuit. */
void initialLcdMessage();

/* Displays sensors parameters. */
void displayCollectedData();

/* Displays custom character in the center of the LCD. */
void displaySymbol(byte symbol[][8]);

/* Displays custom sun character => marks LEDs lighting. */
void displaySun();

/* Displays custom wind character => marks FAN turning on. */
void displayWind();

/* Displays custom watering can character => marks PUMP watering the plant. */
void displayWater();

#endif
