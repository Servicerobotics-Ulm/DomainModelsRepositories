#ifndef _FLEETMANAGERCOORDINATIONSERVICEFLEETSENDSENDHANDLER_HH_
#define _FLEETMANAGERCOORDINATIONSERVICEFLEETSENDSENDHANDLER_HH_

#include "CommBasicObjects/CommTaskMessage.hh"
#include <string>

class FleetManagerCoordinationServiceFleetSendSendHandler
{
public:

	FleetManagerCoordinationServiceFleetSendSendHandler(){

	}

	CommBasicObjects::CommTaskMessage handleSend(std::string inString);
};

#endif
