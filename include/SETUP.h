#ifndef SETUP_H
#define SETUP_H

#include <BH1750.h>
#include <DHT.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#define LED_1 6
#define LED_2 8
#define SOIL A0
#define FAN 10
#define WATER 7

#define WET_SOIL 500
#define DRY_SOIL 750

#define LIGHT_LOW 10
#define LIGHT_HIGH 80

#define TEMPERATURE_HIGH 24

#define MINUTE 120
#define FAN_ON 30 * MINUTE
#define FAN_OFF 10 * MINUTE
#define WATER_OFF 60 * MINUTE
#define COLLECT_DATA MINUTE

/* light intensity sensor */
extern BH1750 lightSensor;
/* LCD display */
extern LiquidCrystal lcdDisplay;
/* temperature and humidity sensor */
extern DHT dhtSensor;

/* read sensor values */
extern int lightIntensity;
extern int temperature;
extern int humidity;
extern int soilMoisture;

/* timer used for collecting data */
extern int timer;
/* timer used for measuring time spent by the fan, either on or off */
extern int fanTimer;
/* timer used for measuring time spent between two following waterings */
extern int waterTimer;

extern bool firstWater;
extern bool firstFan;
extern bool fanOn;

/* Initializes digital pins. */
void setupDigital();

/* Initializes sensors. */
void setupSensors();

/* Initializez timer interrupts. */
void setupTimer();

#endif
