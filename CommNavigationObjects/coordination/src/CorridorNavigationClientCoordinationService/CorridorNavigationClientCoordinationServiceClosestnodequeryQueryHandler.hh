#ifndef _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICECLOSESTNODEQUERYQUERYHANDLER_HH_
#define _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICECLOSESTNODEQUERYQUERYHANDLER_HH_

#include "CommNavigationObjects/CommClosestNodeRequest.hh"
#include "CommNavigationObjects/CommClosestNodeAnswer.hh"
#include <string>

class CorridorNavigationClientCoordinationServiceClosestnodequeryQueryHandler
{
public:

	CorridorNavigationClientCoordinationServiceClosestnodequeryQueryHandler(){

	}

	CommNavigationObjects::CommClosestNodeRequest handleRequest(const std::string& inString);

	std::string handleAnswer(const CommNavigationObjects::CommClosestNodeAnswer& answer);
};

#endif
