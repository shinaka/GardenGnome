#include "CGardenGnome.h"
#include "ListenState.h"
#include "PollingSensorState.h"
#include "StartingSensor.h"
#include "GGLogging.h"

CGardenGnome::CGardenGnome(int _relaypin)
{
	States[EGGState::Listening] = new ListenState(this);
	States[EGGState::PollingSensor] = new PollingSensorState(this);
	States[EGGState::StartingSensor] = new StartingSensorState(this);
}

void CGardenGnome::begin()
{
	pinMode(3, OUTPUT);
	digitalWrite(3, LOW);
	soilSensor.begin();
	radio.begin();
#if IS_TESTING == 1
	radio.setPALevel(RF24_PA_LOW);
#else
	radio.setPALevel(RF24_PA_HIGH);
#endif 
	radio.openWritingPipe(addresses[1]);
	radio.openReadingPipe(1, addresses[0]);
	radio.startListening();
	CurrentState = EGGState::Listening;
	States[CurrentState]->StateStarting();
}

void CGardenGnome::UpdateSM()
{
	States[CurrentState]->StateUpdate();
	//SLOG("Did State Update");
	if (States[CurrentState]->IsStateFinished())
	{
		SetNewState(States[CurrentState]->GetNextState());
	}
}

void CGardenGnome::SetNewState(EGGState::Type)
{
	States[CurrentState]->StateEnding();
	CurrentState = States[CurrentState]->GetNextState();
	States[CurrentState]->StateStarting();
}