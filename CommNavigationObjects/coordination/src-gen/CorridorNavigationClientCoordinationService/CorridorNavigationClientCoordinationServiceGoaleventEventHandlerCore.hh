#ifndef _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICEGOALEVENTEVENTHANDLERCORE_HH_
#define _CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICEGOALEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommNavigationObjects/CommCorridorNavigationGoalEventResult.hh"
#include "CommNavigationObjects/CommCorridorNavigationGoalEventParameter.hh"
#include "CorridorNavigationClientCoordinationServiceGoaleventEventHandler.hh"

class CorridorNavigationClientCoordinationServiceGoaleventEventHandlerCore : public Smart::IEventHandler<CommNavigationObjects::CommCorridorNavigationGoalEventResult>
{
public:
	CorridorNavigationClientCoordinationServiceGoaleventEventHandlerCore(Smart::IEventClientPattern<CommNavigationObjects::CommCorridorNavigationGoalEventParameter, CommNavigationObjects::CommCorridorNavigationGoalEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommNavigationObjects::CommCorridorNavigationGoalEventResult &r) override;
	CommNavigationObjects::CommCorridorNavigationGoalEventParameter activateEventParam(const std::string& parameterString);
private:
	CorridorNavigationClientCoordinationServiceGoaleventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
