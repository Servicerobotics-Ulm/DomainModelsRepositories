#ifndef _PUREPURSUITNAVIGATIONCOORDINATIONSERVICEGOALEVENTEVENTHANDLERCORE_HH_
#define _PUREPURSUITNAVIGATIONCOORDINATIONSERVICEGOALEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommNavigationObjects/CommCdlGoalEventResult.hh"
#include "CommNavigationObjects/CommCdlGoalEventParameter.hh"
#include "PurePursuitNavigationCoordinationServiceGoalEventEventHandler.hh"

class PurePursuitNavigationCoordinationServiceGoalEventEventHandlerCore : public Smart::IEventHandler<CommNavigationObjects::CommCdlGoalEventResult>
{
public:
	PurePursuitNavigationCoordinationServiceGoalEventEventHandlerCore(Smart::IEventClientPattern<CommNavigationObjects::CommCdlGoalEventParameter, CommNavigationObjects::CommCdlGoalEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommNavigationObjects::CommCdlGoalEventResult &r) override;
	CommNavigationObjects::CommCdlGoalEventParameter activateEventParam(const std::string& parameterString);
private:
	PurePursuitNavigationCoordinationServiceGoalEventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
