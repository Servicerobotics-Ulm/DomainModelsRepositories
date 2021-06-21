#ifndef _EXTERNALPROGAMCOORDINATIONSERVICEPROGRAMCALLRESULTEVENTHANDLERCORE_HH_
#define _EXTERNALPROGAMCOORDINATIONSERVICEPROGRAMCALLRESULTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "DomainExternalSystems/CommExternalProgramResponse.hh"
#include "DomainExternalSystems/CommExternalProgamEventParam.hh"
#include "ExternalProgamCoordinationServiceProgramCallResultEventHandler.hh"

class ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore : public Smart::IEventHandler<DomainExternalSystems::CommExternalProgramResponse>
{
public:
	ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore(Smart::IEventClientPattern<DomainExternalSystems::CommExternalProgamEventParam, DomainExternalSystems::CommExternalProgramResponse> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const DomainExternalSystems::CommExternalProgramResponse &r) override;
	DomainExternalSystems::CommExternalProgamEventParam activateEventParam(const std::string& parameterString);
private:
	ExternalProgamCoordinationServiceProgramCallResultEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
