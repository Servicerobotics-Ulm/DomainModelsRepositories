#include "MapperCoordinationServiceLtmMapDataQueryHandler.hh"

#include "CommNavigationObjectsJSON/CommGridMapRequestJSON.hh"
#include "CommNavigationObjectsJSON/CommGridMapJSON.hh"

#include <sstream>

CommNavigationObjects::CommGridMapRequest MapperCoordinationServiceLtmMapDataQueryHandler::handleRequest(const std::string& inString){
	CommNavigationObjects::CommGridMapRequest request;
//	// parse the inString into an nlohmann::json object
//	nlohmann::json data = nlohmann::json::parse(inString);
//	// convert the parsed nlohmann::json object into the request communication object
//	CommNavigationObjectsIDL::from_json(data, request.set());
//	// return the coverted result object
	return request;
}

std::string MapperCoordinationServiceLtmMapDataQueryHandler::handleAnswer(const CommNavigationObjects::CommGridMap& answer){
//	nlohmann::json data;
//	CommNavigationObjectsIDL::to_json(answer.get(), data);
//	return data.dump();

	std::ostringstream outString;
	double cell_size = answer.getCellSizeMM()/1000.0;
	double x_offset = answer.getXOffsetMM()/1000.0;
	double y_offset = answer.getYOffsetMM()/1000.0;
	double x_size = answer.getXSizeMM()/1000.0;
	double y_size = answer.getYSizeMM()/1000.0;

	outString << std::fixed << std::setprecision(2) << "("<<x_size<<" "<<y_size<<" "<<x_offset<<" "<<y_offset<<" "<< cell_size <<")";
	return outString.str();
}
