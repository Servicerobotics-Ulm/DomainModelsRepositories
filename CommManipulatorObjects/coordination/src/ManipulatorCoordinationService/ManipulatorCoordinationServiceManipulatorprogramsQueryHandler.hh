#ifndef _MANIPULATORCOORDINATIONSERVICEMANIPULATORPROGRAMSQUERYHANDLER_HH_
#define _MANIPULATORCOORDINATIONSERVICEMANIPULATORPROGRAMSQUERYHANDLER_HH_

#include "CommBasicObjects/CommVoid.hh"
#include "CommManipulatorObjects/CommMobileManipulatorPrograms.hh"
#include <string>

class ManipulatorCoordinationServiceManipulatorprogramsQueryHandler
{
public:

	ManipulatorCoordinationServiceManipulatorprogramsQueryHandler(){

	}

	CommBasicObjects::CommVoid handleRequest(const std::string& inString);

	std::string handleAnswer(const CommManipulatorObjects::CommMobileManipulatorPrograms& answer);
};

#endif
