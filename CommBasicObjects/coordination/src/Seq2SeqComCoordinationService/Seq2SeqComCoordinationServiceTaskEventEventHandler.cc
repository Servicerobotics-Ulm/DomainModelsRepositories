#include "Seq2SeqComCoordinationServiceTaskEventEventHandler.hh"

std::string Seq2SeqComCoordinationServiceTaskEventEventHandler::handleEvent(const CommBasicObjects::CommTaskMessage &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}

CommBasicObjects::CommTaskMessage Seq2SeqComCoordinationServiceTaskEventEventHandler::activateEventParam(const std::string& parameterString){
	CommBasicObjects::CommTaskMessage param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	return param;
}
