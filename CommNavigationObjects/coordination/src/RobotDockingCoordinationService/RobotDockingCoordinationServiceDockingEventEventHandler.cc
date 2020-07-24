#include "RobotDockingCoordinationServiceDockingEventEventHandler.hh"

std::string RobotDockingCoordinationServiceDockingEventEventHandler::handleEvent(const CommNavigationObjects::CommDockingEventResult &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}

CommNavigationObjects::CommDockingEventParameter RobotDockingCoordinationServiceDockingEventEventHandler::activateEventParam(const std::string& parameterString){
	CommNavigationObjects::CommDockingEventParameter param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	return param;
}
