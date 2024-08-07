class PlantController 
{
public: 
    PlantController(int solenoidPin, int moisturePin, int plantNumber);
    ~PlantController();

    void ToggleSolenoid();
    bool GetIsFlowing();
    float GetMoisture();
    int GetRawMoisture();
    int GetPlantNumber();
    void Activate();
    void Deactivate();
private:
    void SetPinMode();
    int m_solenoidPin;
    int m_moistureSensorPin;
    int m_plantNumber;
    bool m_isSolenoidOpen = false;
};