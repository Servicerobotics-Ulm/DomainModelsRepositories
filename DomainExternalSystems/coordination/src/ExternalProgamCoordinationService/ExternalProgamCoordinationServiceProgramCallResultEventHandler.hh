#ifndef _EXTERNALPROGAMCOORDINATIONSERVICEPROGRAMCALLRESULTEVENTHANDLER_HH_
#define _EXTERNALPROGAMCOORDINATIONSERVICEPROGRAMCALLRESULTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "DomainExternalSystems/CommExternalProgramResponse.hh"
#include "DomainExternalSystems/CommExternalProgamEventParam.hh"

class ExternalProgamCoordinationServiceProgramCallResultEventHandler
{
public:
	std::string handleEvent(const DomainExternalSystems::CommExternalProgramResponse &r) throw();
	DomainExternalSystems::CommExternalProgamEventParam activateEventParam(const std::string& parameterString);
};

#endif
