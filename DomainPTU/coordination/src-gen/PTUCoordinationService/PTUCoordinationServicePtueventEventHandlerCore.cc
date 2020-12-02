#include "PTUCoordinationServicePtueventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

PTUCoordinationServicePtueventEventHandlerCore::PTUCoordinationServicePtueventEventHandlerCore(Smart::IEventClientPattern<DomainPTU::CommPTUGoalEventParameter, DomainPTU::CommPTUGoalEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<DomainPTU::CommPTUGoalEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void PTUCoordinationServicePtueventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const DomainPTU::CommPTUGoalEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"PTUCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"ptuevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"PTUCoordinationService\" "<<this->ciInstanceName<<" \"ptuevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

DomainPTU::CommPTUGoalEventParameter PTUCoordinationServicePtueventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
