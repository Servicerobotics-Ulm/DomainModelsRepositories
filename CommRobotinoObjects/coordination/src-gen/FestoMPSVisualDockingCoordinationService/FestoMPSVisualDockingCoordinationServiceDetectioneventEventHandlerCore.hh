#ifndef _FESTOMPSVISUALDOCKINGCOORDINATIONSERVICEDETECTIONEVENTEVENTHANDLERCORE_HH_
#define _FESTOMPSVISUALDOCKINGCOORDINATIONSERVICEDETECTIONEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommTrackingObjects/CommDetectedMarkerEventResult.hh"
#include "CommTrackingObjects/CommDetectedMarkerEventParameter.hh"
#include "FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandler.hh"

class FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandlerCore : public Smart::IEventHandler<CommTrackingObjects::CommDetectedMarkerEventResult>
{
public:
	FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandlerCore(Smart::IEventClientPattern<CommTrackingObjects::CommDetectedMarkerEventParameter, CommTrackingObjects::CommDetectedMarkerEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommTrackingObjects::CommDetectedMarkerEventResult &r) override;
	CommTrackingObjects::CommDetectedMarkerEventParameter activateEventParam(const std::string& parameterString);
private:
	FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
