#ifndef _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICEPOSEREQUESTEVENTEVENTHANDLER_HH_
#define _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICEPOSEREQUESTEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommNavigationObjects/CommCorridorNavigationPoseRequestEventResult.hh"
#include "CommNavigationObjects/CommCorridorNavigationPoseRequestEventParameter.hh"

class CorridorNavigationClientCoordinationServicePoserequesteventEventHandler
{
public:
	std::string handleEvent(const CommNavigationObjects::CommCorridorNavigationPoseRequestEventResult &r) throw();
	CommNavigationObjects::CommCorridorNavigationPoseRequestEventParameter activateEventParam(const std::string& parameterString);
};

#endif
