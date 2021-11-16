#ifndef _MANIPULATIONCOORDINATIONSERVICEMANIPULATORSTATEQUERYHANDLER_HH_
#define _MANIPULATIONCOORDINATIONSERVICEMANIPULATORSTATEQUERYHANDLER_HH_

#include "CommBasicObjects/CommVoid.hh"
#include "CommManipulatorObjects/CommMobileManipulatorState.hh"
#include <string>

class ManipulationCoordinationServiceManipulatorstateQueryHandler
{
public:

	ManipulationCoordinationServiceManipulatorstateQueryHandler(){

	}

	CommBasicObjects::CommVoid handleRequest(const std::string& inString);

	std::string handleAnswer(const CommManipulatorObjects::CommMobileManipulatorState& answer);
};

#endif
