#ifndef REMOTECONTROLCOORDINATIONSERVICE_H_
#define REMOTECONTROLCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <DomainHMI/CommRemoteControlEvent.hh>
#include <DomainHMI/CommRemoteControlEventACE.hh>


#include "RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore.hh"


class RemoteControlCoordinationService {
 	
public:
	RemoteControlCoordinationService ();
	~RemoteControlCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<DomainHMI::CommRemoteControlEvent, DomainHMI::CommRemoteControlEvent> *remoteControlCoordinationServiceremoteControlEventClient;
	RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore *remoteControlCoordinationServiceremoteControlEventEventHandlerCore;
 };
#endif /* REMOTECONTROLCOORDINATIONSERVICE_H_ */
