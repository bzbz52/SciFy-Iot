# 🚀 SciFi-IOT Control System

A complete IoT device control platform that lets you command ESP32/ESP8266 devices from anywhere in the world! Perfect for students, makers, and anyone wanting to build smart devices.

![Project Banner](public/banner.png) <!-- Optional: Add screenshot -->

---

## 🌍 Live Demo
**GitHub Pages:** [https://yourusername.github.io/SciFi-IOT](https://yourusername.github.io/SciFi-IOT)  
**Backend API:** `https://scifi-iot-backend.herokuapp.com`

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

1. **You create a project** and get special "keys" (like passwords for your devices)
2. **Program your ESP32/ESP8266** with these keys so it knows it's yours
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

## 📦 Installation

```bash
# Clone the repository
git clone https://github.com/YOUR_GITHUB_USERNAME/SciFi-IOT.git
cd SciFi-IOT

# Install dependencies
npm install

# Run locally
npm run dev

# Build for production
npm run build

# Preview production build
npm run preview
```

---

## 🚀 Deploy to GitHub Pages

```bash
# Install GitHub Pages deploy tool
npm install gh-pages --save-dev

# Add these lines to package.json
# "scripts": {
#   "predeploy": "npm run build",
#   "deploy": "gh-pages -d dist"
# }

# Deploy
npm run deploy
```

After deployment, your site will be live at:  
`https://YOUR_GITHUB_USERNAME.github.io/SciFi-IOT`

---

## 📡 API Documentation

### Main Endpoint
```
POST https://scifi-iot-backend.herokuapp.com/sendSignal
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
fetch("https://scifi-iot-backend.herokuapp.com/sendSignal", {
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
  "https://scifi-iot-backend.herokuapp.com/sendSignal",
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
  http.begin("https://scifi-iot-backend.herokuapp.com/getCommands");
  http.addHeader("Content-Type", "application/json");
  String payload = "{"apiKey":"" + apiKey + ""}";
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

## 🛠 Repository Structure

```
SciFi-IOT/
├── public/            # Static assets
├── src/               # Frontend code
├── examples/          # Arduino, JS, Python samples
├── README.md
└── package.json
```

---

## 📷 Screenshots

(Add control panel & device screenshots here)

---

## 📱 What You Can Build

- Smart lights
- Smart doors
- Temperature monitors
- Robot cars
- Pet feeders
- Weather stations

---

## 🎯 Learning Path

### Beginner
- Create a project, upload LED code, test with control panel

### Intermediate
- Add sensors, servos, relays
- Create custom commands

### Advanced
- Build mobile/web dashboards
- Integrate multiple devices

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

## 🤝 Contributing

1. Fork the repo
2. Create a branch (`git checkout -b feature-name`)
3. Commit changes (`git commit -m 'Added feature'`)
4. Push to branch (`git push origin feature-name`)
5. Create Pull Request

---

## 🆘 Support

- Open an **issue** in this repo  
- Check Troubleshooting section in docs  
- Use Serial Monitor for device debugging
