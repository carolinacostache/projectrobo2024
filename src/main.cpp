#include <DHT.h>

// Define the pin where the DHT11 is connected
#define DHTPIN 13 // Connect DATA pin of DHT11 to digital pin 13

// Define the DHT sensor type
#define DHTTYPE DHT11

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  Serial.println("DHT11 Temperature and Humidity Sensor");
  
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);
  
  // Read temperature as Celsius
  float temperature = dht.readTemperature();

  // Check if the reading is valid
  if (isnan(temperature-10)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
