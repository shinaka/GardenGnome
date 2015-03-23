#pragma once
#include "GGState.h"
#include "CGardenGnome.h"
#include <SPI.h>
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>

namespace ERequestType
{
	enum Type
	{
		SendSoilValue = 0,
		ReceiveSoilValue = 1,
	};
}

struct RemoteRequest
{
	ERequestType::Type reqType;
	int payload;
};

class ListenState : public GGState
{
public:
	ListenState(RF24* _radio);
	virtual void StateStarting() override;
	virtual void StateEnding() override;
	virtual void StateUpdate() override;
	virtual EGGState::Type GetNextState() override;
	virtual EGGState::Type GetStateIdentifier() override;
	virtual bool IsStateFinished() override;
protected:
	RF24* radio;
};
