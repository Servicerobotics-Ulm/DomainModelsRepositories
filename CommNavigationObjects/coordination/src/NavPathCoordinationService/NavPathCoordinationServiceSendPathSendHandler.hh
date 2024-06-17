#ifndef _NAVPATHCOORDINATIONSERVICESENDPATHSENDHANDLER_HH_
#define _NAVPATHCOORDINATIONSERVICESENDPATHSENDHANDLER_HH_

#include "CommNavigationObjects/CommNavPath.hh"
#include <string>

class NavPathCoordinationServiceSendPathSendHandler
{
public:

	NavPathCoordinationServiceSendPathSendHandler(){

	}

	CommNavigationObjects::CommNavPath handleSend(std::string inString);
};

#endif
