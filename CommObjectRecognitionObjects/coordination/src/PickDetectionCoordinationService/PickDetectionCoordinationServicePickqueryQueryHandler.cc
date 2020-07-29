#include "PickDetectionCoordinationServicePickqueryQueryHandler.hh"
  
CommObjectRecognitionObjects::PickDetectionRequest PickDetectionCoordinationServicePickqueryQueryHandler::handleRequest(const std::string& inString){

	CommObjectRecognitionObjects::PickDetectionRequest request;
	//fill the request commObject with the data provided via the inString (from TCL)
	//e.g. request.setLisp(inString);

	return request;
}

std::string PickDetectionCoordinationServicePickqueryQueryHandler::handleAnswer(const CommManipulatorObjects::CommGrasp& answer){
	
	std::string outString;
	//fill the outString (to TCL) with the data provided via the answer commObject
	//e.g. 
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}
