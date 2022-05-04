#ifndef _NAVPATHCOORDINATIONSERVICEQUERYCLOSESTFREENODEQUERYHANDLER_HH_
#define _NAVPATHCOORDINATIONSERVICEQUERYCLOSESTFREENODEQUERYHANDLER_HH_

#include "CommBasicObjects/CommPosition3d.hh"
#include "DomainRobotFleetNavigation/CommNode.hh"
#include <string>

class NavPathCoordinationServiceQueryClosestFreeNodeQueryHandler
{
public:

	NavPathCoordinationServiceQueryClosestFreeNodeQueryHandler(){

	}

	CommBasicObjects::CommPosition3d handleRequest(const std::string& inString);

	std::string handleAnswer(const DomainRobotFleetNavigation::CommNode& answer);
};

#endif
