//
// Ativar LED com sensor PIR
//

//Projeto ativar LED com sensor PIR
// pin for the LED
const int ledPin = 2;
// input pin (PIR sensor)
const int inputPin = 7;

void setup() {
  // declare LED as output
  pinMode(ledPin, OUTPUT);
  // declare pin as input
  pinMode(inputPin, INPUT);
}

void loop() {
  // read input value
  int val = digitalRead(inputPin);

  // check if the input is HIGH
  if (val == HIGH) {
    // turn LED on if motion detected
    digitalWrite(ledPin, HIGH);
    delay(500);
    // turn LED off
    digitalWrite(ledPin, LOW);
  }
}