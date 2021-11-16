#ifndef _NAVPATHCOORDINATIONSERVICEQUERYSHORTESTPATHQUERYHANDLER_HH_
#define _NAVPATHCOORDINATIONSERVICEQUERYSHORTESTPATHQUERYHANDLER_HH_

#include "DomainRobotFleetNavigation/CommShortestPathRequest.hh"
#include "DomainRobotFleetNavigation/CommShortestPathAnswer.hh"
#include <string>

class NavPathCoordinationServiceQueryShortestPathQueryHandler
{
public:

	NavPathCoordinationServiceQueryShortestPathQueryHandler(){

	}

	DomainRobotFleetNavigation::CommShortestPathRequest handleRequest(const std::string& inString);

	std::string handleAnswer(const DomainRobotFleetNavigation::CommShortestPathAnswer& answer);
};

#endif
