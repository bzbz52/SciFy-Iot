# 🚀 SciFy-IOT Control System

A complete **IoT device control platform** that lets you command ESP32/ESP8266 devices from anywhere in the world — now available at **[https://scify-iot.in](https://scify-iot.in)**!  
Perfect for students, makers, and anyone wanting to build smart devices.

---

## 🌍 Live Platform
- **Website:** [https://scify-iot.in](https://scify-iot.in)  
- **API Base URL:** `https://api.scify-iot.in`
- **GitHub Repo:** [https://github.com/AlphaNodesDev/SciFy-Iot](https://github.com/AlphaNodesDev/SciFy-Iot)

---

## 🎯 What This System Does
Think of this as a **remote control for your electronics** that works from anywhere with internet:

- 💡 Turn lights on/off from your phone
- 🚪 Control door locks remotely  
- 🌡️ Monitor temperature sensors
- 🤖 Control robot cars from across the world
- 🔧 And much more!

---

## 🧠 How It Works (Simple Explanation)
```
Your Phone/Computer  →  Internet  →  SciFy-IOT Platform  →  Your Device
     (Send Command)      (Cloud)      (Process & Route)      (LED turns on!)
```

---

# 📥 Receiving Commands on ESP (Arduino Library)

This method is for **ESP32/ESP8266 devices** to receive commands from the SciFy-IOT platform.

### 1️⃣ Install the Library
- Download ZIP: [Click Here](https://github.com/AlphaNodesDev/SciFy-Iot/archive/refs/heads/main.zip)  
- In Arduino IDE: `Sketch → Include Library → Add .ZIP Library…`

### 2️⃣ Basic Example
```cpp
#include <WiFi.h>        // Or <ESP8266WiFi.h> for ESP8266
#include <SciFyIot.h>    // SciFy-IOT library

const char* ssid = "Wokwi-GUEST"; 
const char* password = "";

SciFyIot iot("YOUR_API_KEY", "YOUR_SECRET_KEY");

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT); // Onboard LED

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void loop() {
  String cmd = iot.getLatestCommand();
  if (cmd == "LED_ON") {
    digitalWrite(2, HIGH);
  } else if (cmd == "LED_OFF") {
    digitalWrite(2, LOW);
  }
  delay(2000);
}
```

---

# 📤 Sending Commands to Device (API)

This is for **custom apps, websites, or scripts** to send commands to your ESP devices through SciFy-IOT.

### Endpoint
```
POST https://api.scify-iot.in/sendSignal
```

### JSON Body
```json
{
  "apiKey": "your-api-key",
  "secret": "your-secret-key",
  "command": "LED_ON"
}
```

### Example in Python
```python
import requests

requests.post(
  "https://api.scify-iot.in/sendSignal",
  json={
    "apiKey": "your-api-key",
    "secret": "your-secret-key",
    "command": "LED_ON"
  }
)
```

### Example in JavaScript
```javascript
fetch("https://api.scify-iot.in/sendSignal", {
  method: "POST",
  headers: {"Content-Type": "application/json"},
  body: JSON.stringify({
    apiKey: "your-api-key",
    secret: "your-secret-key",
    command: "LED_ON"
  })
});
```

---

## 📱 What You Can Build
- Smart lights
- Smart doors
- Temperature monitors
- Robot cars
- Pet feeders
- Weather stations

---

## 🔐 Security Best Practices
✅ Keep keys private  
✅ Use separate projects for separate devices  
✅ Secure your WiFi  

❌ Don’t commit keys to public repos  
❌ Don’t share API credentials publicly  

---

## 📜 License
MIT License — free to use and modify.

---

## 🆘 Support
- Open an **issue** in this repo  
- Check Troubleshooting section in docs  
- Use Serial Monitor for device debugging
