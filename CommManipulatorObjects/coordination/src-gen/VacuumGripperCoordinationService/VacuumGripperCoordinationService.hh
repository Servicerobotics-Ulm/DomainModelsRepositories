#ifndef VACUUMGRIPPERCOORDINATIONSERVICE_H_
#define VACUUMGRIPPERCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommManipulatorObjects/CommVacuumGripperEventParameter.hh>
#include <CommManipulatorObjects/CommVacuumGripperEventParameterACE.hh>
#include <CommManipulatorObjects/CommVacuumGripperEventResult.hh>
#include <CommManipulatorObjects/CommVacuumGripperEventResultACE.hh>
#include <CommManipulatorObjects/CommVacuumGripperEventState.hh>
#include <CommManipulatorObjects/CommVacuumGripperEventStateACE.hh>


#include "VacuumGripperCoordinationServiceGrippereventEventHandlerCore.hh"


class VacuumGripperCoordinationService {
 	
public:
	VacuumGripperCoordinationService ();
	~VacuumGripperCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommManipulatorObjects::CommVacuumGripperEventParameter, CommManipulatorObjects::CommVacuumGripperEventResult> *vacuumGripperCoordinationServicegrippereventClient;
	VacuumGripperCoordinationServiceGrippereventEventHandlerCore *vacuumGripperCoordinationServicegrippereventEventHandlerCore;
 };
#endif /* VACUUMGRIPPERCOORDINATIONSERVICE_H_ */
