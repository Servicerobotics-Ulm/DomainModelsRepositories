#ifndef _REMOTECONTROLCOORDINATIONSERVICEREMOTECONTROLEVENTEVENTHANDLER_HH_
#define _REMOTECONTROLCOORDINATIONSERVICEREMOTECONTROLEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "DomainHMI/CommRemoteControlEvent.hh"
#include "DomainHMI/CommRemoteControlEvent.hh"

class RemoteControlCoordinationServiceRemoteControlEventEventHandler
{
public:
	std::string handleEvent(const DomainHMI::CommRemoteControlEvent &r) throw();
	DomainHMI::CommRemoteControlEvent activateEventParam(const std::string& parameterString);
};

#endif
