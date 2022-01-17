#include "BundledNavigationCoordinationServiceGoalEventEventHandler.hh"

std::string BundledNavigationCoordinationServiceGoalEventEventHandler::handleEvent(const CommNavigationObjects::CommBundledNavigationEventResult &r) throw() {
	std::string outString;
	//convert the event result commObject to string representation outString (to TCL)
	if(r.getGoalState() == CommNavigationObjects::BundledNavigationGoalState::GOAL_UNDEFINED) {
		outString = "(undefined)";
	} else if(r.getGoalState() == CommNavigationObjects::BundledNavigationGoalState::GOAL_NOT_REACHABLE){
		outString = "(goal-not-reached)";
	} else if(r.getGoalState() == CommNavigationObjects::BundledNavigationGoalState::GOAL_REACHED){
		outString = "(goal-reached)";
	} else if(r.getGoalState() == CommNavigationObjects::BundledNavigationGoalState::GOAL_CANCELED){
		outString = "(goal-canceled)";
	} else {
		outString = "(error)";
	}
	return outString;
}

CommNavigationObjects::CommBundledNavigationEventParameter BundledNavigationCoordinationServiceGoalEventEventHandler::activateEventParam(const std::string& parameterString){
	CommNavigationObjects::CommBundledNavigationEventParameter param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	param.setLocationName("");
	param.setPreviousState(CommNavigationObjects::BundledNavigationGoalState::GOAL_UNDEFINED);
	return param;
}
