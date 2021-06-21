#ifndef _LABELPRINTERCOORDINATIONSERVICEDATAQUERYHANDLER_HH_
#define _LABELPRINTERCOORDINATIONSERVICEDATAQUERYHANDLER_HH_

#include "DomainPrint/CommPrintProcessData.hh"
#include "DomainPrint/CommPrintResponse.hh"
#include <string>

class LabelPrinterCoordinationServiceDataQueryHandler
{
public:

	LabelPrinterCoordinationServiceDataQueryHandler(){

	}

	DomainPrint::CommPrintProcessData handleRequest(const std::string& inString);

	std::string handleAnswer(const DomainPrint::CommPrintResponse& answer);
};

#endif
