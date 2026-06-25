// #include <SPI.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <DHT.h>

// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define OLED_DC 7
// #define OLED_CS 10
// #define OLED_RESET 8

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

// // DHT11
// #define DHTPIN 2
// #define DHTTYPE DHT11
// DHT dht(DHTPIN, DHTTYPE);

// // Motor
// #define IN1 5
// #define IN2 6
// #define ENA 9

// void setup() {
//   Serial.begin(9600);

//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(ENA, OUTPUT);

//   dht.begin();

//   if (!display.begin(SSD1306_SWITCHCAPVCC)) {
//     Serial.println("OLED failed");
//     while (1);
//   }

//   display.clearDisplay();
//   display.setTextColor(WHITE);

//   Serial.println("System Started...");
// }

// void loop() {
//   float temp = dht.readTemperature();

//   display.clearDisplay();

//   if (isnan(temp)) {
//     Serial.println("DHT Error!");

//     display.setTextSize(1);
//     display.setCursor(0, 20);
//     display.println("Sensor Error!");
//     display.display();
//     return;
//   }

//   // SERIAL OUTPUT
//   Serial.print("Temperature: ");
//   Serial.print(temp);
//   Serial.println(" C");

//   // OLED DISPLAY - Temperature
//   display.setTextSize(2);
//   display.setCursor(0, 0);
//   display.print("Temp:");
//   display.print(temp);
//   display.println("C");

//   // MOTOR CONTROL + DISPLAY
//   display.setTextSize(2);
//   display.setCursor(0, 40);

//   if (temp > 30) {
//     Serial.println("Cooling ON");

//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     analogWrite(ENA, 200);

//     display.println("ON");
//   } else {
//     Serial.println("Cooling OFF");

//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);
//     analogWrite(ENA, 0);

//     display.println("OFF");
//   }

//   display.display();  // VERY IMPORTANT

//   delay(2000);
// }
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED (SPI)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_DC 7
#define OLED_CS 10
#define OLED_RESET 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

// DHT11
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Motor (L298N)
#define IN1 5
#define IN2 6
#define ENA 9

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  dht.begin();

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println("OLED failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);

  // Startup message
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("STARTING");
  display.display();
  delay(2000);

  Serial.println("System Started...");
}

void loop() {
  float temp = dht.readTemperature();

  display.clearDisplay();

  // Sensor error check
  if (isnan(temp)) {
    Serial.println("DHT Error!");

    display.setTextSize(1);
    display.setCursor(0, 20);
    display.println("Sensor Error!");
    display.display();
    return;
  }

  // Serial output
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  // OLED - Temperature
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("Temp:");
  display.print(temp);
  display.println("C");

  // Motor control (36°C condition)
  display.setTextSize(2);
  display.setCursor(0, 40);

  if (temp >= 36) {
    Serial.println("Cooling ON");

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 200);

    display.println("ON");
  } else {
    Serial.println("Cooling OFF");

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);

    display.println("OFF");
  }

  display.display();

  delay(2000);
}