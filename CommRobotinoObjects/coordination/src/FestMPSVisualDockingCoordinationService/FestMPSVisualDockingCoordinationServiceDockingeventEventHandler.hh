#ifndef _FESTMPSVISUALDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLER_HH_
#define _FESTMPSVISUALDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommRobotinoObjects/CommRobotinoDockingEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoDockingEventParameter.hh"

class FestMPSVisualDockingCoordinationServiceDockingeventEventHandler
{
public:
	std::string handleEvent(const CommRobotinoObjects::CommRobotinoDockingEventResult &r) throw();
	CommRobotinoObjects::CommRobotinoDockingEventParameter activateEventParam(const std::string& parameterString);
};

#endif
