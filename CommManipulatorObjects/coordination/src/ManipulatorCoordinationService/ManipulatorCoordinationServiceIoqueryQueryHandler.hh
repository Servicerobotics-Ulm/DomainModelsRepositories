#ifndef _MANIPULATORCOORDINATIONSERVICEIOQUERYQUERYHANDLER_HH_
#define _MANIPULATORCOORDINATIONSERVICEIOQUERYQUERYHANDLER_HH_

#include "CommBasicObjects/CommIOValues.hh"
#include "CommBasicObjects/CommIOValues.hh"
#include <string>

class ManipulatorCoordinationServiceIoqueryQueryHandler
{
public:

	ManipulatorCoordinationServiceIoqueryQueryHandler(){

	}

	CommBasicObjects::CommIOValues handleRequest(const std::string& inString);

	std::string handleAnswer(const CommBasicObjects::CommIOValues& answer);
};

#endif
