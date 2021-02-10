#ifndef _IOQUERYCOORDINATIONSERVICEIOQUERYQUERYHANDLER_HH_
#define _IOQUERYCOORDINATIONSERVICEIOQUERYQUERYHANDLER_HH_

#include "CommBasicObjects/CommIOValues.hh"
#include "CommBasicObjects/CommIOValues.hh"
#include <string>

class IOQueryCoordinationServiceIoQueryQueryHandler
{
public:

	IOQueryCoordinationServiceIoQueryQueryHandler(){

	}

	CommBasicObjects::CommIOValues handleRequest(const std::string& inString);

	std::string handleAnswer(const CommBasicObjects::CommIOValues& answer);
};

#endif
