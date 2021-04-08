#ifndef _ROBOTTOROBOTDOCKINGCOORDINATIONSERVICER2RDOCKINGEVENTEVENTHANDLER_HH_
#define _ROBOTTOROBOTDOCKINGCOORDINATIONSERVICER2RDOCKINGEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommRobotinoObjects/CommRobotinoDockingEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoDockingEventParameter.hh"

class RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandler
{
public:
	std::string handleEvent(const CommRobotinoObjects::CommRobotinoDockingEventResult &r) throw();
	CommRobotinoObjects::CommRobotinoDockingEventParameter activateEventParam(const std::string& parameterString);
};

#endif
