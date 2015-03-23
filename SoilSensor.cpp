// 
// 
// 
#define SENSOR_WAIT_TIME 1000

#include "SoilSensor.h"
#include "arduino.h"
#include "GGLogging.h"
SoilSensor::SoilSensor(int _powerpin, int _sensorpin)
{
	SensorPin = _sensorpin;
	PowerPin = _powerpin;
}

int SoilSensor::GetSensorValue()
{
	SLOG("Get Sensor Value");
	lastReadTime = micros();
	return lastReadValue = analogRead(SensorPin);
}

void SoilSensor::begin()
{
	pinMode(PowerPin, OUTPUT);
}

void SoilSensor::SetSensorPowered(bool isPowered)
{
	SLOG("SetSensorPowered:");
	SLOG(isPowered);
	if (isPowered)
	{
		digitalWrite(PowerPin, HIGH);
	}
	else
	{
		digitalWrite(PowerPin, LOW);
	}
}

