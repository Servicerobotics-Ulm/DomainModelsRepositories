#include "CorridorNavigationClientCoordinationServiceGoaleventEventHandler.hh"

#include <iomanip>

std::string CorridorNavigationClientCoordinationServiceGoaleventEventHandler::handleEvent(const CommNavigationObjects::CommCorridorNavigationGoalEventResult &r) throw() {
	std::string outString;

	//convert the event result commObject to string representation outString (to TCL)
	if(r.getState() == CommNavigationObjects:: PathNavigationEventType::GOAL_UNKNOWN) {
		outString = "(unknown)";
	} else if(r.getState() == CommNavigationObjects::PathNavigationEventType::GOAL_REACHED){
		outString = "(reached)";
	} else if(r.getState() == CommNavigationObjects::PathNavigationEventType::GOAL_NOT_REACHED){
		outString = "(notreached)";
	} else if(r.getState() == CommNavigationObjects::PathNavigationEventType::START_TOO_FAR){
		std::stringstream tmp;
		tmp << "(starttoofar " << std::setprecision(0) << r.getNextGoal().getX() << " " << r.getNextGoal().getY() << " )";
		outString = tmp.str();
	} else if(r.getState() == CommNavigationObjects::PathNavigationEventType::NO_PATH_FOUND){
		outString = "(nopath)";
	} else if(r.getState() == CommNavigationObjects::PathNavigationEventType::FATAL_ERROR){
		outString = "(fatal error)";
	} else {
		outString = "(error)";
	}
	return outString;

}

CommNavigationObjects::CommCorridorNavigationGoalEventParameter CorridorNavigationClientCoordinationServiceGoaleventEventHandler::activateEventParam(const std::string& parameterString){
	CommNavigationObjects::CommCorridorNavigationGoalEventParameter param;

	param.setOldState(CommNavigationObjects::PathNavigationEventType::GOAL_UNKNOWN);
	return param;
}
