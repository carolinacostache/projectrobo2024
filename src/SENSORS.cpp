#include "SENSORS.h"

/**
 * @brief Reads light intensity value and turns on the LEDs if needed.
 *
 */
void readLight()
{
	/* reads light intensity from the sensor */
	lightIntensity = lightSensor.readLightLevel();

	/* light intensity is low*/
	if (lightIntensity < LIGHT_LOW) {
		lcdDisplay.clear();

		/* displays sun character */
		displaySun();

		/* turns on LEDs */
		digitalWrite(LED_1, HIGH);
		digitalWrite(LED_2, HIGH);

		delay(2000);
		lcdDisplay.clear();

		/* rereads light intensity after adjusting light */
		lightIntensity = lightSensor.readLightLevel();

		/* light intensity is high */
	} else if (lightIntensity > LIGHT_HIGH) {
		/* turns off LEDs */
		digitalWrite(LED_1, LOW);
		digitalWrite(LED_2, LOW);
		delay(500);

		/* rereads light intensity after adjusting light */
		lightIntensity = lightSensor.readLightLevel();
	}
}

/**
 * @brief Reads temperature value and turns on fan if needed.
 *
 */
void readTemperature()
{
	/* reads temperature value from the sensor */
	temperature = dhtSensor.readTemperature();

	if (temperature > TEMPERATURE_HIGH) {
		/* first time the fan is turned on */
		if (firstFan) {
			firstFan = false;
			fanOn = true;

			/* starts timer for measuring fan on */
			fanTimer = 0;

			lcdDisplay.clear();

			/* displays wind character */
			displayWind();

			/* turns on the fan */
			digitalWrite(FAN, HIGH);

			delay(2000);
			lcdDisplay.clear();

			/* next times the fan is turned on */
		} else if (!fanOn) {
			/* fan has been off for a period of time */
			if (fanTimer >= FAN_OFF) {
				fanOn = true;

				/* starts timer for measuring fan on */
				fanTimer = 0;

				lcdDisplay.clear();

				/* displays wind character */
				displayWind();

				/* turns on the fan */
				digitalWrite(FAN, HIGH);

				delay(2000);
				lcdDisplay.clear();
			}
		}
	}
}

/**
 * @brief Reads humidity value.
 *
 */
void readHumidity()
{
	/* reads humidity value from the sensor */
	humidity = dhtSensor.readHumidity();
}

/**
 * @brief Reads soil moisture value and waters the plant through the pump is
 * needed.
 *
 */
void readMoisture()
{
	/* reads soil moisture from the sensor */
	soilMoisture = analogRead(SOIL);

	/* soil is dry */
	if (soilMoisture > DRY_SOIL) {
		/* first time the pump is turned on */
		if (firstWater) {
			firstWater = false;

			lcdDisplay.clear();

			/* displays watering can character */
			displayWater();
			delay(2000);
			lcdDisplay.clear();

			/* waters plant */
			digitalWrite(WATER, HIGH);
			delay(3000);
			digitalWrite(WATER, LOW);

			/* starts timer for measuring pump off */
			waterTimer = 0;

			/* next times the pump is turned on => if the plant has
			 * not been watered for a period of time
			 */
		} else if (waterTimer >= WATER_OFF) {
			lcdDisplay.clear();

			/* displays watering can character */
			displayWater();
			delay(2000);
			lcdDisplay.clear();

			/* waters plant */
			digitalWrite(WATER, HIGH);
			delay(3000);
			digitalWrite(WATER, LOW);

			/* starts timer for measuring pump off */
			waterTimer = 0;
		}
	}
}
