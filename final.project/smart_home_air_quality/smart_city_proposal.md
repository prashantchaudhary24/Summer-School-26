# IoT Proposal for Jammu Smart City

## Overview

The Government of Jammu & Kashmir plans to develop Jammu as a Smart City using Internet of Things (IoT) technology. This proposal presents three IoT-based systems to improve urban infrastructure:

1. Smart Street Lighting
2. Smart Air Quality Monitoring
3. Smart Waste Bin Monitoring

---

# 1. Smart Street Lighting

## Objective

Reduce electricity consumption by automatically controlling street lights based on ambient light and vehicle/pedestrian movement.

### Sensors

- LDR Sensor
- PIR Motion Sensor

### Microcontroller

- ESP32

### Connectivity

- Wi-Fi / LoRa

### Data Flow

LDR + PIR
↓

ESP32

↓

MQTT / HTTP

↓

Cloud Server

↓

Smart City Dashboard

### Estimated Cost

| Component | Cost |
|------------|------|
| ESP32 | ₹550 |
| PIR | ₹120 |
| LDR | ₹30 |
| Relay | ₹80 |
| Power Supply | ₹150 |

**Total Cost ≈ ₹930 per node**

### Advantages

- Saves electricity
- Automatic operation
- Reduced maintenance

---

# 2. Smart Air Quality Monitoring

## Objective

Continuously monitor pollution levels and alert authorities when air quality becomes unsafe.

### Sensors

- MQ135 Air Quality Sensor
- DHT11 Temperature & Humidity Sensor

### Microcontroller

ESP32

### Connectivity

Wi-Fi

### Data Flow

MQ135 + DHT11

↓

ESP32

↓

HTTP / MQTT

↓

Cloud

↓

Mobile Dashboard

### Estimated Cost

| Component | Cost |
|------------|------|
| ESP32 | ₹550 |
| MQ135 | ₹250 |
| DHT11 | ₹120 |
| Power Supply | ₹150 |

**Total Cost ≈ ₹1070 per node**

### Advantages

- Real-time pollution monitoring
- Health alerts
- Environmental analysis

---

# 3. Smart Waste Bin Monitoring

## Objective

Monitor garbage bin fill level and optimize waste collection routes.

### Sensors

- Ultrasonic Sensor (HC-SR04)

### Microcontroller

ESP8266

### Connectivity

Wi-Fi

### Data Flow

Ultrasonic Sensor

↓

ESP8266

↓

HTTP

↓

Cloud Database

↓

Municipal Dashboard

### Estimated Cost

| Component | Cost |
|------------|------|
| ESP8266 | ₹350 |
| HC-SR04 | ₹100 |
| Battery | ₹200 |
| Enclosure | ₹150 |

**Total Cost ≈ ₹800 per node**

### Advantages

- Prevents overflowing bins
- Optimized waste collection
- Lower operational cost

---

# Overall Architecture

```
Sensors
   │
   ▼
ESP32 / ESP8266
   │
Wi-Fi / LoRa
   │
   ▼
Cloud Platform
   │
   ▼
Smart City Dashboard
```

---

# Conclusion

The proposed Smart City solution combines Smart Street Lighting, Air Quality Monitoring, and Waste Bin Monitoring to improve energy efficiency, environmental safety, and sanitation in Jammu. These IoT systems provide real-time monitoring, reduce operational costs, and improve the quality of life for citizens. The use of ESP32/ESP8266 microcontrollers with Wi-Fi or LoRa communication makes the solution scalable, cost-effective, and suitable for future expansion across the city.
