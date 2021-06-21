#include "ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore::ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore(Smart::IEventClientPattern<DomainExternalSystems::CommExternalProgamEventParam, DomainExternalSystems::CommExternalProgramResponse> *client, std::string ciInstanceName)
: Smart::IEventHandler<DomainExternalSystems::CommExternalProgramResponse>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const DomainExternalSystems::CommExternalProgramResponse &r) {
	std::string resultString;
	resultString = userHandler.handleEvent(r);
	
	///////////////////////////////////////////
	/////////// ESCAPE " in user data
	std::string toSearch = "\"";
	std::string replaceStr = "\\\"";
	// Get the first occurrence
    size_t pos = resultString.find(toSearch);
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
    	resultString.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos =resultString.find(toSearch, pos + replaceStr.size());
    }
    ///////////////////////////////////////////
	
	std::ostringstream eventResult;
	eventResult<< "(";
	eventResult<< "( coordination-interfaces-type . \"ExternalProgamCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"programCallResult\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"ExternalProgamCoordinationService\" "<<this->ciInstanceName<<" \"programCallResult\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

DomainExternalSystems::CommExternalProgamEventParam ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
