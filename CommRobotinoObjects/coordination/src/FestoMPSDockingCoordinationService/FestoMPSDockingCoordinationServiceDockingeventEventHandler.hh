#ifndef _FESTOMPSDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLER_HH_
#define _FESTOMPSDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommRobotinoObjects/CommRobotinoDockingEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoDockingEventParameter.hh"

class FestoMPSDockingCoordinationServiceDockingeventEventHandler
{
public:
	std::string handleEvent(const CommRobotinoObjects::CommRobotinoDockingEventResult &r) throw();
	CommRobotinoObjects::CommRobotinoDockingEventParameter activateEventParam(const std::string& parameterString);
};

#endif
