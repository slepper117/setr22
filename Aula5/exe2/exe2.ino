//
// LED com PIR + Serial Monitor
//

//Projeto ativar LED com sensor PIR
// pin for the LED
const int ledPin = 2;
// input pin (PIR sensor)
const int inputPin = 7;
// by default, no motion detected
int state = LOW;
// store the sensor status (value)
int val = 0;

void setup() {
  // declare LED as output
  pinMode(ledPin, OUTPUT);
  // declare pin as input
  pinMode(inputPin, INPUT);
  // initialize serial
  Serial.begin(9600);
}

void loop() {
  // read input value
  int val = digitalRead(inputPin);

  // check if the input is HIGH
  if (val == HIGH) {
    // turn LED on if motion detected
    digitalWrite(ledPin, HIGH);
    delay(500);

    if (state == LOW) {
      Serial.print("Movimento detetado - LED ligado! -> ");
      Serial.println(millis());
      state = HIGH;  // update variable state to HIGH
    }
  } else {
    // turn LED off
    digitalWrite(ledPin, LOW);
    delay(500);

    if (state == HIGH) {
      Serial.print("LED desligado! -> ");
      Serial.println(millis());
      state = LOW;  // update variable state to LOW
    }
  }
}