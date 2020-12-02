#ifndef _FLEETMANAGERCOORDINATIONSERVICEFLEETEVENTEVENTHANDLERCORE_HH_
#define _FLEETMANAGERCOORDINATIONSERVICEFLEETEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommBasicObjects/CommTaskMessage.hh"
#include "CommBasicObjects/CommTaskMessage.hh"
#include "FleetManagerCoordinationServiceFleetEventEventHandler.hh"

class FleetManagerCoordinationServiceFleetEventEventHandlerCore : public Smart::IEventHandler<CommBasicObjects::CommTaskMessage>
{
public:
	FleetManagerCoordinationServiceFleetEventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommTaskMessage, CommBasicObjects::CommTaskMessage> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommTaskMessage &r) override;
	CommBasicObjects::CommTaskMessage activateEventParam(const std::string& parameterString);
private:
	FleetManagerCoordinationServiceFleetEventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
