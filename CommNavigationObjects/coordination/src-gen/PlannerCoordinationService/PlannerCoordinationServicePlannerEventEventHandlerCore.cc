#include "PlannerCoordinationServicePlannerEventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

PlannerCoordinationServicePlannerEventEventHandlerCore::PlannerCoordinationServicePlannerEventEventHandlerCore(Smart::IEventClientPattern<CommNavigationObjects::CommPlannerEventParameter, CommNavigationObjects::CommPlannerEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommNavigationObjects::CommPlannerEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void PlannerCoordinationServicePlannerEventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommNavigationObjects::CommPlannerEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"PlannerCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"plannerEvent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"PlannerCoordinationService\" "<<this->ciInstanceName<<" \"plannerEvent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommNavigationObjects::CommPlannerEventParameter PlannerCoordinationServicePlannerEventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
