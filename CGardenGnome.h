#pragma once
#include "arduino.h"
#include "GGState.h"
#include "SoilSensor.h"
#include "../SPI/SPI.h"
#include "../RF24-master/RF24_config.h"
#include "../RF24-master/RF24.h"
#include "../RF24-master/nRF24L01.h"
class CGardenGnome
{
public:
	CGardenGnome(int _relaypin);
	void begin();
	void UpdateSM();
	void SetNewState(EGGState::Type);
	GGState* GetCurrentState() { return States[CurrentState]; }
	RF24* GetRadio() { return &radio; }
	SoilSensor* GetSoilSensor() { return &soilSensor; }
protected:
	GGState* States[EGGState::MAX];
	EGGState::Type CurrentState;
	RF24 radio = RF24(7, 8);
	byte addresses[2][6] = { "GNOME", "TRMNL" };
	SoilSensor soilSensor = SoilSensor(2, A0);
};

