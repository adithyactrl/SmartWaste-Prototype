// C++ code

#include <Servo.h>
//pins

#define Red 1
#define Green 2
#define Trig 7
#define Echo 6
#define ServoP 9
Servo myServo;
void setup()
{
  pinMode(Red, OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  myServo.attach(ServoP);
  myServo.write(0);
}

void loop()
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  long duration = pulseIn(Echo, HIGH);
  int distance = duration * 0.034 / 2;
  
   // object closer than 20cm
  
  if (distance < 20) { 
    digitalWrite(Green, HIGH);
    digitalWrite(Red, LOW);
    myServo.write(90);
    delay(100);
  } 
  else {
    digitalWrite(Red, HIGH);
    digitalWrite(Green, LOW);
    myServo.write(0);
  }

  delay(100);


}
