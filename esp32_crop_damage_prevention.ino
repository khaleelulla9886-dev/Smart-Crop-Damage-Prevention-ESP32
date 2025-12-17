#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Crop Damage Prevention"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// WiFi Credentials
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

// Pin Definitions
#define SOIL_PIN 34
#define RAIN_PIN 27
#define DHT_PIN 4
#define RED_LED 25
#define GREEN_LED 26
#define BUZZER 33

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;

// Function to read sensors
void readSensors() {
  int soilValue = analogRead(SOIL_PIN);
  int rainValue = digitalRead(RAIN_PIN);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print(" H:");
  lcd.print(hum);

  lcd.setCursor(0, 1);
  lcd.print("Soil:");
  lcd.print(soilValue);

  if (soilValue > 2500 || rainValue == LOW) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, HIGH);

    Blynk.logEvent("crop_alert", "⚠ Crop Risk Detected!");
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, LOW);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RAIN_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(3000L, readSensors);
}

void loop() {
  Blynk.run();
  timer.run();
}
