#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int greenLED = 10;
const int redLED = 11;
const int buzzer = 12;

String password = "1234";
String enteredPin = "";

int attempts = 0;
bool locked = false;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("ENTER PIN:");
}

void loop() {

  if (locked) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SYSTEM LOCKED");
    lcd.setCursor(0,1);
    lcd.print("Wait 10 Sec");

    delay(10000);

    attempts = 0;
    locked = false;
    enteredPin = "";

    lcd.clear();
    lcd.print("ENTER PIN:");
  }

  char key = keypad.getKey();

  if (key) {

    if (key >= '0' && key <= '9') {

      lcd.setCursor(enteredPin.length(),1);
      lcd.print("*");

      enteredPin += key;
    }

    if (enteredPin.length() == 4) {

      if (enteredPin == password) {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("GRANTED");

        digitalWrite(greenLED, HIGH);

        delay(3000);

        digitalWrite(greenLED, LOW);

        attempts = 0;
      }
      else {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("DENIED");

        digitalWrite(redLED, HIGH);

        tone(buzzer,1000);

        delay(2000);

        noTone(buzzer);

        digitalWrite(redLED, LOW);

        attempts++;

        if (attempts >= 3) {
          locked = true;
        }
      }

      enteredPin = "";

      lcd.clear();
      lcd.print("ENTER PIN:");
    }
  }
}
