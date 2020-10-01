#ifndef _IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICEOBJECTRECOGNITIONEVENTEVENTHANDLER_HH_
#define _IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICEOBJECTRECOGNITIONEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommObjectRecognitionObjects/CommObjectRecognitionEventResult.hh"
#include "CommBasicObjects/CommVoid.hh"

class ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandler
{
public:
	std::string handleEvent(const CommObjectRecognitionObjects::CommObjectRecognitionEventResult &r) throw();
	CommBasicObjects::CommVoid activateEventParam(const std::string& parameterString);
};

#endif
