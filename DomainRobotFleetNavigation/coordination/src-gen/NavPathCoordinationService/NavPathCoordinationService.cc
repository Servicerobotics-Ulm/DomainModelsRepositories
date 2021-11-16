#include "NavPathCoordinationService.hh"

NavPathCoordinationService::NavPathCoordinationService (){
		navPathCoordinationServicequeryShortestPathQueryHandler = NULL;
		navPathCoordinationServicequeryShortestPathClient = NULL;
		navPathCoordinationServicesendPathSendHandler = NULL;
		navPathCoordinationServicesendPathClient = NULL;
}
NavPathCoordinationService::~NavPathCoordinationService (){
	
}

