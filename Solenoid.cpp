#include "Solenoid.h"
#include "Arduino.h"

Solenoid::Solenoid(int pin, int plantNumber) 
{
    this->m_pin = pin;
    this->SetPinMode();
    char buffer[10];
    Serial.print("Plant: ");
    Serial.print(itoa(plantNumber, buffer, 10)); 
    Serial.print(" on pin: ");
    Serial.println(itoa(pin, buffer, 10));

}

Solenoid::~Solenoid()
{
}


void Solenoid::ToggleSolenoid() 
{
    this->m_isFlowing = !this->m_isFlowing;
    this->m_isFlowing ? this->Activate() : this->Deactivate();
}

void Solenoid::Activate() 
{
    digitalWrite(this->m_pin, HIGH);
    this->m_isFlowing = true;
}

void Solenoid::Deactivate()
{
    digitalWrite(this->m_pin, LOW);
    this->m_isFlowing = false;
}

bool Solenoid::GetIsFlowing() 
{
    return this->m_isFlowing;
}

void Solenoid::SetPinMode() {
    pinMode(this->m_pin, OUTPUT);
}