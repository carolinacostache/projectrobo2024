#include "LCD.h"

/**
 * @brief Computes transition of two messages leaving the screen.
 *
 * @param message1 first row message
 * @param message2 second row message
 * @param delayValue delay value used for transitioning
 */
void transitionLcd(String message1, String message2, int delayValue)
{
	for (int i = 0; i <= 16; ++i) {
		lcdDisplay.clear();

		/* first row leaving display to right */
		lcdDisplay.setCursor(i, 0);
		lcdDisplay.print(message1);

		/* second row leaving display to left */
		lcdDisplay.setCursor(0, 1);
		lcdDisplay.print(message2.substring(0, 16 - i));

		delay(10);
	}
}

/**
 * @brief Computes display waiting effect while collecting data.
 *
 * @param message displayed while waiting transition
 * @param delayValue delay value used for transitioning
 */
void waitingEffect(String message, int delayValue)
{
	lcdDisplay.clear();
	delay(1000);

	for (int i = 0; i <= 12; ++i) {
		lcdDisplay.clear();

		lcdDisplay.setCursor(0, 0);
		lcdDisplay.print(message);

		lcdDisplay.setCursor(0, 1);

		lcdDisplay.setCursor(i, 1);
		lcdDisplay.print("...");
		delay(100);

		lcdDisplay.setCursor(i, 1);
		lcdDisplay.print(".. .");
		delay(100);

		lcdDisplay.setCursor(i, 1);
		lcdDisplay.print(". ..");
		delay(100);

		lcdDisplay.setCursor(i, 1);
		lcdDisplay.print(" ...");

		delay(delayValue);
	}
}

/**
 * @brief Displays two messages on the two rows of the 1602 LCD.
 *
 * @param message1 first row message
 * @param message2 second row message
 * @param delayValue delay value used for transitioning
 */
void displayLcd(String message1, String message2, int delayValue)
{
	lcdDisplay.clear();

	lcdDisplay.setCursor(0, 0);
	lcdDisplay.print(message1);

	lcdDisplay.setCursor(0, 1);
	lcdDisplay.print(message2);

	delay(delayValue);
}

/**
 * @brief Displays initial LCD message when starting the circuit.
 *
 */
void initialLcdMessage()
{
	lcdDisplay.begin(16, 2);

	String message1 = "Welcome, I'm";
	String message2 = " a Lazy Garden! ";

	displayLcd(message1, message2, 3000);
	transitionLcd(message1, message2, 125);

	delay(2000);

	String message3 = "I do not require";
	String message4 = "your assistance!";

	displayLcd(message3, message4, 3000);
	transitionLcd(message3, message4, 125);

	delay(2000);
}

/**
 * @brief Displays sensors parameters.
 *
 */
void displayCollectedData()
{
	/* displays light intensity */
	displayLcd("Light Intensity:", String(String(lightIntensity) + " lx"),
		   3000);

	/* displays temperature */
	displayLcd("Temperature:", String(String(temperature) + " C"), 3000);

	/* displays humidity */
	displayLcd("Humidity:", String(String(humidity) + " %"), 3000);

	/* displays soil moisture */
	if (soilMoisture < WET_SOIL) {
		displayLcd("Soil Moisture:",
			   String(String(soilMoisture) + " is TOO WET"), 3000);
	} else if (soilMoisture > DRY_SOIL) {
		displayLcd("Soil Moisture:",
			   String(String(soilMoisture) + " is TOO DRY"), 3000);
	} else {
		displayLcd("Soil Moisture:",
			   String(String(soilMoisture) + " is PERFECT"), 3000);
	}
}

/**
 * @brief Displays custom character in the center of the LCD.
 *
 * @param symbol to be displayed
 */
void displaySymbol(byte symbol[][8])
{
	/* creates character */
	for (int i = 0; i < 8; ++i) {
		lcdDisplay.createChar(i, symbol[i]);
	}

	/* writes character */
	for (int i = 0; i < 4; ++i) {
		lcdDisplay.setCursor(6 + i, 0);
		lcdDisplay.write(byte(i));

		lcdDisplay.setCursor(6 + i, 1);
		lcdDisplay.write(byte(i + 4));
	}
}

/**
 * @brief Displays custom sun character => marks LEDs lighting.
 *
 */
void displaySun()
{
	byte sunSymbol[][8] = {
	    {B00000, B00000, B00010, B00001, B00000, B00000, B00000, B01111},
	    {B00000, B00100, B00010, B00010, B10000, B00011, B00111, B01111},
	    {B00000, B00100, B01000, B01000, B00000, B11001, B11100, B11110},
	    {B00000, B00000, B00000, B01000, B10000, B00000, B00000, B00000},
	    {B00000, B00000, B00000, B00001, B00010, B00000, B00000, B00000},
	    {B01111, B00111, B10011, B00000, B00010, B00010, B00100, B00000},
	    {B11110, B11100, B11000, B00001, B01000, B01000, B00100, B00000},
	    {B11110, B00000, B00000, B00000, B10000, B01000, B00000, B00000}};

	displaySymbol(sunSymbol);
}

/**
 * @brief Displays custom wind character => marks FAN turning on.
 *
 */
void displayWind()
{
	byte windSymbol[][8] = {
	    {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
	    {B00000, B00000, B00000, B10000, B11000, B10100, B10011, B11111},
	    {B00000, B00000, B00000, B11111, B10010, B10100, B11000, B11000},
	    {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
	    {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
	    {B00011, B00011, B00101, B01001, B11111, B00000, B00000, B00000},
	    {B11111, B11001, B00101, B00011, B00001, B00000, B00000, B00000},
	    {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
	};

	displaySymbol(windSymbol);
}

/**
 * @brief Displays custom watering can character => marks PUMP watering the
 * plant.
 *
 */
void displayWater()
{
	byte waterSymbol[][8] = {
	    {B00000, B00000, B01100, B10010, B10001, B01111, B00111, B11111},
	    {B00000, B00000, B00000, B10000, B11000, B11100, B11110, B11111},
	    {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
	    {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
	    {B11111, B00111, B00011, B00001, B00000, B00000, B00000, B00000},
	    {B11110, B11101, B11011, B10000, B00000, B00000, B00000, B00000},
	    {B00001, B10011, B11111, B00011, B00001, B00000, B00000, B00000},
	    {B00000, B00000, B10000, B00100, B00000, B00110, B00110, B00000}};

	displaySymbol(waterSymbol);
}
