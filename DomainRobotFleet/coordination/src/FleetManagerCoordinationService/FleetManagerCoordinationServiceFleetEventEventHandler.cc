#include "FleetManagerCoordinationServiceFleetEventEventHandler.hh"

std::string FleetManagerCoordinationServiceFleetEventEventHandler::handleEvent(const CommBasicObjects::CommTaskMessage &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	std::ostringstream ss;
	ss << r.getMsg();
	outString = ss.str();
	return outString;
}

CommBasicObjects::CommTaskMessage FleetManagerCoordinationServiceFleetEventEventHandler::activateEventParam(const std::string& parameterString){
	CommBasicObjects::CommTaskMessage param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	param.setMsg(parameterString);
	return param;
}
