#ifndef ROBOTDOCKINGCOORDINATIONSERVICE_H_
#define ROBOTDOCKINGCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommNavigationObjects/CommDockingEventParameter.hh>
#include <CommNavigationObjects/CommDockingEventParameterACE.hh>
#include <CommNavigationObjects/CommDockingEventResult.hh>
#include <CommNavigationObjects/CommDockingEventResultACE.hh>
#include <CommNavigationObjects/CommDockingEventState.hh>
#include <CommNavigationObjects/CommDockingEventStateACE.hh>


#include "RobotDockingCoordinationServiceDockingEventEventHandlerCore.hh"


class RobotDockingCoordinationService {
 	
public:
	RobotDockingCoordinationService ();
	~RobotDockingCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommNavigationObjects::CommDockingEventParameter, CommNavigationObjects::CommDockingEventResult> *robotDockingCoordinationServicedockingEventClient;
	RobotDockingCoordinationServiceDockingEventEventHandlerCore *robotDockingCoordinationServicedockingEventEventHandlerCore;
 };
#endif /* ROBOTDOCKINGCOORDINATIONSERVICE_H_ */
