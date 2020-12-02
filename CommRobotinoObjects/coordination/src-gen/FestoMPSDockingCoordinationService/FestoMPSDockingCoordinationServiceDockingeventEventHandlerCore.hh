#ifndef _FESTOMPSDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLERCORE_HH_
#define _FESTOMPSDOCKINGCOORDINATIONSERVICEDOCKINGEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommRobotinoObjects/CommRobotinoDockingEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoDockingEventParameter.hh"
#include "FestoMPSDockingCoordinationServiceDockingeventEventHandler.hh"

class FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore : public Smart::IEventHandler<CommRobotinoObjects::CommRobotinoDockingEventResult>
{
public:
	FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore(Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommRobotinoObjects::CommRobotinoDockingEventResult &r) override;
	CommRobotinoObjects::CommRobotinoDockingEventParameter activateEventParam(const std::string& parameterString);
private:
	FestoMPSDockingCoordinationServiceDockingeventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
