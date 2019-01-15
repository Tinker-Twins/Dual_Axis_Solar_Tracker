#include <Servo.h>


//Defining Servos
Servo servoHorizontal;
int servoH = 0;
int servoHLimitHigh = 160;
int servoHLimitLow = 20;

Servo servoVertical; 
int servoV = 0; 
int servoVLimitHigh = 160;
int servoVLimitLow = 20;


//Assigning LDR Pins
#define ldrTopLeft A2       //top left LDR
#define ldrTopRight A1      //top right LDR
#define ldrBottomLeft A3    // bottom left LDR
#define ldrBottomRight A0   // bottom right LDR


void setup () 
 {
  servoHorizontal.attach(10);
  servoHorizontal.write(0);
  servoVertical.attach(9);
  servoVertical.write(0);
  delay(500);
 }


void loop()
{
  servoH = servoHorizontal.read();
  servoV = servoVertical.read();
  
  //capturing analog values of each LDR
  int topLeft = analogRead(ldrTopLeft);
  int topRight = analogRead(ldrTopRight);
  int bottomLeft = analogRead(ldrBottomLeft);
  int bottomRight = analogRead(ldrBottomRight);
  
  // calculating average
  int avgTop = (topLeft + topRight)/2;              //average of top LDRs
  int avgBottom = (bottomLeft + bottomRight)/2;     //average of bottom LDRs
  int avgLeft = (topLeft + bottomLeft)/2;           //average of left LDRs
  int avgRight = (topRight + bottomRight)/2;        //average of right LDRs

  if (avgTop < avgBottom)
  {
    servoVertical.write(servoV -1);
    if (servoV > servoVLimitHigh) 
     { 
      servoV = servoVLimitHigh;
     }
    delay(10);
  }
  else if (avgBottom < avgTop)
  {
    servoVertical.write(servoV +1);
    if (servoV < servoVLimitLow)
  {
    servoV = servoVLimitLow;
  }
    delay(10);
  }
  else 
  {
    servoVertical.write(servoV);
  }
  
  if (avgLeft > avgRight)
  {
    servoHorizontal.write(servoH +1);
    if (servoH > servoHLimitHigh)
    {
    servoH = servoHLimitHigh;
    }
    delay(10);
  }
  else if (avgRight > avgLeft)
  {
    servoHorizontal.write(servoH -1);
    if (servoH < servoHLimitLow)
     {
     servoH = servoHLimitLow;
     }
    delay(10);
  }
  else 
  {
    servoHorizontal.write(servoH);
  }
  delay(50);
}
