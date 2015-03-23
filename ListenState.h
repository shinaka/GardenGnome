#include "GGState.h"
#include "CGardenGnome.h"

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
	ListenState(CGardenGnome* creator);
	virtual void StateStarting() override;
	virtual void StateEnding() override;
	virtual void StateUpdate() override;
	virtual EGGState::Type GetNextState() override;
	virtual EGGState::Type GetStateIdentifier() override;
	virtual bool IsStateFinished() override;
protected:
	RF24* radio;
};
