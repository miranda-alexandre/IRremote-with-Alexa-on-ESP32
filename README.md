# ESP32 LG TV IR Control with Alexa

Project for controlling an LG TV using an ESP32 as an infrared (IR) transmitter, integrated with Amazon Alexa through the Sinric Pro platform.

---

## 📌 Features

- TV control via **Alexa**
- Integration with **Sinric Pro**
- Sending **Infrared (IR)** commands
- Connection via **Wi-Fi**
- Implementation with **ESP32**

---

## 🛠 Technologies Used

- ESP32
- Arduino IDE
- Sinric Pro API
- IRremoteESP8266
- WiFi.h

---

## ⚙️ installation

## 1. Clone the repository

## 2. Open the project in the Arduino IDE

Open the `.ino` file in the Arduino IDE.

---

## 3. Install the necessary libraries

Install using the **Library Manager**:

- SinricPro
- IRremoteESP8266

---

## 4. Configure your credentials


```
#define WIFI_SSID "YOUR_WIFI"
#define WIFI_PASSWORD "YOUR_PASSWORD"

#define APP_KEY "YOUR_APP_KEY"
#define APP_SECRET "YOUR_APP_SECRET"

```

## 5. Send the code to the ESP32

Connect the ESP32 via USB and click **Upload** in the Arduino IDE.

---

## 🔧Required Hardware

- ESP32
- Infrared LED
- 220Ω Resistor
- USB Power Supply 

---

## 📡 How it works:

The ESP32 connects to Wi-Fi and the Sinric Pro.

When a command is sent via Alexa, the Sinric Pro sends the request to the ESP32, which transmits the request to the ESP32, which then sends the corresponding IR code to the LG TV.
