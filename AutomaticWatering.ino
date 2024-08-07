#include "PlantController.h"
int FLOW_PIN = 7;
double flowRate;
volatile int count;

PlantController* plants[2] = {nullptr};


void setup() 
{
  // put your setup code here, to run once:
  pinMode(FLOW_PIN, INPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  attachInterrupt(0, Flow, RISING);
  Serial.begin(9600);
  // Solenoids use Serial so they must be created after.
  plants[0] = new PlantController(2, A0, 1);
  plants[1] = new PlantController(4, A1, 2);
}

void loop() 
{
  Serial.print("Plant 0 Current moisture: ");
  Serial.println(plants[0]->GetMoisture());

  if (digitalRead(9) == LOW)
  {
    plants[0]->ToggleSolenoid();
  }
  if (digitalRead(10) == LOW)
  {
    plants[1]->ToggleSolenoid();
  }
  delay(150);
}

void Flow()
{
  count++;
}
