#include "RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore::RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore(Smart::IEventClientPattern<DomainHMI::CommRemoteControlEvent, DomainHMI::CommRemoteControlEvent> *client, std::string ciInstanceName)
: Smart::IEventHandler<DomainHMI::CommRemoteControlEvent>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const DomainHMI::CommRemoteControlEvent &r) {
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
	eventResult<< "( coordination-interfaces-type . \"RemoteControlCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"remoteControlEvent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"RemoteControlCoordinationService\" "<<this->ciInstanceName<<" \"remoteControlEvent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

DomainHMI::CommRemoteControlEvent RemoteControlCoordinationServiceRemoteControlEventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
