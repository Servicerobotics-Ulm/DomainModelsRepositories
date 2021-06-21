#include "RemoteControlCoordinationServiceRemoteControlEventEventHandler.hh"

std::string RemoteControlCoordinationServiceRemoteControlEventEventHandler::handleEvent(const DomainHMI::CommRemoteControlEvent &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}

DomainHMI::CommRemoteControlEvent RemoteControlCoordinationServiceRemoteControlEventEventHandler::activateEventParam(const std::string& parameterString){
	DomainHMI::CommRemoteControlEvent param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	return param;
}
