# Weather API Fetcher (ESP32)

## Components
- ESP32
- DHT11
- WiFi

## Libraries
- WiFi
- HTTPClient
- ArduinoJson
- DHT Sensor Library

## Features
- Connects to WiFi
- Fetches weather from OpenWeatherMap API
- Reads DHT11 temperature and humidity
- Compares API temperature with local temperature
- Displays results on Serial Monitor

Note:
API key is stored in config.h and is ignored using .gitignore.
