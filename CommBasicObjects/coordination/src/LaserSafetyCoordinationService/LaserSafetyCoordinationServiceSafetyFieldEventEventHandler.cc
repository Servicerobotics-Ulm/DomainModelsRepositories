#include "LaserSafetyCoordinationServiceSafetyFieldEventEventHandler.hh"

std::string LaserSafetyCoordinationServiceSafetyFieldEventEventHandler::handleEvent(const CommBasicObjects::CommLaserSafetyField &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();

	if(r.getProtectiveState() == CommBasicObjects::SafetyFieldState::BLOCKED){
		outString = "(blocked)";
	} else if (r.getProtectiveState() == CommBasicObjects::SafetyFieldState::FREE){
		outString = "(free)";
	}

	return outString;
}

CommBasicObjects::CommLaserSafetyEventParam LaserSafetyCoordinationServiceSafetyFieldEventEventHandler::activateEventParam(const std::string& parameterString){
	CommBasicObjects::CommLaserSafetyEventParam param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	param.setProtectiveState(CommBasicObjects::SafetyFieldState::UNKNOWN);

	return param;
}
