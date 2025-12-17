# 🌱 Smart Crop Damage Prevention System using ESP32

A complete IoT-based agriculture monitoring system that helps farmers
detect rain, soil dryness, and environmental conditions in real time.
The system provides alerts through LED, buzzer, LCD display, and
push notifications using the Blynk IoT platform.

---

## 🔧 Hardware Components

- ESP32 Dev Module
- DHT11 Temperature & Humidity Sensor
- Soil Moisture Sensor
- Rain Drop Sensor Module
- 16×2 LCD with I2C Module
- Buzzer
- LED + 330Ω resistor
- Breadboard & Jumper wires
- Power Supply (USB)

---

## 📌 Features

- Real-time temperature & humidity monitoring
- Soil moisture level detection
- Rain detection
- LCD display for local monitoring
- Mobile app monitoring using Blynk
- Push notification alerts on:
  - Rain detection
  - Dry soil condition
- LED & buzzer alerts in the field

---

## 🔌 Circuit Connections

| Component | ESP32 Pin |
|---------|-----------|
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |
| LCD VCC | 5V |
| LCD GND | GND |
| DHT11 DATA | GPIO 4 |
| DHT11 VCC | 5V |
| DHT11 GND | GND |
| Soil Sensor A0 | GPIO 34 |
| Rain Sensor D0 | GPIO 32 |
| LED | GPIO 25 (with resistor) |
| Buzzer | GPIO 27 |
| All GND | Common GND |

---

## 📱 Blynk IoT Setup

### 1️⃣ Create Template
- Platform: ESP32
- Connection: WiFi
- Template Name: Crop Damage Prevention

### 2️⃣ Datastreams

| Virtual Pin | Parameter |
|------------|----------|
| V0 | Temperature |
| V1 | Humidity |
| V2 | Soil Moisture |
| V3 | Rain Status |

### 3️⃣ Events (Push Notifications)

| Event Name | Description |
|-----------|-------------|
| rain_alert | Rain detected |
| dry_soil | Soil moisture is low |

---

## 💻 Software Requirements

- Arduino IDE (v2.3.6 recommended)
- ESP32 Board Package
- Libraries:
  - Blynk
  - LiquidCrystal_PCF8574
  - DHT Sensor Library
  - Adafruit Unified Sensor

---

## 🚀 How to Upload Code to ESP32

1. Open Arduino IDE
2. Install required libraries
3. Select:
   - Board: ESP32 Dev Module
   - Port: COMx
4. Paste the provided code
5. Update WiFi credentials & Blynk token
6. Click Upload

---

## 📲 Final Output

- LCD displays sensor values
- Blynk app shows live data
- Push notifications sent instantly
- LED & buzzer alert on danger

---

## 📸 Project Images
(Add your circuit images here)

---

## 🧑‍💻 Author
Khaleel Ulla
In Association with Channabasaveshwara Institute Of Technology.

---

## 📜 License
This project is open-source and free to use for academic purposes.
