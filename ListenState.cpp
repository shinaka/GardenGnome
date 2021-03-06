// 
// 
// 


#include "ListenState.h"
#include "Arduino.h"
#include "GGLogging.h"

ListenState::ListenState(RF24* _radio)
{
	radio = _radio;
}

void ListenState::StateStarting()
{
	SLOG("Listen State Started");
	GGState::StateStarting();
	radio->startListening();
}

void ListenState::StateEnding()
{
	SLOG("Listen State Ending");
	radio->stopListening();
}

void ListenState::StateUpdate()
{
	//SLOG("Listen State Update");
	if (radio->available())
	{
		RemoteRequest req;
		while (radio->available())
		{
			SLOG("Listen State: Reading in Radio Request.");
			radio->read(&req, sizeof(RemoteRequest));
		}
	}
}

EGGState::Type ListenState::GetNextState()
{
	return EGGState::StartingSensor;
}

EGGState::Type ListenState::GetStateIdentifier()
{
	return EGGState::Listening;
}

bool ListenState::IsStateFinished()
{
	//SLOG("Listen State Finished?");
	//SLOG(micros() - stateStartTime);
	return micros() - stateStartTime > LISTEN_STATE_DURATION;
}