#ifndef _FESTOMPSVISUALDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLER_HH_
#define _FESTOMPSVISUALDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommRobotinoObjects/CommRobotinoDockingEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoDockingEventParameter.hh"

class FestoMPSVisualDockingCoordinationServiceDockingeventEventHandler
{
public:
	std::string handleEvent(const CommRobotinoObjects::CommRobotinoDockingEventResult &r) throw();
	CommRobotinoObjects::CommRobotinoDockingEventParameter activateEventParam(const std::string& parameterString);
};

#endif
