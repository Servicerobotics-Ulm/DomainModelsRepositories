#ifndef _IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICEOBJECTQUERYQUERYHANDLER_HH_
#define _IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICEOBJECTQUERYQUERYHANDLER_HH_

#include "CommObjectRecognitionObjects/CommObjectRecognitionId.hh"
#include "CommObjectRecognitionObjects/CommImageObjectRecognitionResults.hh"
#include <string>

class ImageObjectRecognitionCoordinationServiceObjectqueryQueryHandler
{
public:

	ImageObjectRecognitionCoordinationServiceObjectqueryQueryHandler(){

	}

	CommObjectRecognitionObjects::CommObjectRecognitionId handleRequest(const std::string& inString);

	std::string handleAnswer(const CommObjectRecognitionObjects::CommImageObjectRecognitionResults& answer);
};

#endif
