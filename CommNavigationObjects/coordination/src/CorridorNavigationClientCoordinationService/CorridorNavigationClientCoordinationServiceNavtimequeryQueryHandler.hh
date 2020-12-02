#ifndef _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICENAVTIMEQUERYQUERYHANDLER_HH_
#define _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICENAVTIMEQUERYQUERYHANDLER_HH_

#include "CommNavigationObjects/CommNavigationTimeRequest.hh"
#include "CommNavigationObjects/CommNavigationTimeResponse.hh"
#include <string>

class CorridorNavigationClientCoordinationServiceNavtimequeryQueryHandler
{
public:

	CorridorNavigationClientCoordinationServiceNavtimequeryQueryHandler(){

	}

	CommNavigationObjects::CommNavigationTimeRequest handleRequest(const std::string& inString);

	std::string handleAnswer(const CommNavigationObjects::CommNavigationTimeResponse& answer);
};

#endif
