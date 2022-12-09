//
// Controlo de intensidade de luz do LED com PWM
//

//Example: Control LED intensity, activated with pressure b
#define LED 11    // the pin for the LED - PUM
#define BUTTON 2  // the input pin where the
//pushbutton is connected
int val = 0;  // val will be used to store the state
// of the input pin
int i;
float Output;
unsigned long time, timeinit = millis() / 1000;

void setup() {
  pinMode(LED, OUTPUT);    // tell Arduino LED is an output
  pinMode(BUTTON, INPUT);  // and BUTTON is an input
  Serial.begin(9600);
}

void loop() {
  time = millis() / 1000 - timeinit;
  val = digitalRead(BUTTON);  // read input value and store it

  // check whether the input is HIGH (button pressed)
  if (val == HIGH) {
    Serial.print("Button Pressed: ");
    Serial.println(time);
    Serial.print("s\n");

    // loop from 0 to 254 (fade
    for (i = 1; i <= 255; i++) {
      analogWrite(LED, i);
      Output = i * 5 / 255;
      Serial.print("Output Voltage: ");
      Serial.println((int)Output);
      Serial.print(".");
      Serial.println(i * 5 % 255);
      Serial.print(" V\n");
      delay(10);  // Wait 10ms because analogWrite is instantaneous and we would not see any change
    }

    // loop from 255 to 1 (fade
    for (i = 255; i >= 1; i--) {
      analogWrite(LED, i);  // set the LED brightness
      Output = i * 5 / 255;
      Serial.print("Output Voltage: ");
      Serial.println((int)Output);
      Serial.print(".");
      Serial.println(i * 5 % 255);
      Serial.print("V\n");
      delay(10);  // Wait 10ms
    }
  }
}
