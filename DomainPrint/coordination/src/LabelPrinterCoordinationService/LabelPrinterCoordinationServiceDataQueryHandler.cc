#include "LabelPrinterCoordinationServiceDataQueryHandler.hh"
#include "DomainPrint/enumApplicationModeTypeEnum.hh"

#include "nlohmann/json.hpp"

using json = nlohmann::json;
  
DomainPrint::CommPrintProcessData LabelPrinterCoordinationServiceDataQueryHandler::handleRequest(const std::string& inString){

	DomainPrint::CommPrintProcessData request;
	// extract the json value from the request object

	std::cout<<"handleRequest: "<<inString<<std::endl;

	json data = json::parse(inString);

	if(data.contains("mode") && data["mode"].is_string()){
		std::string mode = data["mode"].get<std::string>();
		if(mode.compare("PrintApply") == 0){
			request.setApplicationMode(DomainPrint::ApplicationModeTypeEnum::PrintApply);
		} else if(mode.compare("ApplyPrint") == 0){
			request.setApplicationMode(DomainPrint::ApplicationModeTypeEnum::ApplyPrint);
		} else {
			std::cout<<"Unknown print mode, set default --> PrintApply"<<std::endl;
			request.setApplicationMode(DomainPrint::ApplicationModeTypeEnum::PrintApply);
		}
	}


	if(data.contains("templateid") && data["templateid"].is_string()){
		request.setTemplateID(data["templateid"].get<std::string>());
	}

	std::vector<DomainPrint::CommKeyValue> pairs;

	json keyValueData;
	if(data.contains("data") && data["data"].is_array()){
		keyValueData = data["data"];
	}


	for(auto& el : keyValueData.items())
	{
		DomainPrint::CommKeyValue v;
		v.setType(DomainPrint::KeyValueDataTypeEnum::STRING);
		if(el.value().contains("key") && el.value().at("key").is_string()){
			v.setKey(el.value().at("key").get<std::string>());
		}
		if(el.value().contains("value") && el.value().at("value").is_string()){
			v.setValue(el.value().at("value").get<std::string>());
		}
		pairs.push_back(v);
	}
	request.setData(pairs);

	std::cout<<"LabelPrinterCoordinationServiceDataQueryHandler request: "<<request<<std::endl;
	return request;
}

std::string LabelPrinterCoordinationServiceDataQueryHandler::handleAnswer(const DomainPrint::CommPrintResponse& answer){
	
	std::string outString;

	//fill the outString (to TCL) with the data provided via the answer commObject
	//e.g. 
	std::ostringstream ss;
	if(answer.getResult() == DomainPrint::PrintResponseResultEnum::SUCCESS)
	{
		ss << "( success \""<<answer.getResultValue()<<"\")";

	} else {
		ss << "( error \""<< answer.getResultValue()<<"\")";
	}
	outString = ss.str();
	return outString;
}
