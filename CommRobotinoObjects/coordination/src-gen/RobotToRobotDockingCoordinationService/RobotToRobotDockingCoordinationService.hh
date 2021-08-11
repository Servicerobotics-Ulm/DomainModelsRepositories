#ifndef ROBOTTOROBOTDOCKINGCOORDINATIONSERVICE_H_
#define ROBOTTOROBOTDOCKINGCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommRobotinoObjects/CommRobotinoDockingEventParameter.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventParameterACE.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventResult.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventResultACE.hh>
#include <CommRobotinoObjects/RobotinoDockingEventState.hh>
#include <CommRobotinoObjects/RobotinoDockingEventStateACE.hh>


#include "RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore.hh"


class RobotToRobotDockingCoordinationService {
 	
public:
	RobotToRobotDockingCoordinationService ();
	~RobotToRobotDockingCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *robotToRobotDockingCoordinationServicer2rdockingeventClient;
	RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore *robotToRobotDockingCoordinationServicer2rdockingeventEventHandlerCore;
 };
#endif /* ROBOTTOROBOTDOCKINGCOORDINATIONSERVICE_H_ */
