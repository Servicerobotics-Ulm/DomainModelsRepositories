#ifndef FLEETMANAGERCOORDINATIONSERVICE_H_
#define FLEETMANAGERCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommTaskEventState.hh>
#include <CommBasicObjects/CommTaskEventStateACE.hh>
#include <CommBasicObjects/CommTaskMessage.hh>
#include <CommBasicObjects/CommTaskMessageACE.hh>


#include "FleetManagerCoordinationServiceFleetEventEventHandlerCore.hh"
#include "FleetManagerCoordinationServiceFleetSendSendHandler.hh"


class FleetManagerCoordinationService {
 	
public:
	FleetManagerCoordinationService ();
	~FleetManagerCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommBasicObjects::CommTaskMessage, CommBasicObjects::CommTaskMessage> *fleetManagerCoordinationServicefleetEventClient;
	FleetManagerCoordinationServiceFleetEventEventHandlerCore *fleetManagerCoordinationServicefleetEventEventHandlerCore;
	SmartACE::SendClient<CommBasicObjects::CommTaskMessage> *fleetManagerCoordinationServicefleetSendClient;
	FleetManagerCoordinationServiceFleetSendSendHandler *fleetManagerCoordinationServicefleetSendSendHandler;
 };
#endif /* FLEETMANAGERCOORDINATIONSERVICE_H_ */
