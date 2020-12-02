#include "VacuumGripperCoordinationServiceGrippereventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

VacuumGripperCoordinationServiceGrippereventEventHandlerCore::VacuumGripperCoordinationServiceGrippereventEventHandlerCore(Smart::IEventClientPattern<CommManipulatorObjects::CommVacuumGripperEventParameter, CommManipulatorObjects::CommVacuumGripperEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommManipulatorObjects::CommVacuumGripperEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void VacuumGripperCoordinationServiceGrippereventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommManipulatorObjects::CommVacuumGripperEventResult &r) {
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
	eventResult<< "( coordination-interfaces-type . \"VacuumGripperCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"gripperevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"VacuumGripperCoordinationService\" "<<this->ciInstanceName<<" \"gripperevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommManipulatorObjects::CommVacuumGripperEventParameter VacuumGripperCoordinationServiceGrippereventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
