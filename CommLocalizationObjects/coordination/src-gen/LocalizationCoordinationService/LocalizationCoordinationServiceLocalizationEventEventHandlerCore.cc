#include "LocalizationCoordinationServiceLocalizationEventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

LocalizationCoordinationServiceLocalizationEventEventHandlerCore::LocalizationCoordinationServiceLocalizationEventEventHandlerCore(Smart::IEventClientPattern<CommLocalizationObjects::CommLocalizationEventParameter, CommLocalizationObjects::CommLocalizationEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommLocalizationObjects::CommLocalizationEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void LocalizationCoordinationServiceLocalizationEventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommLocalizationObjects::CommLocalizationEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"LocalizationCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"localizationEvent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"LocalizationCoordinationService\" "<<this->ciInstanceName<<" \"localizationEvent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommLocalizationObjects::CommLocalizationEventParameter LocalizationCoordinationServiceLocalizationEventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
