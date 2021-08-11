#ifndef _FESTOMPSVISUALDOCKINGCOORDINATIONSERVICEDETECTIONEVENTEVENTHANDLER_HH_
#define _FESTOMPSVISUALDOCKINGCOORDINATIONSERVICEDETECTIONEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommTrackingObjects/CommDetectedMarkerEventResult.hh"
#include "CommTrackingObjects/CommDetectedMarkerEventParameter.hh"

class FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandler
{
public:
	std::string handleEvent(const CommTrackingObjects::CommDetectedMarkerEventResult &r) throw();
	CommTrackingObjects::CommDetectedMarkerEventParameter activateEventParam(const std::string& parameterString);
};

#endif
