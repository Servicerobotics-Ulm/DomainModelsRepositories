#ifndef MANIPULATIONCOORDINATIONSERVICE_H_
#define MANIPULATIONCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommDigitalInputEventParameter.hh>
#include <CommBasicObjects/CommDigitalInputEventParameterACE.hh>
#include <CommBasicObjects/CommDigitalInputEventResult.hh>
#include <CommBasicObjects/CommDigitalInputEventResultACE.hh>
#include <CommBasicObjects/CommDigitalInputEventState.hh>
#include <CommBasicObjects/CommDigitalInputEventStateACE.hh>
#include <CommBasicObjects/CommIOValues.hh>
#include <CommBasicObjects/CommIOValuesACE.hh>
#include <CommManipulatorObjects/CommManipulationTrajectory.hh>
#include <CommManipulatorObjects/CommManipulationTrajectoryACE.hh>
#include <CommManipulatorObjects/CommManipulatorEventParameter.hh>
#include <CommManipulatorObjects/CommManipulatorEventParameterACE.hh>
#include <CommManipulatorObjects/CommManipulatorEventResult.hh>
#include <CommManipulatorObjects/CommManipulatorEventResultACE.hh>
#include <CommManipulatorObjects/CommManipulatorEventState.hh>
#include <CommManipulatorObjects/CommManipulatorEventStateACE.hh>
#include <CommManipulatorObjects/CommMobileManipulatorPrograms.hh>
#include <CommManipulatorObjects/CommMobileManipulatorProgramsACE.hh>
#include <CommManipulatorObjects/CommMobileManipulatorState.hh>
#include <CommManipulatorObjects/CommMobileManipulatorStateACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>


#include "ManipulationCoordinationServiceIoeventEventHandlerCore.hh"
#include "ManipulationCoordinationServiceIoqueryQueryHandler.hh"
#include "ManipulationCoordinationServiceManipulatoreventEventHandlerCore.hh"
#include "ManipulationCoordinationServiceManipulatorprogramsQueryHandler.hh"
#include "ManipulationCoordinationServiceManipulatorstateQueryHandler.hh"
#include "ManipulationCoordinationServiceTrajectorySendHandler.hh"


class ManipulationCoordinationService {
 	
public:
	ManipulationCoordinationService ();
	~ManipulationCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommBasicObjects::CommDigitalInputEventParameter, CommBasicObjects::CommDigitalInputEventResult> *manipulationCoordinationServiceioeventClient;
	ManipulationCoordinationServiceIoeventEventHandlerCore *manipulationCoordinationServiceioeventEventHandlerCore;
	Smart::IQueryClientPattern<CommBasicObjects::CommIOValues, CommBasicObjects::CommIOValues> *manipulationCoordinationServiceioqueryClient;
	ManipulationCoordinationServiceIoqueryQueryHandler *manipulationCoordinationServiceioqueryQueryHandler;
	Smart::IEventClientPattern<CommManipulatorObjects::CommManipulatorEventParameter, CommManipulatorObjects::CommManipulatorEventResult> *manipulationCoordinationServicemanipulatoreventClient;
	ManipulationCoordinationServiceManipulatoreventEventHandlerCore *manipulationCoordinationServicemanipulatoreventEventHandlerCore;
	Smart::IQueryClientPattern<CommBasicObjects::CommVoid, CommManipulatorObjects::CommMobileManipulatorPrograms> *manipulationCoordinationServicemanipulatorprogramsClient;
	ManipulationCoordinationServiceManipulatorprogramsQueryHandler *manipulationCoordinationServicemanipulatorprogramsQueryHandler;
	Smart::IQueryClientPattern<CommBasicObjects::CommVoid, CommManipulatorObjects::CommMobileManipulatorState> *manipulationCoordinationServicemanipulatorstateClient;
	ManipulationCoordinationServiceManipulatorstateQueryHandler *manipulationCoordinationServicemanipulatorstateQueryHandler;
	SmartACE::SendClient<CommManipulatorObjects::CommManipulationTrajectory> *manipulationCoordinationServicetrajectoryClient;
	ManipulationCoordinationServiceTrajectorySendHandler *manipulationCoordinationServicetrajectorySendHandler;
 };
#endif /* MANIPULATIONCOORDINATIONSERVICE_H_ */
