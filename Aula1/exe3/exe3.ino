//
// Exercício
//

// Project 100 Traffic Lights with sensor light
int redPin = 10;
int yellowPin = 9;
int greenPin = 8;
// Pin connected to LDR
int ldrPin = 0;
// Value read from LDR
int lightVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Read in value from LDR
  lightVal = analogRead(ldrPin);
  Serial.print("\nAnalog in reading: ");
  Serial.print(lightVal);

  digitalWrite(redPin, HIGH);  // turn the red light on
  delay(lightVal);             // wait sensor value

  digitalWrite(yellowPin, HIGH);  // turn on yellow
  delay(lightVal);                // wait sensor value

  digitalWrite(greenPin, HIGH);  // turn green on
  digitalWrite(redPin, LOW);     // turn red off
  digitalWrite(yellowPin, LOW);  // turn yellow off
  delay(lightVal);               // wwait sensor value

  digitalWrite(yellowPin, HIGH);  // turn yellow on
  digitalWrite(greenPin, LOW);    // turn green off
  delay(lightVal);                // wait sensor value

  digitalWrite(yellowPin, LOW);  // turn yellow off
  // now our loop repeats
}
