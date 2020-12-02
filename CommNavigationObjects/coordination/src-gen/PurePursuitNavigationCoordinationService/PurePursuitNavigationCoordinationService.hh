#ifndef PUREPURSUITNAVIGATIONCOORDINATIONSERVICE_H_
#define PUREPURSUITNAVIGATIONCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommNavigationObjects/CdlGoalEventState.hh>
#include <CommNavigationObjects/CdlGoalEventStateACE.hh>
#include <CommNavigationObjects/CommCdlGoalEventParameter.hh>
#include <CommNavigationObjects/CommCdlGoalEventParameterACE.hh>
#include <CommNavigationObjects/CommCdlGoalEventResult.hh>
#include <CommNavigationObjects/CommCdlGoalEventResultACE.hh>


#include "PurePursuitNavigationCoordinationServiceGoalEventEventHandlerCore.hh"


class PurePursuitNavigationCoordinationService {
 	
public:
	PurePursuitNavigationCoordinationService ();
	~PurePursuitNavigationCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommNavigationObjects::CommCdlGoalEventParameter, CommNavigationObjects::CommCdlGoalEventResult> *purePursuitNavigationCoordinationServicegoalEventClient;
	PurePursuitNavigationCoordinationServiceGoalEventEventHandlerCore *purePursuitNavigationCoordinationServicegoalEventEventHandlerCore;
 };
#endif /* PUREPURSUITNAVIGATIONCOORDINATIONSERVICE_H_ */
