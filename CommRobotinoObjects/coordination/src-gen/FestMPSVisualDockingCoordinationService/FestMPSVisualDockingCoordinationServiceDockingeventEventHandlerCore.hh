#ifndef _FESTMPSVISUALDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLERCORE_HH_
#define _FESTMPSVISUALDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommRobotinoObjects/CommRobotinoDockingEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoDockingEventParameter.hh"
#include "FestMPSVisualDockingCoordinationServiceDockingeventEventHandler.hh"

class FestMPSVisualDockingCoordinationServiceDockingeventEventHandlerCore : public Smart::IEventHandler<CommRobotinoObjects::CommRobotinoDockingEventResult>
{
public:
	FestMPSVisualDockingCoordinationServiceDockingeventEventHandlerCore(Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommRobotinoObjects::CommRobotinoDockingEventResult &r) override;
	CommRobotinoObjects::CommRobotinoDockingEventParameter activateEventParam(const std::string& parameterString);
private:
	FestMPSVisualDockingCoordinationServiceDockingeventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
