#include "ManipulatorCoordinationServiceIoeventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

ManipulatorCoordinationServiceIoeventEventHandlerCore::ManipulatorCoordinationServiceIoeventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommDigitalInputEventParameter, CommBasicObjects::CommDigitalInputEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommBasicObjects::CommDigitalInputEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void ManipulatorCoordinationServiceIoeventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommDigitalInputEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"ManipulatorCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"ioevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"ManipulatorCoordinationService\" "<<this->ciInstanceName<<" \"ioevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommBasicObjects::CommDigitalInputEventParameter ManipulatorCoordinationServiceIoeventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
