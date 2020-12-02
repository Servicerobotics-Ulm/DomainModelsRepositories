#include "RobotDockingCoordinationServiceDockingEventEventHandler.hh"

std::string RobotDockingCoordinationServiceDockingEventEventHandler::handleEvent(const CommNavigationObjects::CommDockingEventResult &r) throw() {
	std::string outString;
	
	if(r.getState() == CommNavigationObjects::DockingEventType::DOCKING_UNKNOWN){
		outString = "(unknown)";
	} else if (r.getState() == CommNavigationObjects::DockingEventType::DOCKING_NOT_DONE){
		outString = "(docking not done)";
	} else if (r.getState() == CommNavigationObjects::DockingEventType::DOCKING_DONE){
		outString = "(docking done)";
	} else if (r.getState() == CommNavigationObjects::DockingEventType::DOCKING_ERROR){
		outString = "(docking error)";
	} else if (r.getState() == CommNavigationObjects::DockingEventType::UN_DOCKING_DONE){
		outString = "(undocking done)";
	} else if (r.getState() == CommNavigationObjects::DockingEventType::UN_DOCKING_NOT_DONE){
		outString = "(undocking not done)";
	} else if (r.getState() == CommNavigationObjects::DockingEventType::UN_DOCKING_ERROR){
		outString = "(undocking error)";
	} else {
		outString = "(error)";
	}

	return outString;
}

CommNavigationObjects::CommDockingEventParameter RobotDockingCoordinationServiceDockingEventEventHandler::activateEventParam(const std::string& parameterString){
	CommNavigationObjects::CommDockingEventParameter param;
	
	param.setOldState(CommNavigationObjects::DockingEventType::DOCKING_UNKNOWN);
	return param;
}
