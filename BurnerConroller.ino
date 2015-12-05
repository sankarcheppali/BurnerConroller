/*
Burner Controller with DC fans

Two DC fans with individual speed control 
Battery Level indication on four leds

A0- M1 (motor1 speed contol)
A2- M2
A3- battery voltage 

PIN 2 - Motor 1(L293D 2 pin,7th pin to ground) 
PIN 3 - Motor 2(L293D 15th Pin,10th pin to ground)
*/
#define M1O 2
#define M2O 3

#define M1I A0
#define M2I A1

int m1i,m2i;

void setup() {
pinMode(M1O,OUTPUT);
pinMode(M2O,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  m1i=analogRead(M1I);
  delay(20);
  m2i=analogRead(M2I);
  analogWrite(M1O,(m1i/1024.0)*255);
  analogWrite(M2O,(m2i/1024.0)*255);
  delay(100);
}
