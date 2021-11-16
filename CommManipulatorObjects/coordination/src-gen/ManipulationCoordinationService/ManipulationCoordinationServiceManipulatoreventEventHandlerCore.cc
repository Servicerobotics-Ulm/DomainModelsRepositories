#include "ManipulationCoordinationServiceManipulatoreventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

ManipulationCoordinationServiceManipulatoreventEventHandlerCore::ManipulationCoordinationServiceManipulatoreventEventHandlerCore(Smart::IEventClientPattern<CommManipulatorObjects::CommManipulatorEventParameter, CommManipulatorObjects::CommManipulatorEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommManipulatorObjects::CommManipulatorEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void ManipulationCoordinationServiceManipulatoreventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommManipulatorObjects::CommManipulatorEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"ManipulationCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"manipulatorevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"ManipulationCoordinationService\" "<<this->ciInstanceName<<" \"manipulatorevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommManipulatorObjects::CommManipulatorEventParameter ManipulationCoordinationServiceManipulatoreventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
