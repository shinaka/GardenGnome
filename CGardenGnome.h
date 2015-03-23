
#pragma once
#include "GGDefines.h"
#include "arduino.h"
#include "GGState.h"
#include "SoilSensor.h"
#include <RF24.h>
class CGardenGnome
{
public:
	CGardenGnome();
	void begin();
	void UpdateSM();
	void SetNewState(EGGState::Type);
	GGState* GetCurrentState() { return States[CurrentState]; }
	RF24* GetRadio() { return radio; }
	SoilSensor* GetSoilSensor() { return &soilSensor; }
protected:
	GGState* States[EGGState::MAX];
	EGGState::Type CurrentState;
	RF24* radio;
	byte addresses[2][6] = { "GNOME", "TRMNL" };
	SoilSensor soilSensor = SoilSensor(SOIL_SENSOR_D_PIN, SOIL_SENSOR_A_PIN);
};

//There should only be a single, global instance of CGardenGnome
static CGardenGnome G_GGnome;
