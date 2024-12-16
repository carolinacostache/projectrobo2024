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
|Arduino UNO ATmega328P ||Kit |[Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)|
|Mini-Breadboard ||Kit |-|
|Breadboard ||[Store](https://www.emag.ro/breadboard-830-puncte-mb102-cl01/pd/DF0C5JBBM/?ref=history-shopping_404566740_38837_4)|-|
|LCD 1602 Module ||Kit|[Datasheet](https://www.waveshare.com/datasheet/LCD_en_PDF/LCD1602.pdf)|
|LEDs 5 mm||Kit|-|
|Fan ||[Store](https://www.emag.ro/ventilator-pc-lhr-super-fan-80x80x25mm-3000rpm-12v-0-20a-lhr-80-2p-b/pd/DTFH9BMBM/?ref=history-shopping_404566740_5919_1)|Airflow (CFM): 41.2 <br> Speed: 3000 RPM <br> Dimensions: 80 x 80 x 25 mm <br> Noise Level (dB): 34 dB <br> Voltage: 12 V <br> Weight: 54 g|
|Water Pump 3-5V||[Store](https://www.emag.ro/pompa-de-apa-3-6v-cl88/pd/D91Z5JBBM/)| Voltage: DC 3-5V <br> Current: 100-200mA <br> Flow Rate: 1.2-1.6 L/min <br> Weight: 28 grams <br> Material: Plastic <br> Outer Nozzle Diameter: 7.5mm <br> Inner Nozzle Diameter: 4.7mm <br> Diameter: Approximately 24mm <br> Length: Approximately 45mm <br> Height: Approximately 33mm <br> Recommended Continuous Operating Time: Should not exceed 500 hours <br> Color: White |
|Transistor NPN||Kit|[Datasheet](https://www.sparkfun.com/datasheets/Components/2N3904.pdf)|
|Temperature and Humidity Sensor DHT11||[Store](https://www.emag.ro/modul-de-temperatura-si-umiditate-dht11-senzor-de-temperatura-umiditate-consum-mediu-de-curent-redus-14-mm-x-20-mm-albastru-g1/pd/D93G1QYBM/?ref=history-shopping_404566740_158626_1)|[Datasheet](https://components101.com/sites/default/files/component_datasheet/DFR0067%20DHT11%20Datasheet.pdf)|
|Soil Moisture Sensor ||[Store](https://www.emag.ro/modul-cu-senzor-umiditate-sol-cl73/pd/D5ZZ5JBBM/?ref=history-shopping_404566740_38837_2)|[Datasheet](https://www.alldatasheet.com/view.jsp?Searchword=LM39)|
|Light Intensity Sensor BH1750||[Store](https://www.emag.ro/senzor-lumina-robofun-gy-302-bh1750-00005472/pd/D6M30YYBM/?ref=history-shopping_404566740_12161_1)|[Datasheet](https://www.handsontec.com/dataspecs/sensor/BH1750%20Light%20Sensor.pdf)|
|Resistors ||Kit|-|
|Battery Holder ||[Store](https://www.emag.ro/suport-4-baterii-robofun-aaa-cu-cablu-de-conectare-00002876/pd/DBGSN3YBM/?ref=history-shopping_404566740_12161_2)|-|
|Batteries ||-|-|
|Colorful Wires ||Kit|-|
|Capacitor ||Kit|-|
|Diode ||Kit|-|

## Software Design

## Results

## Pictures

## Video

## Diary

## Resources
