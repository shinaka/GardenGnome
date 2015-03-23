#include "GGState.h"
#include "CGardenGnome.h"
#include "SoilSensor.h"
class StartingSensorState : public GGState
{
public:
	StartingSensorState(SoilSensor* ss);
	virtual void StateStarting() override;
	virtual void StateEnding() override;
	virtual void StateUpdate() override;
	virtual EGGState::Type GetNextState() override;
	virtual EGGState::Type GetStateIdentifier() override;
	virtual bool IsStateFinished() override;
protected:
	SoilSensor* soilSensor;
};
