#ifndef _PUREPURSUITNAVIGATIONCOORDINATIONSERVICEGOALEVENTEVENTHANDLER_HH_
#define _PUREPURSUITNAVIGATIONCOORDINATIONSERVICEGOALEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommNavigationObjects/CommCdlGoalEventResult.hh"
#include "CommNavigationObjects/CommCdlGoalEventParameter.hh"

class PurePursuitNavigationCoordinationServiceGoalEventEventHandler
{
public:
	std::string handleEvent(const CommNavigationObjects::CommCdlGoalEventResult &r) throw();
	CommNavigationObjects::CommCdlGoalEventParameter activateEventParam(const std::string& parameterString);
};

#endif
