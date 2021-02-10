#include "PurePursuitNavigationCoordinationServiceGoalEventEventHandler.hh"

std::string PurePursuitNavigationCoordinationServiceGoalEventEventHandler::handleEvent(const CommNavigationObjects::CommCdlGoalEventResult &r) throw() {
	std::string outString;
	
	if(r.getState() == CommNavigationObjects::CdlGoalEventType::CDL_GOAL_UNKNOWN) {
		outString = "(unknown)";
	} else if(r.getState() == CommNavigationObjects::CdlGoalEventType::CDL_GOAL_REACHED){
		outString = "(reached)";
	} else if(r.getState() == CommNavigationObjects::CdlGoalEventType::CDL_GOAL_NOT_REACHED){
		outString = "(notreached)";
	} else {
		outString = "(error)";
	}
	return outString;
}


CommNavigationObjects::CommCdlGoalEventParameter PurePursuitNavigationCoordinationServiceGoalEventEventHandler::activateEventParam(const std::string& parameterString){
	CommNavigationObjects::CommCdlGoalEventParameter param;
	
	param.setOldState(CommNavigationObjects::CdlGoalEventType::CDL_GOAL_UNKNOWN);
	return param;
}
