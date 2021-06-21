#ifndef _EXTERNALPROGAMCOORDINATIONSERVICEPROGRAMLISTQUERYQUERYHANDLER_HH_
#define _EXTERNALPROGAMCOORDINATIONSERVICEPROGRAMLISTQUERYQUERYHANDLER_HH_

#include "CommBasicObjects/CommVoid.hh"
#include "DomainExternalSystems/CommProgramList.hh"
#include <string>

class ExternalProgamCoordinationServiceProgramListQueryQueryHandler
{
public:

	ExternalProgamCoordinationServiceProgramListQueryQueryHandler(){

	}

	CommBasicObjects::CommVoid handleRequest(const std::string& inString);

	std::string handleAnswer(const DomainExternalSystems::CommProgramList& answer);
};

#endif
