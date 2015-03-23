#define STARTING_STATE_DURATION 5000000 //1 second
#include "StartingSensor.h"
#include "GGLogging.h"
StartingSensorState::StartingSensorState(CGardenGnome* Owner)
{
	soilSensor = Owner->GetSoilSensor();
}

void StartingSensorState::StateStarting()
{
	SLOG("StartingSensor State Started");
	GGState::StateStarting();
	soilSensor->SetSensorPowered(true);
}

void StartingSensorState::StateEnding()
{
	SLOG("StartingSensor State Ending");
}

void StartingSensorState::StateUpdate()
{
	//SLOG("StartingSensor State Update");
}

EGGState::Type StartingSensorState::GetNextState()
{
	return EGGState::PollingSensor;
}

EGGState::Type StartingSensorState::GetStateIdentifier()
{
	return EGGState::StartingSensor;
}

bool StartingSensorState::IsStateFinished()
{
	return micros() - stateStartTime > STARTING_STATE_DURATION;
}
