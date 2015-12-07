/*
Burner Controller with DC fans

Two DC fans with individual speed control 
Battery Level indication on four leds

A0- M1 (motor1 speed contol)
A2- M2
A3- battery voltage 

PIN 11 - Motor 1(L293D 2 pin,7th pin to ground) 
PIN 3 - Motor 2(L293D 15th Pin,10th pin to ground)

Battery level in 4 leds, battery is 12v so we have to use
a voltage devider (1/4)
>8v- PIN4
>9V- PIN5
>11V- PIN6
>12.5V- PIN7
*/
#define M1O 11
#define M2O 3
#define bl1 4
#define bl2 5
#define bl3 6
#define bl4 7

#define bl1v 8
#define bl2v 9
#define bl3v 11
#define bl4v 12.5




#define M1I A0
#define M2I A2
#define bat A3

int m1i,m2i,bv;

void setup() {
pinMode(M1O,OUTPUT);
pinMode(M2O,OUTPUT);
pinMode(bl1,OUTPUT);
pinMode(bl2,OUTPUT);
pinMode(bl3,OUTPUT);
pinMode(bl4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  m1i=analogRead(M1I);
  delay(20);
  m2i=analogRead(M2I);
  delay(20);
  checkBat();
  analogWrite(M1O,(m1i/1024.0)*255);
  analogWrite(M2O,(m2i/1024.0)*255);
  //delay(100);
}

void checkBat()
{
	float bv=(analogRead(bat)/1024.0)*20;
	if(bv>bl4v)
	{
          digitalWrite(bl1,0);
          digitalWrite(bl2,0);
          digitalWrite(bl3,0);
          digitalWrite(bl4,1);
	}
	else if(bv>bl3v)
	{
          digitalWrite(bl1,0);
          digitalWrite(bl2,0);
          digitalWrite(bl3,1);
          digitalWrite(bl4,0);

	}
	else if(bv>bl2v)
    {
          digitalWrite(bl1,0);
          digitalWrite(bl2,1);
          digitalWrite(bl3,0);
          digitalWrite(bl4,0);

    }
    else if(bv>bl1v)
    {
          digitalWrite(bl1,1);
          digitalWrite(bl2,0);
          digitalWrite(bl3,0);
          digitalWrite(bl4,0);
    }

}