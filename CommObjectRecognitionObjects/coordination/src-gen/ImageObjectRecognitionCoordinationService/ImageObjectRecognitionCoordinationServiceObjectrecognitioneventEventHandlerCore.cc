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
