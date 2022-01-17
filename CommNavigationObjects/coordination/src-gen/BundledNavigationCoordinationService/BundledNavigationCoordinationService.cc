#include "BundledNavigationCoordinationService.hh"

BundledNavigationCoordinationService::BundledNavigationCoordinationService (){
		bundledNavigationCoordinationServicebaseStateQueryHandler = NULL;
		bundledNavigationCoordinationServicebaseStateClient = NULL;
		bundledNavigationCoordinationServicegoalEventClient = NULL;
		bundledNavigationCoordinationServicegoalEventEventHandlerCore = NULL;
}
BundledNavigationCoordinationService::~BundledNavigationCoordinationService (){
	
}

