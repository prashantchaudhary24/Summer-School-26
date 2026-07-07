# Q49. Security Vulnerability Analysis

## Problem Statement

An ESP8266 IoT device connects to a public Wi-Fi network. The code contains several security flaws:
- Hardcoded Wi-Fi credentials
- Uses HTTP instead of HTTPS
- Publishes to a public MQTT broker without authentication
- Does not validate incoming commands

---

# Vulnerability 1: Hardcoded Wi-Fi Credentials

### Issue
The Wi-Fi SSID and password are stored directly in the source code.

Example:

```cpp
const char* ssid = "MyWiFi";
const char* password = "12345678";
```

### Risk
- Anyone with access to the source code can view the Wi-Fi credentials.
- If the project is uploaded to GitHub, sensitive information becomes public.

### Solution
Store credentials in a separate `config.h` file and add it to `.gitignore`.

### Corrected Code

```cpp
// config.h

#ifndef CONFIG_H
#define CONFIG_H

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

#endif
```

Main program:

```cpp
#include "config.h"

WiFi.begin(ssid, password);
```

.gitignore

```text
config.h
```

---

# Vulnerability 2: Using HTTP Instead of HTTPS

### Issue

```cpp
http.begin("http://example.com/api");
```

### Risk
- Data is transmitted without encryption.
- Hackers can intercept or modify network traffic (Man-in-the-Middle attack).

### Solution

Use HTTPS with WiFiClientSecure.

### Corrected Code

```cpp
WiFiClientSecure client;

client.setInsecure();     // For testing only

HTTPClient https;

https.begin(client,
"https://example.com/api");
```

---

# Vulnerability 3: Public MQTT Broker Without Authentication

### Issue

```cpp
client.connect("ESP8266");
```

### Risk

- Anyone can publish fake sensor data.
- Anyone can subscribe and read private information.
- Unauthorized users can control IoT devices.

### Solution

Use:

- Private MQTT broker
- Username and password
- TLS encryption (MQTTS)

Example

```cpp
client.connect(
"ESP8266",
"username",
"password");
```

---

# Vulnerability 4: No Validation of Incoming Commands

### Issue

The ESP8266 executes every received command.

### Risk

An attacker can send malicious commands such as:

- Turn ON relay
- Disable alarm
- Reset device

### Solution

Validate every command before executing.

Example

```cpp
if(command=="LED_ON")
{
    digitalWrite(LED_BUILTIN,LOW);
}
else if(command=="LED_OFF")
{
    digitalWrite(LED_BUILTIN,HIGH);
}
else
{
    Serial.println("Invalid Command");
}
```

---

# Vulnerability 5: No Encryption for Sensor Data

### Issue

Sensor readings are sent as plain text.

### Risk

Anyone connected to the same network can:

- Read data
- Modify data
- Replay packets

### Solution

- Use HTTPS
- Use MQTT over TLS (MQTTS)
- Encrypt communication

---

# Summary Table

| Vulnerability | Risk | Recommended Solution |
|---------------|------|----------------------|
| Hardcoded Wi-Fi credentials | Password leakage | Store credentials in `config.h` and ignore with `.gitignore` |
| HTTP communication | Data interception | Use HTTPS (`WiFiClientSecure`) |
| Public MQTT broker | Unauthorized access | Use authentication and TLS |
| No command validation | Remote device control | Validate all incoming commands |
| Unencrypted sensor data | Data theft and tampering | Use HTTPS/MQTTS |

---

# Conclusion

An IoT device should never expose sensitive credentials, transmit data over unencrypted protocols, or accept commands without validation. Using HTTPS, secure MQTT (MQTTS), separate configuration files, authentication, and proper input validation significantly improves the security and reliability of IoT systems.
