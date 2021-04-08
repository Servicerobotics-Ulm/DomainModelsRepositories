#include "ManipulationPlannerCoordinationServicePlannereventEventHandler.hh"

std::string ManipulationPlannerCoordinationServicePlannereventEventHandler::handleEvent(const CommManipulationPlannerObjects::CommManipulationPlannerEventResult &r) throw() {

	std::string outString;

	//convert the event result commObject to string representation outString (to TCL)
	if (r.getEvent() == CommManipulationPlannerObjects::ManipulationPlannerEvent::PATH_FOUND) {
		outString = "(PATH FOUND)";
	} else if (r.getEvent() == CommManipulationPlannerObjects::ManipulationPlannerEvent::PLANNING_PATH) {
		outString = "(PLANNING PATH)";
	} else if (r.getEvent() == CommManipulationPlannerObjects::ManipulationPlannerEvent::NO_IK_SOLUTION_FOUND) {
		outString = "(NO IK SOLUTION FOUND)";
	} else if (r.getEvent() == CommManipulationPlannerObjects::ManipulationPlannerEvent::NO_PATH_FOUND) {
		outString = "(NO PATH FOUND)";
	} else {
		outString = "(ERROR)";
	}

	return outString;
}

CommManipulationPlannerObjects::CommManipulationPlannerEventParameter ManipulationPlannerCoordinationServicePlannereventEventHandler::activateEventParam(const std::string& parameterString){
	CommManipulationPlannerObjects::CommManipulationPlannerEventParameter param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	//param.setEvent(CommManipulatorObjects::ManipulatorEvent::UNKNOWN);
	param.setEvent(CommManipulationPlannerObjects::ManipulationPlannerEvent::UNKNOWN);
	return param;
}
