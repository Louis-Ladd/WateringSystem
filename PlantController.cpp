#include "PlantController.h"
#include "Arduino.h"

PlantController::PlantController(int solenoidPin, int moisturePin, int plantNumber) 
{
    this->m_solenoidPin = solenoidPin;
    this->m_moistureSensorPin = moisturePin;
    this->m_plantNumber = plantNumber;
    this->SetPinMode();
    char buffer[10];
    Serial.print("PlantController: ");
    Serial.print(itoa(plantNumber, buffer, 10)); 
    Serial.print(" on pin: ");
    Serial.println(itoa(solenoidPin, buffer, 10));

}

PlantController::~PlantController()
{
}


void PlantController::ToggleSolenoid() 
{
    this->m_isSolenoidOpen = !this->m_isSolenoidOpen;
    this->m_isSolenoidOpen ? this->Activate() : this->Deactivate();
}

void PlantController::Activate() 
{
    digitalWrite(this->m_solenoidPin, HIGH);
    Serial.print("Plant: ");
    Serial.print(this->m_plantNumber);
    Serial.println(" is WATERING");
    this->m_isSolenoidOpen = true;
}

void PlantController::Deactivate()
{
    digitalWrite(this->m_solenoidPin, LOW);
    Serial.print("Plant: ");
    Serial.print(this->m_plantNumber);
    Serial.println(" is NOT WATERING");
    this->m_isSolenoidOpen = false;
}

bool PlantController::GetIsFlowing() 
{
    return this->m_isSolenoidOpen;
}

float PlantController::GetMoisture() 
{
    return -(GetRawMoisture()/1023.0) + 1;
}

int PlantController::GetRawMoisture()
{
    return analogRead(this->m_moistureSensorPin); 
}

int PlantController::GetPlantNumber() 
{
    return this->m_plantNumber;
}

void PlantController::SetPinMode() {
    pinMode(this->m_solenoidPin, OUTPUT);
}