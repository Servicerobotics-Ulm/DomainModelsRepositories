#ifndef FESTOMPSDOCKINGCOORDINATIONSERVICE_H_
#define FESTOMPSDOCKINGCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommRobotinoObjects/CommRobotinoDockingEventParameter.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventParameterACE.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventResult.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventResultACE.hh>
#include <CommRobotinoObjects/RobotinoDockingEventState.hh>
#include <CommRobotinoObjects/RobotinoDockingEventStateACE.hh>


#include "FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore.hh"


class FestoMPSDockingCoordinationService {
 	
public:
	FestoMPSDockingCoordinationService ();
	~FestoMPSDockingCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *festoMPSDockingCoordinationServicedockingeventClient;
	FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore *festoMPSDockingCoordinationServicedockingeventEventHandlerCore;
 };
#endif /* FESTOMPSDOCKINGCOORDINATIONSERVICE_H_ */
