//
// Controlar a posição de rotação com um servo
//
#include <Servo.h>

// create servo object to control a servo
Servo myservo;
// variable to store the servo position
int angle = 0;

void setup() {
  // attaches the servo on pin 9 to the servo object
  myservo.attach(3);
}

void loop() {
  // goes from 0 degrees to 180 degrees
  for (angle = 0; angle < 180; angle += 1) {  // in steps of 1 degree
    // tell servo to go to position in variable 'angle'
    myservo.write(angle);
    // waits 20 ms between servo commands
    delay(20);
  }

  // goes from 180 degrees to 0 degrees
  for (angle = 180; angle >= 1; angle -= 1) {
    // move servo in opposite direction
    myservo.write(angle);
    // waits 20 ms between servo commands
    delay(20);
  }
}