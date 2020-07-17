#include "SequencerHLCoordinationServerHLCommandResponseClientSendHandler.hh"
  
CommBasicObjects::CommSkillMsg SequencerHLCoordinationServerHLCommandResponseClientSendHandler::handleSend(std::string inString){

	CommBasicObjects::CommSkillMsg sendCommObject;

	//fill the send commObject with the data provided via the inString (from TCL)
	
	//sendCommObject.setData(inString);

	return sendCommObject;
}

