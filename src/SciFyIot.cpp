#include "SciFyIot.h"

SciFyIot::SciFyIot(const String& apiKey, const String& secret) {
    _apiKey = apiKey;
    _secret = secret;
    _lastCommand = "";
}

String SciFyIot::getLatestCommand() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi not connected!");
        return "";
    }

    HTTPClient http;
    http.begin(_baseUrl);
    http.addHeader("Content-Type", "application/json");

    String payload = "{\"apiKey\":\"" + _apiKey + "\",\"secret\":\"" + _secret + "\"}";
    int httpCode = http.POST(payload);

    if (httpCode == 200) {
        String response = http.getString();
        DynamicJsonDocument doc(4096);
        DeserializationError error = deserializeJson(doc, response);

        if (!error && doc.is<JsonObject>()) {
            JsonObject logs = doc.as<JsonObject>();

            if (!logs.isNull()) {
                String latestKey;
                for (JsonPair kv : logs) {
                    latestKey = kv.key().c_str();
                }

                String latestPayload = logs[latestKey]["payload"].as<String>();

                if (latestPayload != _lastCommand) {
                    _lastCommand = latestPayload;
                    http.end();
                    return latestPayload;
                }
            }
        } else {
            Serial.println("JSON parse error or invalid format");
        }
    } else {
        Serial.printf("HTTP error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
    return "";
}
