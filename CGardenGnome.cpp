#include "CGardenGnome.h"
#include "ListenState.h"
#include "PollingSensorState.h"
#include "StartingSensor.h"
#include "GGLogging.h"
#include "GGDefines.h"

CGardenGnome::CGardenGnome()
{
	radio = new RF24(RF24_MISO_PIN, RF24_MOSI_PIN);
}

void CGardenGnome::begin()
{
	States[EGGState::Listening] = new ListenState(radio);
	States[EGGState::PollingSensor] = new PollingSensorState(&soilSensor);
	States[EGGState::StartingSensor] = new StartingSensorState(&soilSensor);
	pinMode(RELAY_DATA_PIN, OUTPUT);
	digitalWrite(RELAY_DATA_PIN, LOW);
	soilSensor.begin();
	radio->begin();
#if IS_TESTING == 1
	radio->setPALevel(RF24_PA_LOW);
#else
	radio.setPALevel(RF24_PA_HIGH);
#endif 
	radio->openWritingPipe(addresses[1]);
	radio->openReadingPipe(1, addresses[0]);
	radio->startListening();
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