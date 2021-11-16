#ifndef _MANIPULATIONCOORDINATIONSERVICEMANIPULATOREVENTEVENTHANDLERCORE_HH_
#define _MANIPULATIONCOORDINATIONSERVICEMANIPULATOREVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommManipulatorObjects/CommManipulatorEventResult.hh"
#include "CommManipulatorObjects/CommManipulatorEventParameter.hh"
#include "ManipulationCoordinationServiceManipulatoreventEventHandler.hh"

class ManipulationCoordinationServiceManipulatoreventEventHandlerCore : public Smart::IEventHandler<CommManipulatorObjects::CommManipulatorEventResult>
{
public:
	ManipulationCoordinationServiceManipulatoreventEventHandlerCore(Smart::IEventClientPattern<CommManipulatorObjects::CommManipulatorEventParameter, CommManipulatorObjects::CommManipulatorEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommManipulatorObjects::CommManipulatorEventResult &r) override;
	CommManipulatorObjects::CommManipulatorEventParameter activateEventParam(const std::string& parameterString);
private:
	ManipulationCoordinationServiceManipulatoreventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
