#include "ManipulationCoordinationServiceManipulatorprogramsQueryHandler.hh"

#include "CommBasicObjectsJSON/CommVoidJSON.hh"
#include "CommManipulatorObjectsJSON/CommMobileManipulatorProgramsJSON.hh"

#include <iomanip>

#include <sstream>


CommBasicObjects::CommVoid ManipulationCoordinationServiceManipulatorprogramsQueryHandler::handleRequest(const std::string& inString){

	CommBasicObjects::CommVoid request;
//	// parse the inString into an nlohmann::json object
//	nlohmann::json data = nlohmann::json::parse(inString);
//	// convert the parsed nlohmann::json object into the request communication object
//	CommBasicObjectsIDL::from_json(data, request.set());
//	// return the coverted result object
	return request;
}

std::string ManipulationCoordinationServiceManipulatorprogramsQueryHandler::handleAnswer(const CommManipulatorObjects::CommMobileManipulatorPrograms& answer){

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


//	nlohmann::json data;
//	CommManipulatorObjectsIDL::to_json(answer.get(), data);
//	return data.dump();
}
