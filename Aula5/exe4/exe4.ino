//
// LED com PIR + Display LCD
//

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 6, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// LED pin
int led = 8;
// PIR pin
int sensor = 7;
// by default, no motion detected
int state = LOW;
// store the sensor status (value)
int val = 0;

void setup() {
  // initalize LED as an output
  pinMode(led, OUTPUT);
  // initialize sensor as an input
  pinMode(sensor, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // read sensor value
  val = digitalRead(sensor);

  // check if the sensor is HIGH
  if (val == HIGH) {
    // turn LED ON
    digitalWrite(led, HIGH);
    // delay 500 milliseconds
    delay(500);

    if (state == LOW) {
      // set the cursor to column 0, line 1
      lcd.setCursor(0, 0);
      // print the number of seconds since reset:
      lcd.print("Led Ligado ->");
      // set the cursor to column 0, line 1
      lcd.setCursor(0, 1);
      // print the number of seconds since reset:
      lcd.print("Led desligado ->" + millis() / 1000);
      // update variable state to HIGH
      state = HIGH;
    } else {
      // turn LED OFF
      digitalWrite(led, LOW);
      // delay 500 milliseconds
      delay(500);

      if (state == HIGH) {
        // set the cursor to column 0, line 1
        lcd.setCursor(0, 0);
        // print the number of seconds since reset:
        lcd.print("Led Desligado ->");
        // set the cursor to column 0, line 1
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print("Led desligado ->" + millis() / 1000);
        // update variable state to LOW
        state = LOW;
      }
    }
  }
}