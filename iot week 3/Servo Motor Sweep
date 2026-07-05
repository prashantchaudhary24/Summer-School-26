#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int buttonPin = 2;
const int servoPin = 9;

void setup() {
  Serial.begin(9600);

  myServo.attach(servoPin);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  // If button is pressed, perform one full sweep
  if (digitalRead(buttonPin) == LOW) {

    // 0° to 180°
    for (int angle = 0; angle <= 180; angle++) {
      myServo.write(angle);
      delay(10);
    }

    // 180° to 0°
    for (int angle = 180; angle >= 0; angle--) {
      myServo.write(angle);
      delay(10);
    }
  }

  // Potentiometer control
  else {

    int sensorValue = analogRead(potPin);

    int angle = map(sensorValue, 0, 1023, 0, 180);

    myServo.write(angle);

    Serial.print("Servo Angle: ");
    Serial.print(angle);
    Serial.println("°");

    delay(100);
  }
}
