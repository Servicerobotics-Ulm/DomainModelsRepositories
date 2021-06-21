#include "ExternalProgamCoordinationServiceProgramCallResultEventHandler.hh"
#include <string>

std::string ExternalProgamCoordinationServiceProgramCallResultEventHandler::handleEvent(const DomainExternalSystems::CommExternalProgramResponse &r) throw() {
	//convert the event result commObject to string representation outString (to TCL)

	std::stringstream result_string;
	result_string << "( ";

	result_string << "(status ";
	switch (r.getStatus()) {
	case DomainExternalSystems::ExternalProgramStatus::UNKOWN:
		result_string << "UNKOWN";
		break;
	case DomainExternalSystems::ExternalProgramStatus::NOTRUNNING:
		result_string << "NOTRUNNING";
		break;
	case DomainExternalSystems::ExternalProgramStatus::RUNNING:
		result_string << "RUNNING";
		break;
	case DomainExternalSystems::ExternalProgramStatus::ABORTED:
		result_string << "ABORTED";
		break;
	case DomainExternalSystems::ExternalProgramStatus::FINSHED:
		result_string << "FINSHED";
		break;
	default:
		result_string << "ENUM_VALUE_UNDEFINED";
		break;
	};
	result_string<<")";


	result_string<<"(result ";
	switch (r.getResult()) {
	case DomainExternalSystems::ExternalProgramResult::SUCCESS:
		result_string << "SUCCESS";
		break;
	case DomainExternalSystems::ExternalProgramResult::ERROR:
		result_string << "ERROR";
		break;
	default:
		result_string << "ENUM_VALUE_UNDEFINED";
		break;
	}
	result_string<<")";

	result_string<<"(resultArgs ";
	if(r.getResultArgsSize()==0){
		result_string<<"nil";
	} else {
		for(unsigned int i; i<r.getResultArgsSize();i++){
			DomainExternalSystems::CommExternalProgramArgument resultArg = r.getResultArgsElemAtPos(i);
			result_string<<"(";
			result_string<<"(name "<<resultArg.getName()<<")";
			result_string<<"(type "<<resultArg.getType()<<")";
			result_string<<"(value "<<resultArg.getValue()<<")";
			result_string<<")";
		}
	}

	result_string<<")";

	return result_string.str();
}

DomainExternalSystems::CommExternalProgamEventParam ExternalProgamCoordinationServiceProgramCallResultEventHandler::activateEventParam(const std::string& parameterString){
	DomainExternalSystems::CommExternalProgamEventParam param;

	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);

	param.setStatus(DomainExternalSystems::ExternalProgramStatus::UNKOWN);
	return param;
}
