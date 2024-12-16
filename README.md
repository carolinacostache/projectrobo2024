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

## Block Diagram 🖼
![Block Diagram](<images/Block Scheme.png>)

## Hardware Design 

## Bill of Materials 🔩
| Name | Photo | Source | Technical Characteristics |
|:------------:|:--------------:|:-------------:|:-------------:|
|Arduino UNO R3 ATmega328P |      |Kit | |
|Mini-Breadboard |        |Kit ||
|Breadboard ||||
|LCD 1602 Module ||Kit||
|LEDs 5 mm||||
|Fan ||[Store](https://www.emag.ro/ventilator-pc-lhr-super-fan-80x80x25mm-3000rpm-12v-0-20a-lhr-80-2p-b/pd/DTFH9BMBM/?ref=history-shopping_404566740_5919_1)|- Airflow (CFM): 41.2 - Speed: 3000 RPM
- Dimensions: 80 x 80 x 25 mm
- Noise Level (dB): 34 dB
- Voltage: 12 V
- Weight: 54 g|
|Water Pump 3-5V||[Store](https://www.emag.ro/pompa-de-apa-3-6v-cl88/pd/D91Z5JBBM/)|- Voltage: DC 3-5V
- Current: 100-200mA
- Flow Rate: 1.2-1.6 L/min
- Weight: 28 grams
- Material: Plastic
- Outer Nozzle Diameter: 7.5mm
- Inner Nozzle Diameter: 4.7mm
- Diameter: Approximately 24mm
- Length: Approximately 45mm
- Height: Approximately 33mm
- Recommended Continuous Operating Time: Should not exceed 500 hours
- Color: White |
|Transistor ||||
|Temperature and Humidity Sensor DHT11||[Store](https://www.emag.ro/modul-de-temperatura-si-umiditate-dht11-senzor-de-temperatura-umiditate-consum-mediu-de-curent-redus-14-mm-x-20-mm-albastru-g1/pd/D93G1QYBM/?ref=history-shopping_404566740_158626_1)|[Datasheet](chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf?srsltid=AfmBOoo9bgj7eenwhUM-Ssb3RPevd5KTRYIdXSFQblFzX35BLW3OTngi)|
|Soil Moisture Sensor ||||
|Light Intensity Sensor ||||
|Resistors ||||
|Battery Holder ||||
|Battery ||||
|Colorful Wires ||||
|Capacitor ||||
|Diode ||||

## Software Design

## Results

## Pictures

## Video

## Diary

## Resources
