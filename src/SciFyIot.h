#ifndef SCIFYIOT_H
#define SCIFYIOT_H

#include <Arduino.h>
#include <WiFi.h>      

#include <HTTPClient.h>
#include <ArduinoJson.h>

class SciFyIot {
public:
    SciFyIot(const String& apiKey, const String& secret);
    String getLatestCommand(); 

private:
    String _apiKey;
    String _secret;
    String _lastCommand;
    const String _baseUrl = "https://ecoplas.tech/getLogs";
};

#endif
