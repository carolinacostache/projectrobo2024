#include "SETUP.h"
#include "Arduino.h"
#include "LCD.h"
#include "SENSORS.h"

void collectData() {
    temperature = dhtSensor.readTemperature();
    humidity = dhtSensor.readHumidity();
    lightIntensity = lightSensor.readLightLevel();
    soilMoisture = analogRead(SOIL);
    Serial.println("Data Collected:");
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.print("Light Intensity: ");
    Serial.println(lightIntensity);
    Serial.print("Soil Moisture: ");
    Serial.println(soilMoisture);
    Serial.println("------------------------");
}


void setup() {
    ///displayLcd("Hi", "hi", 3000);
    Serial.begin(9600);
    initialLcdMessage();
    setupDigital();
    setupSensors();
    setupTimer();
    collectData();
}

void loop() {
    // Collect data periodically
    if (timer >= COLLECT_DATA) {
        collectData();
        displayCollectedData();
        timer = 0; // Reset timer
    }

    // Fan control logic
    if (fanOn) {
        if (fanTimer >= FAN_ON) {
            fanOn = false;
            fanTimer = 0;
            digitalWrite(FAN, LOW); // Turn off fan
        }
    } else {
        if (temperature > TEMPERATURE_HIGH) {
            if (firstFan) {
                firstFan = false;
                fanOn = true;
                fanTimer = 0; // Reset fan timer
                digitalWrite(FAN, HIGH); // Turn on fan
            } else if (fanTimer >= FAN_OFF) {
                fanOn = true;
                fanTimer = 0; // Reset fan timer
                digitalWrite(FAN, HIGH); // Turn on fan
            }
        }
    }

    // Light control logic
    lightIntensity = lightSensor.readLightLevel();
    if (lightIntensity < LIGHT_LOW) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        lightIntensity = lightSensor.readLightLevel(); // Re-read after adjustment
    } else if (lightIntensity > LIGHT_HIGH) {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        delay(500);
        lightIntensity = lightSensor.readLightLevel(); // Re-read after adjustment
    }

    // Soil moisture control logic
    soilMoisture = analogRead(SOIL);
    if (soilMoisture > DRY_SOIL) {
        if (firstWater) {
            firstWater = false;
            digitalWrite(WATER, HIGH);
            delay(2000);
            digitalWrite(WATER, LOW);
            waterTimer = 0; // Reset water timer
        } else if (waterTimer >= WATER_OFF) {
            digitalWrite(WATER, HIGH);
            delay(2000);
            digitalWrite(WATER, LOW);
            waterTimer = 0; // Reset water timer
        }
    }
}
