#include <WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

// ========= WIFI =========
#define WIFI_SSID "YOUR_WIFI"
#define WIFI_PASSWORD "YOUR_PASSWORD"

// ========= SINRIC =========
#define APP_KEY "YOUR_APP_KEY"
#define APP_SECRET "YOUR_APP_SECRET"
#define DEVICE_ID "YOUR_DEVICE_ID"

// ========= IR =========
#define IR_PIN 4
#define LG_POWER_CODE 0x20DF10EF

IRsend irsend(IR_PIN);

// Callback da Alexa
bool onPowerState(const String &deviceId, bool &state) {
  Serial.print("Alexa pediu: ");
  Serial.println(state ? "LIGAR" : "DESLIGAR");

  // LG usa POWER TOGGLE
  irsend.sendNEC(LG_POWER_CODE, 32);
  return true;
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
  Serial.println(WiFi.localIP());

  irsend.begin();

  // Sinric
  SinricProSwitch &mySwitch = SinricPro[DEVICE_ID];
  mySwitch.onPowerState(onPowerState);

  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}

void loop() {
  SinricPro.handle();
}