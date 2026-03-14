#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

#define RELAY_PIN 5  // GPIO5

BlynkTimer timer;

void checkConnection() {
  if (Blynk.connected()) {
    Serial.println("✅ Still connected to Blynk");
  } else {
    Serial.println("❌ Lost Blynk connection");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relay OFF initially

  Serial.println("Connecting to WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connected to WiFi & Blynk");

  timer.setInterval(3000L, checkConnection);
}

BLYNK_WRITE(V0) {
  int state = param.asInt();
  Serial.print("Received from Blynk: ");
  Serial.println(state);
  
  if (state == 1) {
    digitalWrite(RELAY_PIN, LOW);  // Relay ON
    Serial.println("Relay ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Relay OFF
    Serial.println("Relay OFF");
  }
}

void loop() {
  Blynk.run();
  timer.run();
}
