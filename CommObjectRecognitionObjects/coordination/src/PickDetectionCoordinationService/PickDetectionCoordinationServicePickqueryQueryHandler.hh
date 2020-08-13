#ifndef _PICKDETECTIONCOORDINATIONSERVICEPICKQUERYQUERYHANDLER_HH_
#define _PICKDETECTIONCOORDINATIONSERVICEPICKQUERYQUERYHANDLER_HH_

#include "CommObjectRecognitionObjects/CommPickDetectionRequest.hh"
#include "CommManipulatorObjects/CommGrasp.hh"
#include <string>

class PickDetectionCoordinationServicePickqueryQueryHandler
{
public:

	PickDetectionCoordinationServicePickqueryQueryHandler(){

	}

	CommObjectRecognitionObjects::CommPickDetectionRequest handleRequest(const std::string& inString);

	std::string handleAnswer(const CommManipulatorObjects::CommGrasp& answer);
};

#endif
