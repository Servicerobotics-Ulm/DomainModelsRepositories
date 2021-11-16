#include "ManipulationCoordinationService.hh"

ManipulationCoordinationService::ManipulationCoordinationService (){
		manipulationCoordinationServiceioeventClient = NULL;
		manipulationCoordinationServiceioeventEventHandlerCore = NULL;
		manipulationCoordinationServiceioqueryQueryHandler = NULL;
		manipulationCoordinationServiceioqueryClient = NULL;
		manipulationCoordinationServicemanipulatoreventClient = NULL;
		manipulationCoordinationServicemanipulatoreventEventHandlerCore = NULL;
		manipulationCoordinationServicemanipulatorprogramsQueryHandler = NULL;
		manipulationCoordinationServicemanipulatorprogramsClient = NULL;
		manipulationCoordinationServicemanipulatorstateQueryHandler = NULL;
		manipulationCoordinationServicemanipulatorstateClient = NULL;
		manipulationCoordinationServicetrajectorySendHandler = NULL;
		manipulationCoordinationServicetrajectoryClient = NULL;
}
ManipulationCoordinationService::~ManipulationCoordinationService (){
	
}

