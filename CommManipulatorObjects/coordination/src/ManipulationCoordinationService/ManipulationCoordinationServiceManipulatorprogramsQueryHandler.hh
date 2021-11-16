#ifndef _MANIPULATIONCOORDINATIONSERVICEMANIPULATORPROGRAMSQUERYHANDLER_HH_
#define _MANIPULATIONCOORDINATIONSERVICEMANIPULATORPROGRAMSQUERYHANDLER_HH_

#include "CommBasicObjects/CommVoid.hh"
#include "CommManipulatorObjects/CommMobileManipulatorPrograms.hh"
#include <string>

class ManipulationCoordinationServiceManipulatorprogramsQueryHandler
{
public:

	ManipulationCoordinationServiceManipulatorprogramsQueryHandler(){

	}

	CommBasicObjects::CommVoid handleRequest(const std::string& inString);

	std::string handleAnswer(const CommManipulatorObjects::CommMobileManipulatorPrograms& answer);
};

#endif
