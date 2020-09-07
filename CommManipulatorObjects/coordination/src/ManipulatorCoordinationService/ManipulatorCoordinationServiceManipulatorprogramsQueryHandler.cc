#include "ManipulatorCoordinationServiceManipulatorprogramsQueryHandler.hh"
  
#include <iomanip>

#include <sstream>

CommBasicObjects::CommVoid ManipulatorCoordinationServiceManipulatorprogramsQueryHandler::handleRequest(const std::string& inString){

	CommBasicObjects::CommVoid request;
	//fill the request commObject with the data provided via the inString (from TCL)
	//e.g. request.setLisp(inString);

	return request;
}

std::string ManipulatorCoordinationServiceManipulatorprogramsQueryHandler::handleAnswer(const CommManipulatorObjects::CommMobileManipulatorPrograms& answer){
	
	std::ostringstream outString;

	if(answer.getIsValid()){
		outString << "(ok (";
		for (int i = 0; i < answer.getNamesSize(); ++i) {
			outString <<"\""<< answer.getNamesElemAtPos(i) <<"\""<< " ";
		}

		outString << "))";
	} else {
		outString << "(ok (no programs))";
	}

	return outString.str();
}
