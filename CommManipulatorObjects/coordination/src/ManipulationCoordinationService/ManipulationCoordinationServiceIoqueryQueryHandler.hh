#ifndef _MANIPULATIONCOORDINATIONSERVICEIOQUERYQUERYHANDLER_HH_
#define _MANIPULATIONCOORDINATIONSERVICEIOQUERYQUERYHANDLER_HH_

#include "CommBasicObjects/CommIOValues.hh"
#include "CommBasicObjects/CommIOValues.hh"
#include <string>

class ManipulationCoordinationServiceIoqueryQueryHandler
{
public:

	ManipulationCoordinationServiceIoqueryQueryHandler(){

	}

	CommBasicObjects::CommIOValues handleRequest(const std::string& inString);

	std::string handleAnswer(const CommBasicObjects::CommIOValues& answer);
};

#endif
