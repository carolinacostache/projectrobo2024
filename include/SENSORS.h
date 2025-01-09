#ifndef SENSORS_H
#define SENSORS_H

#include "LCD.h"
#include "SETUP.h"

/* Reads light intensity value and turns on the LEDs if needed. */
void readLight();

/* Reads temperature value and turns on fan if needed. */
void readTemperature();

/* Reads humidity value. */
void readHumidity();

/* Reads soil moisture value and waters the plant through the pump is needed. */
void readMoisture();

#endif
