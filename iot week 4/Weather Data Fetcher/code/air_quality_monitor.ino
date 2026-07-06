#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

// MQ2
const int mq2=A0;

// RGB
const int RED=9;
const int GREEN=10;
const int BLUE=11;

// Buzzer
const int BUZZER=8;

void setup()
{
Serial.begin(9600);

pinMode(RED,OUTPUT);
pinMode(GREEN,OUTPUT);
pinMode(BLUE,OUTPUT);

pinMode(BUZZER,OUTPUT);

dht.begin();

Serial.println("Timestamp,MQ2 Value,Temperature,Humidity,Severity");
}

void loop()
{

int gas=analogRead(mq2);

float temp=dht.readTemperature();

float hum=dht.readHumidity();

String level;

if(gas<300)
{
level="SAFE";

digitalWrite(GREEN,HIGH);
digitalWrite(RED,LOW);
digitalWrite(BLUE,LOW);

noTone(BUZZER);

Serial.println("SAFE");
Serial.println("Gas:"+String(gas));
Serial.println("Temp:"+String(temp));
Serial.println("Humidity:"+String(hum));
}

else if(gas<600)
{

level="MODERATE";

digitalWrite(GREEN,HIGH);
digitalWrite(RED,HIGH);
digitalWrite(BLUE,LOW);

tone(BUZZER,1000,300);

Serial.println("WARNING");
Serial.println("Moderate Smoke Detected");
Serial.println("Gas="+String(gas));
Serial.println("Check Fireplace");
}

else
{

level="DANGER";

digitalWrite(GREEN,LOW);
digitalWrite(RED,HIGH);
digitalWrite(BLUE,LOW);

tone(BUZZER,2500,1000);

Serial.println("DANGER!!");
Serial.println("Smoke Level Critical");
Serial.println("Gas="+String(gas));
Serial.println("Open Windows");
Serial.println("Leave Room if Necessary");
}

Serial.print(millis()/1000);

Serial.print(",");

Serial.print(gas);

Serial.print(",");

Serial.print(temp);

Serial.print(",");

Serial.print(hum);

Serial.print(",");

Serial.println(level);

delay(2000);

}
