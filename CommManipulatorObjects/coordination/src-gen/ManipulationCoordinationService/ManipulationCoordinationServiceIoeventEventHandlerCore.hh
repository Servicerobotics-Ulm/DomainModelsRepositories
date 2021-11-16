#ifndef _MANIPULATIONCOORDINATIONSERVICEIOEVENTEVENTHANDLERCORE_HH_
#define _MANIPULATIONCOORDINATIONSERVICEIOEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommBasicObjects/CommDigitalInputEventResult.hh"
#include "CommBasicObjects/CommDigitalInputEventParameter.hh"
#include "ManipulationCoordinationServiceIoeventEventHandler.hh"

class ManipulationCoordinationServiceIoeventEventHandlerCore : public Smart::IEventHandler<CommBasicObjects::CommDigitalInputEventResult>
{
public:
	ManipulationCoordinationServiceIoeventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommDigitalInputEventParameter, CommBasicObjects::CommDigitalInputEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommDigitalInputEventResult &r) override;
	CommBasicObjects::CommDigitalInputEventParameter activateEventParam(const std::string& parameterString);
private:
	ManipulationCoordinationServiceIoeventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
