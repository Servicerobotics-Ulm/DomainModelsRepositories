#include "TTSCorrdinationServiceSayWaitQueryHandler.hh"
  
DomainSpeech::CommSpeechOutputMessage TTSCorrdinationServiceSayWaitQueryHandler::handleRequest(const std::string& inString){

	DomainSpeech::CommSpeechOutputMessage request;
	//fill the request commObject with the data provided via the inString (from TCL)
	//e.g. request.setLisp(inString);

	request.setText(inString);

	return request;
}

std::string TTSCorrdinationServiceSayWaitQueryHandler::handleAnswer(const CommBasicObjects::CommPropertySet& answer){
	
	std::string outString;
	//fill the outString (to TCL) with the data provided via the answer commObject
	//e.g. 
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}
