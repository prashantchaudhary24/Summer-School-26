const int redLED = 8;
const int greenLED = 9;
const int blueLED = 10;

char command;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);

  Serial.begin(9600);   // HC-05 default baud rate
}

void loop()
{
  if (Serial.available())
  {
    command = Serial.read();

    switch (command)
    {
      case 'R':
      case 'r':
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        break;

      case 'G':
      case 'g':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, LOW);
        break;

      case 'B':
      case 'b':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, HIGH);
        break;

      case 'X':
      case 'x':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        break;

      case 'F':
      case 'f':
        flashLEDs();
        break;
    }
  }
}

void flashLEDs()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);

    delay(300);

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);

    delay(300);
  }
}
