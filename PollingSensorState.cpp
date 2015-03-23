#include "PollingSensorState.h"
#include "GGLogging.h"
PollingSensorState::PollingSensorState(CGardenGnome* Owner)
{
	soilSensor = Owner->GetSoilSensor();
}

void PollingSensorState::StateStarting()
{
	SLOG("Polling State Started");
	GGState::StateStarting();
	int value = soilSensor->GetSensorValue();
	if (value < 500)
	{
		digitalWrite(3, LOW);
	}
	else
	{
		digitalWrite(3, HIGH);
	}
	SLOG(value);
}

void PollingSensorState::StateEnding()
{
	SLOG("Polling State Ended");
	soilSensor->SetSensorPowered(false);
}

void PollingSensorState::StateUpdate()
{
	//SLOG("Polling State Update");
}

EGGState::Type PollingSensorState::GetNextState()
{
	return EGGState::Listening;
}

EGGState::Type PollingSensorState::GetStateIdentifier()
{
	return EGGState::PollingSensor;
}

bool PollingSensorState::IsStateFinished()
{
	return true;
}
