
#include "StartingSensor.h"
#include "GGLogging.h"
#include "GGDefines.h"

StartingSensorState::StartingSensorState(SoilSensor* ss)
{
	soilSensor = ss;
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
