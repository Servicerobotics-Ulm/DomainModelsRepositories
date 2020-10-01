#include "ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandler.hh"

std::string ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandler::handleEvent(const CommObjectRecognitionObjects::CommObjectRecognitionEventResult &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}

CommBasicObjects::CommVoid ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandler::activateEventParam(const std::string& parameterString){
	CommBasicObjects::CommVoid param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	return param;
}
