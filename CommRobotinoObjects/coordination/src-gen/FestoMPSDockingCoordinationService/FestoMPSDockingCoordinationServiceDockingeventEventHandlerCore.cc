#include "FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore::FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore(Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommRobotinoObjects::CommRobotinoDockingEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommRobotinoObjects::CommRobotinoDockingEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"FestoMPSDockingCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"dockingevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"FestoMPSDockingCoordinationService\" "<<this->ciInstanceName<<" \"dockingevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommRobotinoObjects::CommRobotinoDockingEventParameter FestoMPSDockingCoordinationServiceDockingeventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
