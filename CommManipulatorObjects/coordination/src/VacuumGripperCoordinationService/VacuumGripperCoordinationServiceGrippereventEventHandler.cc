#include "VacuumGripperCoordinationServiceGrippereventEventHandler.hh"

std::string VacuumGripperCoordinationServiceGrippereventEventHandler::handleEvent(const CommManipulatorObjects::CommVacuumGripperEventResult &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}

CommManipulatorObjects::CommVacuumGripperEventParameter VacuumGripperCoordinationServiceGrippereventEventHandler::activateEventParam(const std::string& parameterString){
	CommManipulatorObjects::CommVacuumGripperEventParameter param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	return param;
}
