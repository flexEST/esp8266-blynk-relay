How to Use
1. Setup Blynk Project

Open the Blynk app on your mobile device.

Create a new project with ESP8266 as the board type.

Add a Button Widget and assign it to V0 virtual pin.

Copy the Auth Token from the project (you will use it in your code).

2. Configure Arduino Code

Replace the placeholders with your details:

#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_TOKEN"

char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

Connect the relay to GPIO5 (or change RELAY_PIN if needed).

3. Upload to ESP8266

Select the correct board and port in Arduino IDE.

Upload the code.

Open the Serial Monitor to see debug messages (baud rate 9600).

4. Control Relay

Open the Blynk app.

Press the button widget (V0) to turn the relay ON/OFF.

Serial Monitor will show the relay status and connection health.

5. Automatic Connection Check

The checkConnection() function runs every 3 seconds, printing the connection status to Blynk and Serial Monitor.

Example Serial Output
Connecting to WiFi...
Connected to WiFi & Blynk
✅ Still connected to Blynk
Received from Blynk: 1
Relay ON
✅ Still connected to Blynk
Received from Blynk: 0
Relay OFF
Notes & Safety

Ensure your relay is rated for the load you are switching.

Avoid connecting high-voltage devices directly to the relay without proper precautions.

This project is intended for educational and prototyping purposes.
