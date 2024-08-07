class Solenoid 
{
public: 
    Solenoid(int pin, int plantNumber);
    ~Solenoid();

    void ToggleSolenoid();
    bool GetIsFlowing();
    void Activate();
    void Deactivate();
private:
    void SetPinMode();
    int m_pin;
    bool m_isFlowing = false;
};