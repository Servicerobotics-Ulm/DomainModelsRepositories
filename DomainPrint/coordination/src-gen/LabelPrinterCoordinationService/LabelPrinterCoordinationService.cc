#include "LabelPrinterCoordinationService.hh"

LabelPrinterCoordinationService::LabelPrinterCoordinationService (){
		labelPrinterCoordinationServicedataQueryHandler = NULL;
		labelPrinterCoordinationServicedataClient = NULL;
		labelPrinterCoordinationServicefullPrintJobQueryHandler = NULL;
		labelPrinterCoordinationServicefullPrintJobClient = NULL;
		labelPrinterCoordinationServicetriggerSendHandler = NULL;
		labelPrinterCoordinationServicetriggerClient = NULL;
}
LabelPrinterCoordinationService::~LabelPrinterCoordinationService (){
	
}

