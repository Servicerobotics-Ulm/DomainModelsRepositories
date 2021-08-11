#ifndef _ROBOTTOROBOTDOCKINGCOORDINATIONSERVICER2RDOCKINGEVENTEVENTHANDLERCORE_HH_
#define _ROBOTTOROBOTDOCKINGCOORDINATIONSERVICER2RDOCKINGEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommRobotinoObjects/CommRobotinoDockingEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoDockingEventParameter.hh"
#include "RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandler.hh"

class RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore : public Smart::IEventHandler<CommRobotinoObjects::CommRobotinoDockingEventResult>
{
public:
	RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore(Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommRobotinoObjects::CommRobotinoDockingEventResult &r) override;
	CommRobotinoObjects::CommRobotinoDockingEventParameter activateEventParam(const std::string& parameterString);
private:
	RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
