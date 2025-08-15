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

1. **Create a project** in your control panel to get your **API Key** and **Secret Key**
2. **Flash your ESP32/ESP8266** with the provided example code & your keys
3. **Send commands** from any phone, computer, or website
4. **Your device receives** and executes the commands instantly!

---

## 🛠 Arduino Library Installation

1. **Download the Library**
   - Method 1: Click [Download ZIP](https://github.com/AlphaNodesDev/SciFy-Iot/archive/refs/heads/main.zip) from this repo and add it to Arduino IDE via  
     `Sketch → Include Library → Add .ZIP Library…`
   - Method 2: (Coming Soon) Install directly from Arduino Library Manager by searching `SciFyIot`.

2. **Include in Your Code**
```cpp
#include <WiFi.h>      // Or <ESP8266WiFi.h> for ESP8266
#include <SciFyIot.h>
```

3. **Open the Example**
   - In Arduino IDE: `File → Examples → SciFyIot → BasicControl`

4. **Upload & Run**
   - Enter your WiFi credentials and your SciFy-IOT API keys
   - Upload to your ESP32/ESP8266
   - Use the dashboard at [scify-iot.in](https://scify-iot.in) to send commands

---

## 📡 Basic Arduino Example

```cpp
#include <WiFi.h>        // ESP32 WiFi library
#include <SciFyIot.h>    // SciFy-IOT library

const char* ssid = "Wokwi-GUEST"; // WiFi SSID
const char* password = "";        // WiFi password

SciFyIot iot("YOUR_API_KEY", "YOUR_SECRET_KEY");

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT); // Onboard LED

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
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

## ⚡ API Quick Examples

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
