#ifndef MANIPULATORCOORDINATIONSERVICE_H_
#define MANIPULATORCOORDINATIONSERVICE_H_
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


#include "ManipulatorCoordinationServiceIoeventEventHandlerCore.hh"
#include "ManipulatorCoordinationServiceIoqueryQueryHandler.hh"
#include "ManipulatorCoordinationServiceManipulatoreventEventHandlerCore.hh"
#include "ManipulatorCoordinationServiceManipulatorprogramsQueryHandler.hh"
#include "ManipulatorCoordinationServiceManipulatorstateQueryHandler.hh"


class ManipulatorCoordinationService {
 	
public:
	ManipulatorCoordinationService ();
	~ManipulatorCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommBasicObjects::CommDigitalInputEventParameter, CommBasicObjects::CommDigitalInputEventResult> *manipulatorCoordinationServiceioeventClient;
	ManipulatorCoordinationServiceIoeventEventHandlerCore *manipulatorCoordinationServiceioeventEventHandlerCore;
	Smart::IQueryClientPattern<CommBasicObjects::CommIOValues, CommBasicObjects::CommIOValues> *manipulatorCoordinationServiceioqueryClient;
	ManipulatorCoordinationServiceIoqueryQueryHandler *manipulatorCoordinationServiceioqueryQueryHandler;
	Smart::IEventClientPattern<CommManipulatorObjects::CommManipulatorEventParameter, CommManipulatorObjects::CommManipulatorEventResult> *manipulatorCoordinationServicemanipulatoreventClient;
	ManipulatorCoordinationServiceManipulatoreventEventHandlerCore *manipulatorCoordinationServicemanipulatoreventEventHandlerCore;
	Smart::IQueryClientPattern<CommBasicObjects::CommVoid, CommManipulatorObjects::CommMobileManipulatorPrograms> *manipulatorCoordinationServicemanipulatorprogramsClient;
	ManipulatorCoordinationServiceManipulatorprogramsQueryHandler *manipulatorCoordinationServicemanipulatorprogramsQueryHandler;
	Smart::IQueryClientPattern<CommBasicObjects::CommVoid, CommManipulatorObjects::CommMobileManipulatorState> *manipulatorCoordinationServicemanipulatorstateClient;
	ManipulatorCoordinationServiceManipulatorstateQueryHandler *manipulatorCoordinationServicemanipulatorstateQueryHandler;
 };
#endif /* MANIPULATORCOORDINATIONSERVICE_H_ */
