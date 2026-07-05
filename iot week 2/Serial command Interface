const int LED = LED_BUILTIN;
int blinkCounter = 0;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
  Serial.println("Serial Command Interface Ready");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "LED_ON") {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    }
    else if (cmd == "LED_OFF") {
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
    else if (cmd.startsWith("BLINK_")) {
      if (cmd.length() == 7) {
        char c = cmd.charAt(6);

        if (c >= '1' && c <= '9') {
          int times = c - '0';

          for (int i = 0; i < times; i++) {
            digitalWrite(LED, HIGH);
            delay(500);
            digitalWrite(LED, LOW);
            delay(500);
          }

          blinkCounter += times;
          Serial.print("Blinked ");
          Serial.print(times);
          Serial.println(" times");
        }
        else {
          Serial.println("ERROR: Unknown command");
        }
      }
      else {
        Serial.println("ERROR: Unknown command");
      }
    }
    else if (cmd == "STATUS") {
      Serial.print("LED State: ");
      if (digitalRead(LED))
        Serial.println("ON");
      else
        Serial.println("OFF");

      Serial.print("Blink Counter: ");
      Serial.println(blinkCounter);
    }
    else if (cmd == "RESET") {
      blinkCounter = 0;
      Serial.println("Blink counter reset");
    }
    else {
      Serial.println("ERROR: Unknown command");
    }
  }
}
