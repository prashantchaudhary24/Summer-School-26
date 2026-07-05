

const int EN = 9;      // PWM
const int IN1 = 8;
const int IN2 = 7;

const int potPin = A0;

const int dirButton = 2;
const int startButton = 3;

bool direction = true;   // true = Forward
bool motorON = true;

bool lastDirState = HIGH;
bool lastStartState = HIGH;

void setup() {

  Serial.begin(9600);

  pinMode(EN, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(dirButton, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);
}

void loop() {

  // Direction Button
  bool dirState = digitalRead(dirButton);

  if (dirState == LOW && lastDirState == HIGH) {

    direction = !direction;

    delay(150);
  }

  lastDirState = dirState;

  // Start / Stop Button
  bool startState = digitalRead(startButton);

  if (startState == LOW && lastStartState == HIGH) {

    motorON = !motorON;

    delay(150);
  }

  lastStartState = startState;

  // Read Potentiometer
  int potValue = analogRead(potPin);

  int pwmValue = map(potValue, 0, 1023, 0, 255);

  int speedPercent = map(pwmValue, 0, 255, 0, 100);

  if (motorON) {

    analogWrite(EN, pwmValue);

    if (direction) {

      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

    } else {

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);

    }

  } else {

    analogWrite(EN, 0);

  }

  Serial.print("Direction: ");

  if (direction)
    Serial.print("Forward");
  else
    Serial.print("Reverse");

  Serial.print(" | Speed: ");
  Serial.print(speedPercent);
  Serial.print("%");

  Serial.print(" | State: ");

  if (motorON)
    Serial.println("Running");
  else
    Serial.println("Stopped");

  delay(300);
}
