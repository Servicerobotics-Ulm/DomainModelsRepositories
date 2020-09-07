#include "ManipulatorCoordinationService.hh"

ManipulatorCoordinationService::ManipulatorCoordinationService (){
		manipulatorCoordinationServicemanipulatoreventClient = NULL;
		manipulatorCoordinationServicemanipulatoreventEventHandlerCore = NULL;
		manipulatorCoordinationServicemanipulatorprogramsQueryHandler = NULL;
		manipulatorCoordinationServicemanipulatorprogramsClient = NULL;
		manipulatorCoordinationServicemanipulatorstateQueryHandler = NULL;
		manipulatorCoordinationServicemanipulatorstateClient = NULL;
}
ManipulatorCoordinationService::~ManipulatorCoordinationService (){
	
}

