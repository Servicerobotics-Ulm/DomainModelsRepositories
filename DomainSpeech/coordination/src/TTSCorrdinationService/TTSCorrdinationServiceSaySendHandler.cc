#include "TTSCorrdinationServiceSaySendHandler.hh"
  
DomainSpeech::CommSpeechOutputMessage TTSCorrdinationServiceSaySendHandler::handleSend(std::string inString){

	DomainSpeech::CommSpeechOutputMessage sendCommObject;

	//fill the send commObject with the data provided via the inString (from TCL)
	
	sendCommObject.setText(inString);

	return sendCommObject;
}

