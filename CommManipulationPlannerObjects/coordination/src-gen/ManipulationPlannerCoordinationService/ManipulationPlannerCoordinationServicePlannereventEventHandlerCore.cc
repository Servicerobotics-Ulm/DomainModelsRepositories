#include "ManipulationPlannerCoordinationServicePlannereventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

ManipulationPlannerCoordinationServicePlannereventEventHandlerCore::ManipulationPlannerCoordinationServicePlannereventEventHandlerCore(Smart::IEventClientPattern<CommManipulationPlannerObjects::CommManipulationPlannerEventParameter, CommManipulationPlannerObjects::CommManipulationPlannerEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommManipulationPlannerObjects::CommManipulationPlannerEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void ManipulationPlannerCoordinationServicePlannereventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommManipulationPlannerObjects::CommManipulationPlannerEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"ManipulationPlannerCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"plannerevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"ManipulationPlannerCoordinationService\" "<<this->ciInstanceName<<" \"plannerevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommManipulationPlannerObjects::CommManipulationPlannerEventParameter ManipulationPlannerCoordinationServicePlannereventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
