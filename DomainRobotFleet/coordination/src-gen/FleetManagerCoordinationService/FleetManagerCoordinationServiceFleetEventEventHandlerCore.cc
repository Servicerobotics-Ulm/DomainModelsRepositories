#include "FleetManagerCoordinationServiceFleetEventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

FleetManagerCoordinationServiceFleetEventEventHandlerCore::FleetManagerCoordinationServiceFleetEventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommTaskMessage, CommBasicObjects::CommTaskMessage> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommBasicObjects::CommTaskMessage>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void FleetManagerCoordinationServiceFleetEventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommTaskMessage &r) {
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
	eventResult<< "( coordination-interfaces-type . \"FleetManagerCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"fleetEvent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"FleetManagerCoordinationService\" "<<this->ciInstanceName<<" \"fleetEvent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommBasicObjects::CommTaskMessage FleetManagerCoordinationServiceFleetEventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
