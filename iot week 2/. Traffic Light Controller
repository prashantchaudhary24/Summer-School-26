const int RED_LED = 10;
const int YELLOW_LED = 9;
const int GREEN_LED = 8;
const int BUTTON = 7;

void allOff() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void printState(String state) {
  Serial.print("Time: ");
  Serial.print(millis());
  Serial.print(" ms --> ");
  Serial.println(state);
}

bool pedestrianPressed() {
  return digitalRead(BUTTON) == LOW;
}

void pedestrianMode() {
  allOff();
  digitalWrite(RED_LED, HIGH);

  printState("PEDESTRIAN REQUEST - RED ON");

  unsigned long startTime = millis();

  while (millis() - startTime < 8000) {
  }

  printState("PEDESTRIAN MODE ENDED");
}

void trafficState(int red, int yellow, int green, unsigned long duration, String name) {
  allOff();

  digitalWrite(RED_LED, red);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(GREEN_LED, green);

  printState(name);

  unsigned long startTime = millis();

  while (millis() - startTime < duration) {
    if (pedestrianPressed()) {
      pedestrianMode();
      return;
    }
  }
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);

  allOff();
}

void loop() {
  trafficState(HIGH, LOW, LOW, 5000, "RED ON");
  trafficState(LOW, HIGH, LOW, 2000, "YELLOW ON");
  trafficState(LOW, LOW, HIGH, 4000, "GREEN ON");
}
