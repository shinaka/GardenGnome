#pragma once
#include "Arduino.h"
namespace EGGState
{
	enum Type
	{
		Listening = 0,
		StartingSensor,
		PollingSensor,
		Sending,
		MAX
	};
}

class GGState
{
public:
	virtual void StateStarting()
	{
		stateStartTime = micros();
	};
	virtual void StateEnding() = 0;
	virtual void StateUpdate() = 0;
	virtual EGGState::Type GetNextState() = 0;
	virtual EGGState::Type GetStateIdentifier() = 0;
	virtual bool IsStateFinished() = 0;

protected:
	unsigned long stateStartTime;
};

