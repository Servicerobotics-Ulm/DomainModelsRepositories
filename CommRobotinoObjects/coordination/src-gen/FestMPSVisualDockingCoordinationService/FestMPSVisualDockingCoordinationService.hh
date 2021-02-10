#ifndef FESTMPSVISUALDOCKINGCOORDINATIONSERVICE_H_
#define FESTMPSVISUALDOCKINGCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommRobotinoObjects/CommRobotinoDockingEventParameter.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventParameterACE.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventResult.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventResultACE.hh>
#include <CommRobotinoObjects/RobotinoDockingEventState.hh>
#include <CommRobotinoObjects/RobotinoDockingEventStateACE.hh>


#include "FestMPSVisualDockingCoordinationServiceDockingeventEventHandlerCore.hh"


class FestMPSVisualDockingCoordinationService {
 	
public:
	FestMPSVisualDockingCoordinationService ();
	~FestMPSVisualDockingCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *festMPSVisualDockingCoordinationServicedockingeventClient;
	FestMPSVisualDockingCoordinationServiceDockingeventEventHandlerCore *festMPSVisualDockingCoordinationServicedockingeventEventHandlerCore;
 };
#endif /* FESTMPSVISUALDOCKINGCOORDINATIONSERVICE_H_ */
