#ifndef _LABELPRINTERCOORDINATIONSERVICEFULLPRINTJOBQUERYHANDLER_HH_
#define _LABELPRINTERCOORDINATIONSERVICEFULLPRINTJOBQUERYHANDLER_HH_

#include "DomainPrint/CommPrintRequest.hh"
#include "DomainPrint/CommPrintResponse.hh"
#include <string>

class LabelPrinterCoordinationServiceFullPrintJobQueryHandler
{
public:

	LabelPrinterCoordinationServiceFullPrintJobQueryHandler(){

	}

	DomainPrint::CommPrintRequest handleRequest(const std::string& inString);

	std::string handleAnswer(const DomainPrint::CommPrintResponse& answer);
};

#endif
