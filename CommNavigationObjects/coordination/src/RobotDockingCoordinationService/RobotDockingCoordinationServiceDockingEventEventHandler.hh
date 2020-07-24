#ifndef _ROBOTDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLER_HH_
#define _ROBOTDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommNavigationObjects/CommDockingEventResult.hh"
#include "CommNavigationObjects/CommDockingEventParameter.hh"

class RobotDockingCoordinationServiceDockingEventEventHandler
{
public:
	std::string handleEvent(const CommNavigationObjects::CommDockingEventResult &r) throw();
	CommNavigationObjects::CommDockingEventParameter activateEventParam(const std::string& parameterString);
};

#endif
