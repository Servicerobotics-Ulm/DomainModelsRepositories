#ifndef _FESTOMPSVISUALDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLERCORE_HH_
#define _FESTOMPSVISUALDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommRobotinoObjects/CommRobotinoDockingEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoDockingEventParameter.hh"
#include "FestoMPSVisualDockingCoordinationServiceDockingeventEventHandler.hh"

class FestoMPSVisualDockingCoordinationServiceDockingeventEventHandlerCore : public Smart::IEventHandler<CommRobotinoObjects::CommRobotinoDockingEventResult>
{
public:
	FestoMPSVisualDockingCoordinationServiceDockingeventEventHandlerCore(Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommRobotinoObjects::CommRobotinoDockingEventResult &r) override;
	CommRobotinoObjects::CommRobotinoDockingEventParameter activateEventParam(const std::string& parameterString);
private:
	FestoMPSVisualDockingCoordinationServiceDockingeventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
