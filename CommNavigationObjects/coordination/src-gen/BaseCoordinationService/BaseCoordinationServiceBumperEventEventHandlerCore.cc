#include "BaseCoordinationServiceBumperEventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

BaseCoordinationServiceBumperEventEventHandlerCore::BaseCoordinationServiceBumperEventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommBumperEventParameter, CommBasicObjects::CommBumperEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommBasicObjects::CommBumperEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void BaseCoordinationServiceBumperEventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommBumperEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"BaseCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"bumperEvent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"BaseCoordinationService\" "<<this->ciInstanceName<<" \"bumperEvent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommBasicObjects::CommBumperEventParameter BaseCoordinationServiceBumperEventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
