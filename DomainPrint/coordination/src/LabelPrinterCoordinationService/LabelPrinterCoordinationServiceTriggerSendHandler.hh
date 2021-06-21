#ifndef _LABELPRINTERCOORDINATIONSERVICETRIGGERSENDHANDLER_HH_
#define _LABELPRINTERCOORDINATIONSERVICETRIGGERSENDHANDLER_HH_

#include "CommBasicObjects/CommVoid.hh"
#include <string>

class LabelPrinterCoordinationServiceTriggerSendHandler
{
public:

	LabelPrinterCoordinationServiceTriggerSendHandler(){

	}

	CommBasicObjects::CommVoid handleSend(std::string inString);
};

#endif
