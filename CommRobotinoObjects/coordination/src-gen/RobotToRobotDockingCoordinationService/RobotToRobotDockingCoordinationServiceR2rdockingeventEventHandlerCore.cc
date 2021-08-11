#include "RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore::RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore(Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoDockingEventParameter, CommRobotinoObjects::CommRobotinoDockingEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommRobotinoObjects::CommRobotinoDockingEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommRobotinoObjects::CommRobotinoDockingEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"RobotToRobotDockingCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"r2rdockingevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"RobotToRobotDockingCoordinationService\" "<<this->ciInstanceName<<" \"r2rdockingevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommRobotinoObjects::CommRobotinoDockingEventParameter RobotToRobotDockingCoordinationServiceR2rdockingeventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
