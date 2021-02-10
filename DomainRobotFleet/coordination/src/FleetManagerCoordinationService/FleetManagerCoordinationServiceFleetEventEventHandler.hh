#ifndef _FLEETMANAGERCOORDINATIONSERVICEFLEETEVENTEVENTHANDLER_HH_
#define _FLEETMANAGERCOORDINATIONSERVICEFLEETEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommBasicObjects/CommTaskMessage.hh"
#include "CommBasicObjects/CommTaskMessage.hh"

class FleetManagerCoordinationServiceFleetEventEventHandler
{
public:
	std::string handleEvent(const CommBasicObjects::CommTaskMessage &r) throw();
	CommBasicObjects::CommTaskMessage activateEventParam(const std::string& parameterString);
};

#endif
