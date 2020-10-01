#include "ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore::ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommVoid, CommObjectRecognitionObjects::CommObjectRecognitionEventResult> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommObjectRecognitionObjects::CommObjectRecognitionEventResult>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommObjectRecognitionObjects::CommObjectRecognitionEventResult &r) {
	std::cout<<"Event CORE Called!"<<std::endl;
	std::string resultString;
	resultString = userHandler.handleEvent(r);
	
	std::ostringstream eventResult;
	eventResult<< "(";
	eventResult<< "( coordination-interfaces-type . \"ImageObjectRecognitionCoordinationService\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"objectrecognitionevent\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"ImageObjectRecognitionCoordinationService\" "<<this->ciInstanceName<<" \"objectrecognitionevent\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommBasicObjects::CommVoid ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
