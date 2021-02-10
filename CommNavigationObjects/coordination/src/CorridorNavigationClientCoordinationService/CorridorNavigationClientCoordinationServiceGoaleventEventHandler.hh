#ifndef _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICEGOALEVENTEVENTHANDLER_HH_
#define _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICEGOALEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommNavigationObjects/CommCorridorNavigationGoalEventResult.hh"
#include "CommNavigationObjects/CommCorridorNavigationGoalEventParameter.hh"

class CorridorNavigationClientCoordinationServiceGoaleventEventHandler
{
public:
	std::string handleEvent(const CommNavigationObjects::CommCorridorNavigationGoalEventResult &r) throw();
	CommNavigationObjects::CommCorridorNavigationGoalEventParameter activateEventParam(const std::string& parameterString);
};

#endif
