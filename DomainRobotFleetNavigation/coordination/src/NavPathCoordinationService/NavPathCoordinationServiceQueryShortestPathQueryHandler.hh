#ifndef _NAVPATHCOORDINATIONSERVICEQUERYSHORTESTPATHQUERYHANDLER_HH_
#define _NAVPATHCOORDINATIONSERVICEQUERYSHORTESTPATHQUERYHANDLER_HH_

#include "DomainRobotFleetNavigation/CommShortestPathRequest.hh"
#include "DomainRobotFleetNavigation/CommCorridorPath.hh"
#include <string>

class NavPathCoordinationServiceQueryShortestPathQueryHandler
{
public:

	NavPathCoordinationServiceQueryShortestPathQueryHandler(){

	}

	DomainRobotFleetNavigation::CommShortestPathRequest handleRequest(const std::string& inString);

	std::string handleAnswer(const DomainRobotFleetNavigation::CommCorridorPath& answer);
};

#endif
