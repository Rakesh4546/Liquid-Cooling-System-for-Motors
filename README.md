# Liquid-Cooling-System-for-Motors
This project is an automatic temperature-based cooling system using an Arduino, DHT11 temperature sensor, SPI OLED display, L298N motor driver, and DC motor/fan.  When the temperature reaches 36°C or above, the cooling motor turns ON. When the temperature is below 36°C, the cooling motor turns OFF.
Features
Reads temperature using DHT11 sensor
Displays temperature on 128x64 OLED display
Controls DC motor/fan using L298N motor driver
Automatically turns cooling ON/OFF based on temperature
Shows motor status on OLED display
Prints temperature and cooling status in Serial Monitor
Components Required
Component	Quantity
Arduino UNO / Nano	1
DHT11 Temperature Sensor	1
128x64 OLED Display SPI	1
L298N Motor Driver	1
DC Motor / Cooling Fan	1
External Motor Power Supply	1
Jumper Wires	Required
Breadboard	Optional
Circuit Connections
DHT11 Sensor Connection
DHT11 Pin	Arduino Pin
VCC	5V
GND	GND
DATA	D2
OLED Display SPI Connection
OLED Pin	Arduino Pin
VCC	5V
GND	GND
SCK / CLK	D13
MOSI / SDA	D11
DC	D7
CS	D10
RESET	D8
L298N Motor Driver Connection
L298N Pin	Arduino Pin
IN1	D5
IN2	D6
ENA	D9
Motor Power Connection
L298N Pin	Connection
OUT1	Motor terminal 1
OUT2	Motor terminal 2
12V / VCC	External motor supply positive
GND	External motor supply negative
GND	Arduino GND

Important: Arduino GND and L298N GND must be connected together.

Pin Configuration Used in Code
#define DHTPIN 2
#define DHTTYPE DHT11

#define OLED_DC 7
#define OLED_CS 10
#define OLED_RESET 8

#define IN1 5
#define IN2 6
#define ENA 9
Required Arduino Libraries

Install these libraries from Arduino IDE Library Manager:

Adafruit GFX Library
Adafruit SSD1306
DHT sensor library
Adafruit Unified Sensor
How to Install Libraries
Open Arduino IDE
Go to Sketch
Select Include Library
Click Manage Libraries
Search and install:
Adafruit GFX Library
Adafruit SSD1306
DHT sensor library
Adafruit Unified Sensor
Uploading the Code
Connect Arduino to your computer using USB cable
Open the code in Arduino IDE
Select board:
Tools → Board → Arduino UNO
Select port:
Tools → Port → Your Arduino COM Port
Click Upload
Open Serial Monitor
Set baud rate to 9600
Working Logic
if (temp >= 36) {
    Cooling ON
} else {
    Cooling OFF
}
Cooling ON Condition

When temperature is 36°C or above:

Motor turns ON
OLED displays ON
Serial Monitor prints Cooling ON
Cooling OFF Condition

When temperature is below 36°C:

Motor turns OFF
OLED displays OFF
Serial Monitor prints Cooling OFF
Serial Monitor Output Example
System Started...
Temperature: 35.00 C
Cooling OFF
Temperature: 36.00 C
Cooling ON
Temperature: 37.00 C
Cooling ON
OLED Display Output

When system starts:

STARTING

During operation:

Temp:36.00C
ON

or

Temp:30.00C
OFF

DHT Error shown

Check:

DHT11 DATA pin connected to D2
VCC connected to 5V
GND connected properly
Sensor is not damaged
Motor not rotating

Check:

External motor power supply connected to L298N
Arduino GND and L298N GND connected together
Motor connected to OUT1 and OUT2
ENA connected to PWM pin D9
IN1 and IN2 connected correctly
Important Notes
DHT11 is low-cost but not highly accurate.
For better temperature accuracy, DHT22 can be used.
L298N has voltage drop and heating losses.
For higher efficiency motor control, a MOSFET driver is better than L298N.
Use external power supply for motor. Do not power motor directly from Arduino.
Applications
Automatic CPU cooling demo
Temperature-based fan control
Mini cooling automation system
Smart ventilation system
Basic embedded system project
IoT cooling prototype
Author

Rakesh Kumar R
