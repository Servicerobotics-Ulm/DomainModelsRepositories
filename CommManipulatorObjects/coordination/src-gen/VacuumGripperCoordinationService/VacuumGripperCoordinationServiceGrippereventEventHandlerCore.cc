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
	std::cout<<"Event CORE Called!"<<std::endl;
	std::string resultString;
	resultString = userHandler.handleEvent(r);
	
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
