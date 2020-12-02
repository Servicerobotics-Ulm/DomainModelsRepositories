#include "FestMPSVisualDockingCoordinationServiceDockingeventEventHandler.hh"

std::string FestMPSVisualDockingCoordinationServiceDockingeventEventHandler::handleEvent(const CommRobotinoObjects::CommRobotinoDockingEventResult &r) throw() {
	std::string outString;
	
	if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::DOCKING_UNKNOWN){
		outString = "(unknown)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::IR_DOCKING_DONE){
		outString = "(ir docking done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::IR_DOCKING_NOT_DONE){
		outString = "(ir docking not done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::LASER_DOCKING_DONE){
		outString = "(laser docking done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::LASER_DOCKING_NOT_DONE){
		outString = "(laser docking not done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::LASER_DOCKING_ERROR){
		outString = "(laser docking error)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::IR_DOCKING_ERROR){
		outString = "(ir docking error)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::UN_DOCKING_NOT_DONE){
		outString = "(undocking not done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::UN_DOCKING_DONE){
		outString = "(undocking done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoDockingEventType::UN_DOCKING_ERROR){
		outString = "(undocking error)";
	} else {
		outString = "(error)";
	}

	return outString;
}

CommRobotinoObjects::CommRobotinoDockingEventParameter FestMPSVisualDockingCoordinationServiceDockingeventEventHandler::activateEventParam(const std::string& parameterString){
	CommRobotinoObjects::CommRobotinoDockingEventParameter param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	param.setOldState(CommRobotinoObjects::RobotinoDockingEventType::DOCKING_UNKNOWN);
	return param;
}
