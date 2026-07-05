const int tempPin = A0;
const int relayLED = 8;
const int buttonPin = 7;

bool relayState = false;
bool manualMode = false;
int lastButtonState = HIGH;

void setup() {
  pinMode(relayLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(relayLED, LOW);

  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * 5.0 / 1023.0;
  float temperature = (voltage - 0.5) * 100.0;

  int buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    manualMode = !manualMode;
    relayState = !relayState;

    digitalWrite(relayLED, relayState);

    Serial.print("Manual Override -> Relay ");
    if (relayState)
      Serial.print("ON");
    else
      Serial.print("OFF");

    Serial.print(" | Temp: ");
    Serial.print(temperature);
    Serial.println(" C");

    delay(200);
  }

  lastButtonState = buttonState;

  if (!manualMode) {

    if (!relayState && temperature > 32) {
      relayState = true;
      digitalWrite(relayLED, HIGH);

      Serial.print("Relay ON | Temp: ");
      Serial.print(temperature);
      Serial.println(" C");
    }

    if (relayState && temperature < 28) {
      relayState = false;
      digitalWrite(relayLED, LOW);

      Serial.print("Relay OFF | Temp: ");
      Serial.print(temperature);
      Serial.println(" C");
    }
  }

  delay(500);
}
