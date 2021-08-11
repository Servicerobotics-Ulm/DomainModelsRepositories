#ifndef FESTOMPSVISUALDOCKINGCOORDINATIONSERVICE_H_
#define FESTOMPSVISUALDOCKINGCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommTrackingObjects/CommDetectedMarkerEventParameter.hh>
#include <CommTrackingObjects/CommDetectedMarkerEventParameterACE.hh>
#include <CommTrackingObjects/CommDetectedMarkerEventResult.hh>
#include <CommTrackingObjects/CommDetectedMarkerEventResultACE.hh>
#include <CommTrackingObjects/CommDetectedMarkerEventState.hh>
#include <CommTrackingObjects/CommDetectedMarkerEventStateACE.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventParameter.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventParameterACE.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventResult.hh>
#include <CommRobotinoObjects/CommRobotinoDockingEventResultACE.hh>
#include <CommRobotinoObjects/RobotinoDockingEventState.hh>
#include <CommRobotinoObjects/RobotinoDockingEventStateACE.hh>


#include "FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandlerCore.hh"
#include "FestoMPSVisualDockingCoordinationServiceDockingeventEventHandlerCore.hh"


class FestoMPSVisualDockingCoordinationService {
 	
public:
	FestoMPSVisualDockingCoordinationService ();
	~FestoMPSVisualDockingCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommTrackingObjects::CommDetectedMarkerEventParameter, CommTrackingObjects::CommDetectedMarkerEventResult> *festoMPSVisualDockingCoordinationServicedetectioneventClient;
	FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandlerCore *festoMPSVisualDockingCoordinationServicedetectioneventEventHandlerCore;
	Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *festoMPSVisualDockingCoordinationServicedockingeventClient;
	FestoMPSVisualDockingCoordinationServiceDockingeventEventHandlerCore *festoMPSVisualDockingCoordinationServicedockingeventEventHandlerCore;
 };
#endif /* FESTOMPSVISUALDOCKINGCOORDINATIONSERVICE_H_ */
