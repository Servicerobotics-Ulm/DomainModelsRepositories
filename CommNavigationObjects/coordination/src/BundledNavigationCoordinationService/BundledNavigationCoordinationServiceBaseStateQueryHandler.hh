#ifndef _BUNDLEDNAVIGATIONCOORDINATIONSERVICEBASESTATEQUERYHANDLER_HH_
#define _BUNDLEDNAVIGATIONCOORDINATIONSERVICEBASESTATEQUERYHANDLER_HH_

#include "CommBasicObjects/CommVoid.hh"
#include "CommBasicObjects/CommBaseState.hh"
#include <string>

class BundledNavigationCoordinationServiceBaseStateQueryHandler
{
public:

	BundledNavigationCoordinationServiceBaseStateQueryHandler(){

	}

	CommBasicObjects::CommVoid handleRequest(const std::string& inString);

	std::string handleAnswer(const CommBasicObjects::CommBaseState& answer);
};

#endif
