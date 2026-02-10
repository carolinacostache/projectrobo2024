# Lazy Indoor Garden 🌱✨

DISCLAIMER: this is still a work in progess, it can be subject to changes.

## Introduction 📚
This project is a small garden located within an apartment, where the temperature, water level, and light are adjusted according to the type of plants in the garden. The temperature, humidity, and light levels will be monitored using sensors placed in the garden. The measured parameters will be displayed on an LCD, ensuring optimal plant growth.

The inspiration for this project came from my desire to stop unintentionally harming houseplants due to improper care. I realized that many people struggle to maintain the ideal conditions for indoor plants, leading to frustration and disappointment, so with this project, I aim to solve that problem by automating the process and ensuring plants are cared for properly, even with minimal attention.

## Description 🌳
The input part of the project consists of using multiple sensors that read, at well-defined time intervals, the environmental parameters specified in the previous section, thereby providing control data for the automated system.

Thus, detecting a temperature above the allowable limits triggers the activation of a fan to partially reduce the excessive heat, which could harm the plant. Additionally, an LED system is used for ambient lighting in the flower nursery, which can be activated on cloudy days, at dusk, or by any other factor that reduces the amount of natural or artificial light received.

Watering is a crucial element in plant care. In this system, it is managed by a water pump that activates whenever the soil moisture sensor detects dry conditions.

The sensor data is displayed to users on an LCD screen, with updates provided at regular intervals.

## Hardware Design - Milestone 2
### LCD 1602:
- Role: Displays information about temperature, humidity, light levels, and soil moisture.
- Interface: Connected via I2C interface.
- Arduino Pins: D2, D3, D4, D5, D11, D12.

### DHT11 Temperature and Humidity Sensor:
- Role: Measures temperature and humidity in the air.
- Interface: Connected to a digital pin on the Arduino.
- Arduino Pins: D13.

### Soil Moisture Sensor:
- Role: Measures the soil moisture to determine whether the water pump needs to be activated.
- Interface: Connected to an analog pin on the Arduino.
- Arduino Pins: A0.

### BH1750 Light Intensity Sensor:
- Role: Measures the light level in the environment to decide whether to turn on the LEDs.
- Interface: I2C interface.
- Arduino Pins: A4, A5.

### Fan:
- Role: Activates when the temperature exceeds a certain threshold to cool the air around the plants.
- Interface: Connected to a relay, which is controlled by a digital pin on the Arduino.
- Arduino Pins: Digital pin controlled via an NPN transistor to activate the relay.
- Energy Consumption: Approximately 150-200 mA.

### Water Pump:
- Role: Activated when the soil moisture sensor detects low moisture levels.
- Interface: Connected to a relay controlled by the Arduino.
- Arduino Pins: Digital pin controlling the relay through an NPN transistor.
- Energy Consumption: Approximately 100-150 mA.

### Relay:
- Role: Allows switching high-power components (fan, water pump).
- Interface: Controlled by the Arduino through an NPN transistor.

## Block Diagram 🖼
![Block Diagram](<images/Lazy Indoor Garden 🌱✨.png>)

## Electric Scheme ⚡
![Scheme](<images/fingers crossed.png>)

## Bill of Materials 🔩
| Name | Photo | Source | Technical Characteristics |
|:------------:|:--------------:|:-------------:|:-------------:|
|Arduino UNO ATmega328P |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.14 PM.jpeg>)|Kit |[Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)|
|Mini-Breadboard |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (9).jpeg>)|Kit |-|
|Breadboard |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (8).jpeg>)|[Store](https://www.emag.ro/breadboard-830-puncte-mb102-cl01/pd/DF0C5JBBM/?ref=history-shopping_404566740_38837_4)|-|
|LCD 1602 Module |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (1).jpeg>)|Kit|[Datasheet](https://www.waveshare.com/datasheet/LCD_en_PDF/LCD1602.pdf)|
|LEDs 5 mm|![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (7).jpeg>)|Kit|-|
|Fan |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (5).jpeg>)|[Store](https://www.emag.ro/ventilator-pc-lhr-super-fan-80x80x25mm-3000rpm-12v-0-20a-lhr-80-2p-b/pd/DTFH9BMBM/?ref=history-shopping_404566740_5919_1)|Airflow (CFM): 41.2 <br> Speed: 3000 RPM <br> Dimensions: 80 x 80 x 25 mm <br> Noise Level (dB): 34 dB <br> Voltage: 12 V <br> Weight: 54 g|
|Water Pump 3-5V|![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (6).jpeg>)|[Store](https://www.emag.ro/pompa-de-apa-3-6v-cl88/pd/D91Z5JBBM/)| Voltage: DC 3-5V <br> Current: 100-200mA <br> Flow Rate: 1.2-1.6 L/min <br> Weight: 28 grams <br> Material: Plastic <br> Outer Nozzle Diameter: 7.5mm <br> Inner Nozzle Diameter: 4.7mm <br> Diameter: Approximately 24mm <br> Length: Approximately 45mm <br> Height: Approximately 33mm <br> Recommended Continuous Operating Time: <br> Should not exceed 500 hours <br> Color: White |
|Transistor NPN||Kit|[Datasheet](https://www.sparkfun.com/datasheets/Components/2N3904.pdf)|
|Temperature and Humidity Sensor DHT11|![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (4).jpeg>)|[Store](https://www.emag.ro/modul-de-temperatura-si-umiditate-dht11-senzor-de-temperatura-umiditate-consum-mediu-de-curent-redus-14-mm-x-20-mm-albastru-g1/pd/D93G1QYBM/?ref=history-shopping_404566740_158626_1)|[Datasheet](https://components101.com/sites/default/files/component_datasheet/DFR0067%20DHT11%20Datasheet.pdf)|
|Soil Moisture Sensor |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM.jpeg>)|[Store](https://www.emag.ro/modul-cu-senzor-umiditate-sol-cl73/pd/D5ZZ5JBBM/?ref=history-shopping_404566740_38837_2)|[Datasheet](https://www.alldatasheet.com/view.jsp?Searchword=LM39)|
|Light Intensity Sensor BH1750|![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (3).jpeg>)|[Store](https://www.emag.ro/senzor-lumina-robofun-gy-302-bh1750-00005472/pd/D6M30YYBM/?ref=history-shopping_404566740_12161_1)|[Datasheet](https://www.handsontec.com/dataspecs/sensor/BH1750%20Light%20Sensor.pdf)|
|Resistors |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.16 PM.jpeg>)|Kit|-|
|Battery Holder ||[Store](https://www.emag.ro/suport-4-baterii-robofun-aaa-cu-cablu-de-conectare-00002876/pd/DBGSN3YBM/?ref=history-shopping_404566740_12161_2)|-|
|Batteries ||-|-|
|Colorful Wires |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.16 PM (1).jpeg>)|Kit|-|
|Capacitor ||Kit|-|
|Diode ||Kit|-|
|Relay |![PHOTO](<images/BOM/WhatsApp Image 2024-12-16 at 11.22.15 PM (2).jpeg>)|Kit|-|

## Hardware Gallery 📷
![](<images/1st Harware check/WhatsApp Image 2024-12-19 at 2.10.21 PM.jpeg>)
![](<images/1st Harware check/WhatsApp Image 2024-12-19 at 2.10.22 PM (1).jpeg>)
![](<images/1st Harware check/WhatsApp Image 2024-12-19 at 2.10.22 PM (2).jpeg>)
![](<images/1st Harware check/WhatsApp Image 2024-12-19 at 2.10.22 PM.jpeg>)

## Video with the temperature sensor functionality 🎥
[Video](https://youtu.be/YjUPRb3dIJw)

## Software Design - Milestone 3

## Code Structure
For a better understanding of the code structure, in the implementation, I used different auxiliary files to organize the logic.
- SETUP.cpp/SETUP.h ⇒ As the names suggests, it contains the implementation of functions used for initializing the necessary parameters (the pins for the fan, LEDs and water pump, the sensors and the timer for interruptions)
- LCD.cpp/LCD.h ⇒ it contains functions for displaying information on the LCD display (message animations, displaying the main environmental parameters, a little fun surprise)
- SENSORS.cpp/SENSORS.h ⇒ it contains implementations used for reading the values of the main parameters recorded by the sensors present in the circuit, as well as triggering the operation of the output components, depending on certain conditions that will be detailed late
- main.cpp ⇒ it contains he main logic of the program

## Program Flow
The circuit operates independently of human assistance. Human intervention is only required to refill the water reservoir used for watering the plant.
Once activated, the circuit performs the following steps:
- setup ⇒ Uses the previously defined files and functions
- loop ⇒ Similar to the setup method, it uses the previously defined files and methods

Using a time counter variable and an interrupt handling routine, new data is collected at regular intervals of about one minute. Between two consecutive data recordings, the sampled values from the last collection (Light Intensity, Temperature, Humidity, and Soil Moisture) are displayed on the screen.

When collecting the data, certain threshold parameters are checked, which may trigger the operation of one of the output components.
The fan is turned on when, after data collection, the ambient temperature exceeds the optimal temperature for an indoor plant (~24°C).
Once turned on, the fan will run for a certain preset period of time (currently set to approximately 30 minutes). There will also be a mandatory pause between two successive fan activations to avoid stressing the hardware and causing harmful behavior to the plant.

The LEDs are turned on if the light received by the sensor is below 10lx. They remain on until the next data sampling, which determines a higher ambient light intensity (>80lx).
Upon turning on the LEDs, the light intensity is recalculated before displaying the value on the screen.

Watering the plant through the hose and water pump is triggered when the soil moisture sensor detects dry soil. There is a time gap between two successive watering actions, during which the plant cannot be watered, regardless of the sampled parameters, allowing the water to be absorbed into the soil, and the new moisture parameters to be correctly provided.

## Libraries 📖
- LiquidCrystal.h ⇒ For the 1602 LCD display.
- Wire.h ⇒ For communication with the I2C device BH1750.
- DHT.h ⇒ For using the DHT11 sensor to record temperature and humidity.
- BH1750.h ⇒ For using the BH1750 sensor to record ambient light intensity.

## Resources
https://eazytronic.com/soil-moisture-sensor-arduino/
https://chrisruppel.com/blog/arduino-automated-greenhouse/
https://lastminuteengineers.com/soil-moisture-sensor-arduino-tutorial/
https://forum.arduino.cc/t/switching-a-cooling-fan-on-and-off-through-npn-transistor-connected-to-arduino/512176
https://maxpromer.github.io/LCD-Character-Creator/