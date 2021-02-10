#include "ConveyerBeltCoordinationServiceLoadeventEventHandler.hh"

std::string ConveyerBeltCoordinationServiceLoadeventEventHandler::handleEvent(const CommRobotinoObjects::CommRobotinoConveyerBeltEventResult &r) throw() {
	std::string outString;

	if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_UNKNOWN){
		outString = "(unknown)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_LOAD_DONE ) {
		outString = "(load done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_LOAD_NOT_DONE ) {
		outString = "(load not done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_UNLOAD_DONE ) {
		outString = "(unload done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_UNLOAD_NOT_DONE ) {
		outString ="(unload not done)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_UNLOAD_ERROR_NO_BOX ) {
		outString ="(unload error no box)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_UNLOAD_ERROR_BOX_STILL_PRESENT ) {
		outString ="(unload error box still present)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_UNLOAD_ERROR_NO_RESPONSE_FROM_STATION ) {
		outString ="(unload error no response from station)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_LOAD_ERROR_NO_BOX_LOADED ) {
		outString ="(load error no box)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_LOAD_ERROR_BOX_ADREADY_PRSESENT ) {
		outString ="(load error box already present)";
	} else if(r.getState() == CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_LOAD_ERROR_NO_RESPONSE_FROM_STATION ) {
		outString ="(load error no response from station)";
	} else {
		outString ="(error)";
	}

	return outString;
}

CommRobotinoObjects::CommRobotinoConveyerBeltEventParameter ConveyerBeltCoordinationServiceLoadeventEventHandler::activateEventParam(const std::string& parameterString){
	CommRobotinoObjects::CommRobotinoConveyerBeltEventParameter param;

	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	param.setOldState(CommRobotinoObjects::RobotinoConveyerBeltEventType::CONVEYER_BELT_UNKNOWN);
	return param;
}
