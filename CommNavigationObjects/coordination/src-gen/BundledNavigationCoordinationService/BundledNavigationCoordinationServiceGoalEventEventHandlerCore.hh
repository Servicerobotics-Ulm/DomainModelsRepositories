#ifndef _BUNDLEDNAVIGATIONCOORDINATIONSERVICEGOALEVENTEVENTHANDLERCORE_HH_
#define _BUNDLEDNAVIGATIONCOORDINATIONSERVICEGOALEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommNavigationObjects/CommBundledNavigationEventResult.hh"
#include "CommNavigationObjects/CommBundledNavigationEventParameter.hh"
#include "BundledNavigationCoordinationServiceGoalEventEventHandler.hh"

class BundledNavigationCoordinationServiceGoalEventEventHandlerCore : public Smart::IEventHandler<CommNavigationObjects::CommBundledNavigationEventResult>
{
public:
	BundledNavigationCoordinationServiceGoalEventEventHandlerCore(Smart::IEventClientPattern<CommNavigationObjects::CommBundledNavigationEventParameter, CommNavigationObjects::CommBundledNavigationEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommNavigationObjects::CommBundledNavigationEventResult &r) override;
	CommNavigationObjects::CommBundledNavigationEventParameter activateEventParam(const std::string& parameterString);
private:
	BundledNavigationCoordinationServiceGoalEventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
