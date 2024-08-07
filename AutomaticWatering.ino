#include "Solenoid.h"
int FLOW_PIN = 7;
double flowRate;
volatile int count;

Solenoid* solenoids[2] = {nullptr};


void setup() 
{
  // put your setup code here, to run once:
  pinMode(FLOW_PIN, INPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  attachInterrupt(0, Flow, RISING);
  Serial.begin(9600);
  // Solenoids use Serial so they must be created after.
  solenoids[0] = new Solenoid(2, 1);
  solenoids[1] = new Solenoid(4, 2);
}

void loop() 
{
  if (digitalRead(9) == 0)
  {
    solenoids[0]->ToggleSolenoid();
  }
  if (digitalRead(10) == 0)
  {
    solenoids[1]->ToggleSolenoid();
  }
}

void Flow()
{
  count++;
}
