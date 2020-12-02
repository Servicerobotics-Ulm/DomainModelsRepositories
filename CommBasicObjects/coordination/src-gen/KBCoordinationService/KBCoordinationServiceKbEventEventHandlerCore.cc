#include "KBCoordinationServiceKbEventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

KBCoordinationServiceKbEventEventHandlerCore::KBCoordinationServiceKbEventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommKBEventParam, CommBasicObjects::CommKBEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommBasicObjects::CommKBEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void KBCoordinationServiceKbEventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommKBEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"KBCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"kbEvent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"KBCoordinationService\" "<<this->ciInstanceName<<" \"kbEvent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommBasicObjects::CommKBEventParam KBCoordinationServiceKbEventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
