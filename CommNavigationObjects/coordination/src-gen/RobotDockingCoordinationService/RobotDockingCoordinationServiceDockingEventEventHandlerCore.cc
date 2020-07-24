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
	std::cout<<"Event CORE Called!"<<std::endl;
	std::string resultString;
	resultString = userHandler.handleEvent(r);
	
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
