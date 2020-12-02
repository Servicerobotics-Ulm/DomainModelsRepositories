#ifndef _MANIPULATORCOORDINATIONSERVICEIOEVENTEVENTHANDLERCORE_HH_
#define _MANIPULATORCOORDINATIONSERVICEIOEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommBasicObjects/CommDigitalInputEventResult.hh"
#include "CommBasicObjects/CommDigitalInputEventParameter.hh"
#include "ManipulatorCoordinationServiceIoeventEventHandler.hh"

class ManipulatorCoordinationServiceIoeventEventHandlerCore : public Smart::IEventHandler<CommBasicObjects::CommDigitalInputEventResult>
{
public:
	ManipulatorCoordinationServiceIoeventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommDigitalInputEventParameter, CommBasicObjects::CommDigitalInputEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommDigitalInputEventResult &r) override;
	CommBasicObjects::CommDigitalInputEventParameter activateEventParam(const std::string& parameterString);
private:
	ManipulatorCoordinationServiceIoeventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
