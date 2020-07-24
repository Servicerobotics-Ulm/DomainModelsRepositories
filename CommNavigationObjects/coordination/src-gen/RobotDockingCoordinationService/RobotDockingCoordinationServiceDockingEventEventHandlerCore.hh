#ifndef _ROBOTDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLERCORE_HH_
#define _ROBOTDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommNavigationObjects/CommDockingEventResult.hh"
#include "CommNavigationObjects/CommDockingEventParameter.hh"
#include "RobotDockingCoordinationServiceDockingEventEventHandler.hh"

class RobotDockingCoordinationServiceDockingEventEventHandlerCore : public Smart::IEventHandler<CommNavigationObjects::CommDockingEventResult>
{
public:
	RobotDockingCoordinationServiceDockingEventEventHandlerCore(Smart::IEventClientPattern<CommNavigationObjects::CommDockingEventParameter, CommNavigationObjects::CommDockingEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommNavigationObjects::CommDockingEventResult &r) override;
	CommNavigationObjects::CommDockingEventParameter activateEventParam(const std::string& parameterString);
private:
	RobotDockingCoordinationServiceDockingEventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
