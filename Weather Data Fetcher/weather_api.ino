#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include "config.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url =
      "http://api.openweathermap.org/data/2.5/weather?q=" +
      String(city) +
      "," +
      String(countryCode) +
      "&appid=" +
      String(apiKey) +
      "&units=metric";

    http.begin(url);

    int httpCode = http.GET();

    if (httpCode == 200) {

      String payload = http.getString();

      DynamicJsonDocument doc(2048);

      deserializeJson(doc, payload);

      String cityName = doc["name"];

      float apiTemp = doc["main"]["temp"];

      int humidity = doc["main"]["humidity"];

      String weather = doc["weather"][0]["description"];

      float localTemp = dht.readTemperature();

      float diff = apiTemp - localTemp;

      Serial.println("----------------------------");

      Serial.print("City : ");
      Serial.println(cityName);

      Serial.print("API Temperature : ");
      Serial.print(apiTemp);
      Serial.println(" C");

      Serial.print("Local Temperature : ");
      Serial.print(localTemp);
      Serial.println(" C");

      Serial.print("Difference : ");
      Serial.print(diff);
      Serial.println(" C");

      Serial.print("Humidity : ");
      Serial.print(humidity);
      Serial.println(" %");

      Serial.print("Weather : ");
      Serial.println(weather);

      Serial.println("----------------------------");
    }

    http.end();
  }

  delay(60000);
}
