#include "FleetManagerCoordinationServiceFleetSendSendHandler.hh"
  
CommBasicObjects::CommTaskMessage FleetManagerCoordinationServiceFleetSendSendHandler::handleSend(std::string inString){

	CommBasicObjects::CommTaskMessage sendCommObject;

	//fill the send commObject with the data provided via the inString (from TCL)
	
	sendCommObject.setMsg(inString);

	return sendCommObject;
}

