#include "BundledNavigationCoordinationServiceBaseStateQueryHandler.hh"

#include "CommBasicObjectsJSON/CommVoidJSON.hh"
#include "CommBasicObjectsJSON/CommBaseStateJSON.hh"

CommBasicObjects::CommVoid BundledNavigationCoordinationServiceBaseStateQueryHandler::handleRequest(const std::string& inString){
	CommBasicObjects::CommVoid request;
	// parse the inString into an nlohmann::json object
	nlohmann::json data = nlohmann::json::parse(inString);
	// convert the parsed nlohmann::json object into the request communication object
	CommBasicObjectsIDL::from_json(data, request.set());
	// return the coverted result object
	return request;
}

std::string BundledNavigationCoordinationServiceBaseStateQueryHandler::handleAnswer(const CommBasicObjects::CommBaseState& answer){
	nlohmann::json data;
	CommBasicObjectsIDL::to_json(answer.get(), data);
	return data.dump();
}
