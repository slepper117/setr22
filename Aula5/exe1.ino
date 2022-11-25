#include <Servo.h>
Servo myservo;
int angle = 0;

void setup()
{
  myservo.attach(3);
}

void loop()
{
  for(angle=0; angle<180;angle+=1)
  {
    myservo.write(angle);
    delay(20);
  }

  for(angle = 180; angle>=1;angle -=1)
  {
    myservo.write(angle);
    delay(20);
  }
}

