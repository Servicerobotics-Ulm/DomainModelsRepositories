#ifndef _CONVEYERBELTCOORDINATIONSERVICELOADEVENTEVENTHANDLER_HH_
#define _CONVEYERBELTCOORDINATIONSERVICELOADEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommRobotinoObjects/CommRobotinoConveyerBeltEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoConveyerBeltEventParameter.hh"

class ConveyerBeltCoordinationServiceLoadeventEventHandler
{
public:
	std::string handleEvent(const CommRobotinoObjects::CommRobotinoConveyerBeltEventResult &r) throw();
	CommRobotinoObjects::CommRobotinoConveyerBeltEventParameter activateEventParam(const std::string& parameterString);
};

#endif
