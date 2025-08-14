# 🚀 SciFi-IOT Control System

A complete **IoT device control platform** that lets you command ESP32/ESP8266 devices from anywhere in the world — now available at **[https://scify-iot.in](https://scify-iot.in)**!  
Perfect for students, makers, and anyone wanting to build smart devices.

![Project Banner](public/banner.png) <!-- Optional: Add screenshot -->

---

## 🌍 Live Platform
- **Website:** [https://scify-iot.in](https://scify-iot.in)  
- **API Base URL:** `https://api.scify-iot.in`

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
Your Phone/Computer  →  Internet  →  SciFi-IOT Platform  →  Your Device
     (Send Command)      (Cloud)      (Process & Route)      (LED turns on!)
```

1. **Create a project** in your control panel to get your **API Key** and **Secret Key**
2. **Flash your ESP32/ESP8266** with the provided example code & your keys
3. **Send commands** from any phone, computer, or website
4. **Your device receives** and executes the commands instantly!

---

## 🎓 Perfect for Students

- ✅ No complex server setup required
- ✅ Works with simple Arduino code
- ✅ Visual interface for testing
- ✅ Detailed step-by-step guides
- ✅ Ready-to-copy code examples

---

## 🌟 Features

### 🎮 Control Panel
- Quick Buttons: One-click commands (LED ON, LED OFF, etc.)
- Custom Commands: Create your own
- String & JSON support
- Real-time communication

### 🔧 Device Support
- ESP32 & ESP8266
- Arduino IDE compatible
- WiFi communication
- Multiple devices per project

### 💻 Programming Languages
- JavaScript
- Python
- cURL
- Any language that can make HTTP requests

### 🔐 Security
- API Keys & Secret Keys
- Project isolation
- Encrypted communication

---

## 📡 API Documentation

### Main Endpoint
```
POST https://api.scify-iot.in/sendSignal
```

### Request Format
```json
{
  "apiKey": "your-api-key-here",
  "secret": "your-secret-key-here", 
  "command": "LED_ON"
}
```

---

## ⚡ Quick Examples

**JavaScript**
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

**Python**
```python
import requests

response = requests.post(
  "https://api.scify-iot.in/sendSignal",
  json={
    "apiKey": "your-api-key",
    "secret": "your-secret-key",
    "command": "LED_ON"
  }
)
print(response.json())
```

**Arduino**
```cpp
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
const String apiKey = "your-api-key-here";

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(1000); }
}

void loop() {
  HTTPClient http;
  http.begin("https://api.scify-iot.in/getCommands");
  http.addHeader("Content-Type", "application/json");
  String payload = "{\"apiKey\":\"" + apiKey + "\"}";
  int httpCode = http.POST(payload);

  if (httpCode == 200) {
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, http.getString());
    String command = doc["command"];
    if (command == "LED_ON") digitalWrite(2, HIGH);
    else if (command == "LED_OFF") digitalWrite(2, LOW);
  }
  http.end();
  delay(5000);
}
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
