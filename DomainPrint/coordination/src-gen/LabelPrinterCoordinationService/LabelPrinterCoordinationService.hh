#ifndef LABELPRINTERCOORDINATIONSERVICE_H_
#define LABELPRINTERCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <DomainPrint/CommPrintProcessData.hh>
#include <DomainPrint/CommPrintProcessDataACE.hh>
#include <DomainPrint/CommPrintRequest.hh>
#include <DomainPrint/CommPrintRequestACE.hh>
#include <DomainPrint/CommPrintResponse.hh>
#include <DomainPrint/CommPrintResponseACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>


#include "LabelPrinterCoordinationServiceDataQueryHandler.hh"
#include "LabelPrinterCoordinationServiceFullPrintJobQueryHandler.hh"
#include "LabelPrinterCoordinationServiceTriggerSendHandler.hh"


class LabelPrinterCoordinationService {
 	
public:
	LabelPrinterCoordinationService ();
	~LabelPrinterCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IQueryClientPattern<DomainPrint::CommPrintProcessData, DomainPrint::CommPrintResponse> *labelPrinterCoordinationServicedataClient;
	LabelPrinterCoordinationServiceDataQueryHandler *labelPrinterCoordinationServicedataQueryHandler;
	Smart::IQueryClientPattern<DomainPrint::CommPrintRequest, DomainPrint::CommPrintResponse> *labelPrinterCoordinationServicefullPrintJobClient;
	LabelPrinterCoordinationServiceFullPrintJobQueryHandler *labelPrinterCoordinationServicefullPrintJobQueryHandler;
	SmartACE::SendClient<CommBasicObjects::CommVoid> *labelPrinterCoordinationServicetriggerClient;
	LabelPrinterCoordinationServiceTriggerSendHandler *labelPrinterCoordinationServicetriggerSendHandler;
 };
#endif /* LABELPRINTERCOORDINATIONSERVICE_H_ */
