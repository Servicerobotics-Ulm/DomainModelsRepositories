#ifndef _NAVPATHCOORDINATIONSERVICESENDPATHSENDHANDLER_HH_
#define _NAVPATHCOORDINATIONSERVICESENDPATHSENDHANDLER_HH_

#include "DomainRobotFleetNavigation/CommNavPath.hh"
#include <string>

class NavPathCoordinationServiceSendPathSendHandler
{
public:

	NavPathCoordinationServiceSendPathSendHandler(){

	}

	DomainRobotFleetNavigation::CommNavPath handleSend(std::string inString);
};

#endif
