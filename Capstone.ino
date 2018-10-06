#include <Servo.h>
#define LS 2 // left sensor
#define RS 3 // right sensor
#define LM1 5 // left motor M1a
#define LM2 4 // left motor M2a
#define RM1 7 // right motor M2a
#define RM2 6 // right motor M2b

Servo servo;

int trigPin = 9;
int echoPin = 10;

void setup()
{

   servo.attach(8);
   servo.write(0);

   Serial.begin(9600); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   
   pinMode(LS, INPUT);
   pinMode(RS, INPUT);
   pinMode(LM1, OUTPUT);
   pinMode(LM2, OUTPUT);
   pinMode(RM1, OUTPUT);
   pinMode(RM2, OUTPUT);
}
void loop()
{

  int x = 0;
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
  
while(x = 0)
{
  if(distance <= 10)
  {
  
     if(digitalRead(LS) && digitalRead(RS)) // Move Forward on line
     {
       digitalWrite(LM1, HIGH);
       digitalWrite(LM2, LOW);
       digitalWrite(RM1, HIGH);
       digitalWrite(RM2, LOW);
     }
     if(digitalRead(LS) && !(digitalRead(RS))) // turn left by rotationg left motors in forward and right ones in backward direction
     {
       digitalWrite(LM1, HIGH);
       digitalWrite(LM2, LOW);
       digitalWrite(RM1, LOW);
       digitalWrite(RM2, HIGH);
     }
     if(!(digitalRead(LS)) && digitalRead(RS)) // Turn right by rotating right motors in forward and left ones in backward direction
     {
       digitalWrite(LM1, LOW);
       digitalWrite(LM2, HIGH);
       digitalWrite(RM1, HIGH);
       digitalWrite(RM2, LOW);
     }

     if(!(digitalRead(LS)) && !(digitalRead(RS))) // Finish line, stop both the motors
     {
       digitalWrite(LM1, LOW);
       digitalWrite(LM2, LOW);
       digitalWrite(RM1, LOW);
       digitalWrite(RM2, LOW);

       delay(15);

       servo.write(180); 
                      
       delay(15);
       digitalWrite(LM1, LOW);
       digitalWrite(LM2, HIGH);
       digitalWrite(RM1, LOW);
       digitalWrite(RM2, HIGH);

           if(digitalRead(LS) && !(digitalRead(RS))) // turn left by rotationg left motors in forward and right ones in backward direction
            {
              digitalWrite(LM1, LOW);
              digitalWrite(LM2, HIGH);
              digitalWrite(RM1, HIGH);
              digitalWrite(RM2, LOW);
            } 

          if(!(digitalRead(LS)) && digitalRead(RS)) // Turn right by rotating right motors in forward and left ones in backward direction
            {
              digitalWrite(LM1, HIGH);
              digitalWrite(LM2, LOW);
              digitalWrite(RM1, LOW);
              digitalWrite(RM2, HIGH);
            } 

           if(!(digitalRead(LS)) && !(digitalRead(RS))) // Finish line, stop both the motors
            {
              digitalWrite(LM1, LOW);
              digitalWrite(LM2, LOW);
              digitalWrite(RM1, LOW);
              digitalWrite(RM2, LOW);
              x = 0;
            }
  }
  else if(distance > 10)
  {
       digitalWrite(LM1, LOW);
       digitalWrite(LM2, LOW);
       digitalWrite(RM1, LOW);
       digitalWrite(RM2, LOW);

  }
}
}
}
