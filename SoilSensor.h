#pragma once
class SoilSensor
{
public:
	//************************************
	// Method:    SoilSensor
	// Parameter: int _powerpin (The Digital pin that will supply 5v to the sensor)
	// Parameter: int _sensorpin (The Analog pin the sensor's A0 is connected to)
	//************************************
	SoilSensor(int _powerpin, int _sensorpin);

	//Initializes the Sensor Class
	void begin();
	//Wakes the sensor up, waits for a few ms, then polls the sensor and returns the value
	int GetSensorValue();
	void SetSensorPowered(bool isPowered);
protected:
	int SensorPin;
	int PowerPin;
};

