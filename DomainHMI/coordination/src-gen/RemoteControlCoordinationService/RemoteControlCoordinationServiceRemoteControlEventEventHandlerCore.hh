#ifndef _REMOTECONTROLCOORDINATIONSERVICEREMOTECONTROLEVENTEVENTHANDLERCORE_HH_
#define _REMOTECONTROLCOORDINATIONSERVICEREMOTECONTROLEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "DomainHMI/CommRemoteControlEvent.hh"
#include "DomainHMI/CommRemoteControlEvent.hh"
#include "RemoteControlCoordinationServiceRemoteControlEventEventHandler.hh"

class RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore : public Smart::IEventHandler<DomainHMI::CommRemoteControlEvent>
{
public:
	RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore(Smart::IEventClientPattern<DomainHMI::CommRemoteControlEvent, DomainHMI::CommRemoteControlEvent> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const DomainHMI::CommRemoteControlEvent &r) override;
	DomainHMI::CommRemoteControlEvent activateEventParam(const std::string& parameterString);
private:
	RemoteControlCoordinationServiceRemoteControlEventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
