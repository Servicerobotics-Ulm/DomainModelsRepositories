#include "CorridorNavigationClientCoordinationServicePoserequesteventEventHandler.hh"

std::string CorridorNavigationClientCoordinationServicePoserequesteventEventHandler::handleEvent(const CommNavigationObjects::CommCorridorNavigationPoseRequestEventResult &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	if(r.getState() == CommNavigationObjects::NodeRequestAnserType::STATE_UNKNOWN) {
		outString = "(unknown)";
	} else if(r.getState() == CommNavigationObjects::NodeRequestAnserType::ERROR_NONODE){
		outString = "(nonode)";
	} else if(r.getState() == CommNavigationObjects::NodeRequestAnserType::FAIL){
		outString = "(fail)";
	} else if(r.getState() == CommNavigationObjects::NodeRequestAnserType::SUCCESS){
		outString = "(success)";
	} else {
		outString = "(error)";
	}
	return outString;
}

CommNavigationObjects::CommCorridorNavigationPoseRequestEventParameter CorridorNavigationClientCoordinationServicePoserequesteventEventHandler::activateEventParam(const std::string& parameterString){
	CommNavigationObjects::CommCorridorNavigationPoseRequestEventParameter param;
	
	param.setOldState(CommNavigationObjects::NodeRequestAnserType::STATE_UNKNOWN);
	return param;
}
