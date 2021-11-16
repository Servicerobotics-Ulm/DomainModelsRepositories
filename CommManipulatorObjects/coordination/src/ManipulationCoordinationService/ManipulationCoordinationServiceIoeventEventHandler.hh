#ifndef _MANIPULATIONCOORDINATIONSERVICEIOEVENTEVENTHANDLER_HH_
#define _MANIPULATIONCOORDINATIONSERVICEIOEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommBasicObjects/CommDigitalInputEventResult.hh"
#include "CommBasicObjects/CommDigitalInputEventParameter.hh"

class ManipulationCoordinationServiceIoeventEventHandler
{
public:
	std::string handleEvent(const CommBasicObjects::CommDigitalInputEventResult &r) throw();
	CommBasicObjects::CommDigitalInputEventParameter activateEventParam(const std::string& parameterString);
};

#endif
