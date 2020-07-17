#ifndef _VACUUMGRIPPERCOORDINATIONSERVICEGRIPPEREVENTEVENTHANDLER_HH_
#define _VACUUMGRIPPERCOORDINATIONSERVICEGRIPPEREVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommManipulatorObjects/CommVacuumGripperEventResult.hh"
#include "CommManipulatorObjects/CommVacuumGripperEventParameter.hh"

class VacuumGripperCoordinationServiceGrippereventEventHandler
{
public:
	std::string handleEvent(const CommManipulatorObjects::CommVacuumGripperEventResult &r) throw();
	CommManipulatorObjects::CommVacuumGripperEventParameter activateEventParam(const std::string& parameterString);
};

#endif
