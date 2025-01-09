#include "SETUP.h"
#include "DHT.h"

BH1750 lightSensor;
LiquidCrystal lcdDisplay(12, 11, 5, 4, 3, 2);
DHT dhtSensor(13, DHT11);

int lightIntensity = 0;
int temperature = 0;
int humidity = 0;
int soilMoisture = 0;

int timer = 0;
int fanTimer = 0;
int waterTimer = 0;

bool firstWater = true;
bool firstFan = true;
bool fanOn = false;

/**
 * @brief Initializes digital pins..
 *
 */
void setupDigital()
{
	///pinMode(LED_1, OUTPUT);
	///pinMode(LED_2, OUTPUT);
	pinMode(FAN, OUTPUT);
	pinMode(WATER, OUTPUT);
}

/**
 * @brief Initializes sensors.
 *
 */
void setupSensors()
{
	Wire.begin();
	lightSensor.begin();
    if (!lightSensor.begin()) {
    Serial.println("BH1750 sensor initialization failed!");
    while (1); // Stop the program if the sensor isn't working
}
	dhtSensor.begin();

}

/**
 * @brief Initializez timer interrupts.
 *
 */
void setupTimer()
{
	cli();

	/* initializes registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;

	/* generates interrupts at every 0.5 seconds */
	OCR1A = 31249;
	/* sets CTC mode */
	TCCR1B |= (1 << WGM12);
	/* sets 256 prescaler */
	TCCR1B |= (1 << CS12);

	/* enables timer compare interrupts */
	TIMSK1 |= (1 << OCIE1A);

	sei();

}

ISR(TIMER1_COMPA_vect) {
    timer++;  // Increment your global timer variable
}