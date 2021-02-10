#include "RobotDockingCoordinationServiceDockingEventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

RobotDockingCoordinationServiceDockingEventEventHandlerCore::RobotDockingCoordinationServiceDockingEventEventHandlerCore(Smart::IEventClientPattern<CommNavigationObjects::CommDockingEventParameter, CommNavigationObjects::CommDockingEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommNavigationObjects::CommDockingEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void RobotDockingCoordinationServiceDockingEventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommNavigationObjects::CommDockingEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"RobotDockingCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"dockingEvent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"RobotDockingCoordinationService\" "<<this->ciInstanceName<<" \"dockingEvent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommNavigationObjects::CommDockingEventParameter RobotDockingCoordinationServiceDockingEventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
