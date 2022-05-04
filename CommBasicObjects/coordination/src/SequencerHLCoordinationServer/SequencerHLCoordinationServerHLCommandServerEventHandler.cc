#include "SequencerHLCoordinationServerHLCommandServerEventHandler.hh"

std::string SequencerHLCoordinationServerHLCommandServerEventHandler::handleEvent(const CommBasicObjects::CommSkillMsg &r) throw() {
	std::string outString;
	
	//convert the event result commObject to string representation outString (to TCL)
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	std::ostringstream ss;
	ss << r.getMsg();
	outString = ss.str();
	return outString;
}

CommBasicObjects::CommSkillMsg SequencerHLCoordinationServerHLCommandServerEventHandler::activateEventParam(const std::string& parameterString){
	CommBasicObjects::CommSkillMsg param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	param.setMsg(parameterString);
	return param;
}
