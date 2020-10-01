#ifndef _IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICEOBJECTRECOGNITIONEVENTEVENTHANDLERCORE_HH_
#define _IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICEOBJECTRECOGNITIONEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommObjectRecognitionObjects/CommObjectRecognitionEventResult.hh"
#include "CommBasicObjects/CommVoid.hh"
#include "ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandler.hh"

class ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore : public Smart::IEventHandler<CommObjectRecognitionObjects::CommObjectRecognitionEventResult>
{
public:
	ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommVoid, CommObjectRecognitionObjects::CommObjectRecognitionEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommObjectRecognitionObjects::CommObjectRecognitionEventResult &r) override;
	CommBasicObjects::CommVoid activateEventParam(const std::string& parameterString);
private:
	ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
