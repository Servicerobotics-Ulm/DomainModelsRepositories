#ifndef _BUNDLEDNAVIGATIONCOORDINATIONSERVICEGOALEVENTEVENTHANDLER_HH_
#define _BUNDLEDNAVIGATIONCOORDINATIONSERVICEGOALEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommNavigationObjects/CommBundledNavigationEventResult.hh"
#include "CommNavigationObjects/CommBundledNavigationEventParameter.hh"

class BundledNavigationCoordinationServiceGoalEventEventHandler
{
public:
	std::string handleEvent(const CommNavigationObjects::CommBundledNavigationEventResult &r) throw();
	CommNavigationObjects::CommBundledNavigationEventParameter activateEventParam(const std::string& parameterString);
};

#endif
