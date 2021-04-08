#include "ManipulatorCoordinationService.hh"

ManipulatorCoordinationService::ManipulatorCoordinationService (){
		manipulatorCoordinationServiceioeventClient = NULL;
		manipulatorCoordinationServiceioeventEventHandlerCore = NULL;
		manipulatorCoordinationServiceioqueryQueryHandler = NULL;
		manipulatorCoordinationServiceioqueryClient = NULL;
		manipulatorCoordinationServicemanipulatoreventClient = NULL;
		manipulatorCoordinationServicemanipulatoreventEventHandlerCore = NULL;
		manipulatorCoordinationServicemanipulatorprogramsQueryHandler = NULL;
		manipulatorCoordinationServicemanipulatorprogramsClient = NULL;
		manipulatorCoordinationServicemanipulatorstateQueryHandler = NULL;
		manipulatorCoordinationServicemanipulatorstateClient = NULL;
		manipulatorCoordinationServicetrajectorySendHandler = NULL;
		manipulatorCoordinationServicetrajectoryClient = NULL;
}
ManipulatorCoordinationService::~ManipulatorCoordinationService (){
	
}

