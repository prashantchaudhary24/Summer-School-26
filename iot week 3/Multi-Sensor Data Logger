#define TMP36 A1
#define LDR A0
#define SIG_PIN 9

void setup() {
  Serial.begin(9600);
}

float readDistance() {
  pinMode(SIG_PIN, OUTPUT);

  digitalWrite(SIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(SIG_PIN, HIGH);
  delayMicroseconds(5);

  digitalWrite(SIG_PIN, LOW);

  pinMode(SIG_PIN, INPUT);

  long duration = pulseIn(SIG_PIN, HIGH);

  float distance = duration * 0.0343 / 2.0;

  return distance;
}

void loop() {

  int tempValue = analogRead(TMP36);
  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  int ldrRaw = analogRead(LDR);
  int lightPercent = map(ldrRaw, 0, 1023, 0, 100);

  String lightState;

  if (lightPercent >= 70)
    lightState = "Bright";
  else if (lightPercent >= 30)
    lightState = "Normal";
  else
    lightState = "Dark";

  float distance = readDistance();

  Serial.println("=== SENSOR LOG ===");

  Serial.print("Time      : ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.print("Temp      : ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  Serial.println("Humidity : N/A");

  Serial.print("Light     : ");
  Serial.print(lightPercent);
  Serial.print("% (");
  Serial.print(lightState);
  Serial.println(")");

  Serial.print("Distance  : ");
  Serial.print(distance, 1);
  Serial.println(" cm");

  Serial.println("==================");
  Serial.println();

  delay(5000);
}
