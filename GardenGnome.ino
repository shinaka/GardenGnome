#include "CGardenGnome.h"
#include "PollingSensorState.h"
#include "StartingSensor.h"
#include "ListenState.h"
#include "GGState.h"
#include <SPI.h>
#include <RF24_config.h>
#include <RF24.h>
#include <printf.h>
#include <nRF24L01.h>
#include "GGLogging.h"
#include "SoilSensor.h"

void setup()
{
#if IS_TESTING == 1
	Serial.begin(57600);
	SLOG("Debugging GardenGnome Enabled.");	
#endif
	G_GGnome = CGardenGnome();
	G_GGnome.begin();
}

void loop()
{
	//SLOG("Loop");
	G_GGnome.UpdateSM();
	/*
	if (lastSoilRead == 0 || micros() - lastSoilRead > SOIL_TEST_RATE)
	{
		SLOG("Polling Soil Sensor.");
		//stop listening until we're done, since this causes a delay
		radio.stopListening();
		ReadSoilSensor();
		radio.startListening();
		UpdateGarden();
		lastSoilRead = micros();
	}

	if (radio.available())
	{
		RemoteRequest req;
		while (radio.available())
		{
			radio.read(&req, sizeof(RemoteRequest));
		}

		HandleRemoteRequest(req);
	}
	*/
}/*

void HandleRemoteRequest(struct RemoteRequest req)
{
	SLOG("Remote Request Received");
	SLOG(req.reqType);
	switch (req.reqType)
	{
	case ERequestType::SendSoilValue:
		SendSoilToRemote();
		break;
	default:
		break;
	}
}

void SendSoilToRemote()
{
	radio.stopListening();
	RemoteRequest newReq;
	newReq.reqType = ERequestType::ReceiveSoilValue;
	newReq.payload = lastReadValue;
	if (!radio.write(&newReq, sizeof(newReq)))
	{
		SLOG("Failed to send response to a remote soil value request.");
	}
	radio.startListening();
}

void ReadSoilSensor()
{
	lastReadValue = soilSensor.GetSensorValue();
	SLOG("Soil Sensor Value:");
	SLOG(lastReadValue);
}

void UpdateGarden()
{

}

*/