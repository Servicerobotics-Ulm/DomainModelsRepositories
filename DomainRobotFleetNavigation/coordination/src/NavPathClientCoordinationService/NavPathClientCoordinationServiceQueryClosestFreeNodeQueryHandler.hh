#ifndef _NAVPATHCLIENTCOORDINATIONSERVICEQUERYCLOSESTFREENODEQUERYHANDLER_HH_
#define _NAVPATHCLIENTCOORDINATIONSERVICEQUERYCLOSESTFREENODEQUERYHANDLER_HH_

#include "CommBasicObjects/CommPosition3d.hh"
#include "DomainRobotFleetNavigation/CommNode.hh"
#include <string>

class NavPathClientCoordinationServiceQueryClosestFreeNodeQueryHandler
{
public:

	NavPathClientCoordinationServiceQueryClosestFreeNodeQueryHandler(){

	}

	CommBasicObjects::CommPosition3d handleRequest(const std::string& inString);

	std::string handleAnswer(const DomainRobotFleetNavigation::CommNode& answer);
};

#endif
