#ifndef _MAPPERCOORDINATIONSERVICELTMMAPDATAQUERYHANDLER_HH_
#define _MAPPERCOORDINATIONSERVICELTMMAPDATAQUERYHANDLER_HH_

#include "CommNavigationObjects/CommGridMapRequest.hh"
#include "CommNavigationObjects/CommGridMap.hh"
#include <string>

class MapperCoordinationServiceLtmMapDataQueryHandler
{
public:

	MapperCoordinationServiceLtmMapDataQueryHandler(){

	}

	CommNavigationObjects::CommGridMapRequest handleRequest(const std::string& inString);

	std::string handleAnswer(const CommNavigationObjects::CommGridMap& answer);
};

#endif
