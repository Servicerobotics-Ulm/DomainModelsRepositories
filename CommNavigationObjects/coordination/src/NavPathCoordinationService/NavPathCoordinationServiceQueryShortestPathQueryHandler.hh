#ifndef _NAVPATHCOORDINATIONSERVICEQUERYSHORTESTPATHQUERYHANDLER_HH_
#define _NAVPATHCOORDINATIONSERVICEQUERYSHORTESTPATHQUERYHANDLER_HH_

#include "CommNavigationObjects/CommShortestPathRequest.hh"
#include "CommNavigationObjects/CommShortestPathAnswer.hh"
#include <string>

class NavPathCoordinationServiceQueryShortestPathQueryHandler
{
public:

	NavPathCoordinationServiceQueryShortestPathQueryHandler(){

	}

	CommNavigationObjects::CommShortestPathRequest handleRequest(const std::string& inString);

	std::string handleAnswer(const CommNavigationObjects::CommShortestPathAnswer& answer);
};

#endif
