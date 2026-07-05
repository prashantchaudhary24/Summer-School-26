const int ledPin = 9;
const int buttonPin = 7;

int mode = 1;
int lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Mode 1: Slow Breathing");
}

void checkButton() {
  int buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    mode++;
    if (mode > 3) mode = 1;

    if (mode == 1)
      Serial.println("Mode 1: Slow Breathing");
    else if (mode == 2)
      Serial.println("Mode 2: Fast Pulse");
    else
      Serial.println("Mode 3: SOS Pattern");

    delay(200);
  }

  lastButtonState = buttonState;
}

void slowBreathing() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(6);
    checkButton();
    if (mode != 1) return;
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(6);
    checkButton();
    if (mode != 1) return;
  }
}

void fastPulse() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(1);
    checkButton();
    if (mode != 2) return;
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(1);
    checkButton();
    if (mode != 2) return;
  }
}

void blinkSOS(int onTime) {
  analogWrite(ledPin, 255);
  delay(onTime);
  analogWrite(ledPin, 0);
  delay(200);
  checkButton();
}

void sosPattern() {
  for (int i = 0; i < 3; i++) {
    blinkSOS(200);
    if (mode != 3) return;
  }

  for (int i = 0; i < 3; i++) {
    blinkSOS(600);
    if (mode != 3) return;
  }

  for (int i = 0; i < 3; i++) {
    blinkSOS(200);
    if (mode != 3) return;
  }

  delay(800);
}

void loop() {
  checkButton();

  if (mode == 1)
    slowBreathing();
  else if (mode == 2)
    fastPulse();
  else
    sosPattern();
}
