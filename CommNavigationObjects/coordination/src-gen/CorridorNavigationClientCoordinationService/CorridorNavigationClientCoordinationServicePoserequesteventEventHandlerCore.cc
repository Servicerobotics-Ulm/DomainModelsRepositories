#include "CorridorNavigationClientCoordinationServicePoserequesteventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

CorridorNavigationClientCoordinationServicePoserequesteventEventHandlerCore::CorridorNavigationClientCoordinationServicePoserequesteventEventHandlerCore(Smart::IEventClientPattern<CommNavigationObjects::CommCorridorNavigationPoseRequestEventParameter, CommNavigationObjects::CommCorridorNavigationPoseRequestEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommNavigationObjects::CommCorridorNavigationPoseRequestEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void CorridorNavigationClientCoordinationServicePoserequesteventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommNavigationObjects::CommCorridorNavigationPoseRequestEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"CorridorNavigationClientCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"poserequestevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"CorridorNavigationClientCoordinationService\" "<<this->ciInstanceName<<" \"poserequestevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommNavigationObjects::CommCorridorNavigationPoseRequestEventParameter CorridorNavigationClientCoordinationServicePoserequesteventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
