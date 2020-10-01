#ifndef IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICE_H_
#define IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommObjectRecognitionObjects/CommImageObjectRecognitionResults.hh>
#include <CommObjectRecognitionObjects/CommImageObjectRecognitionResultsACE.hh>
#include <CommObjectRecognitionObjects/CommObjectRecognitionEventResult.hh>
#include <CommObjectRecognitionObjects/CommObjectRecognitionEventResultACE.hh>
#include <CommObjectRecognitionObjects/CommObjectRecognitionEventState.hh>
#include <CommObjectRecognitionObjects/CommObjectRecognitionEventStateACE.hh>
#include <CommObjectRecognitionObjects/CommObjectRecognitionId.hh>
#include <CommObjectRecognitionObjects/CommObjectRecognitionIdACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>


#include "ImageObjectRecognitionCoordinationServiceObjectqueryQueryHandler.hh"
#include "ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore.hh"


class ImageObjectRecognitionCoordinationService {
 	
public:
	ImageObjectRecognitionCoordinationService ();
	~ImageObjectRecognitionCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IQueryClientPattern<CommObjectRecognitionObjects::CommObjectRecognitionId, CommObjectRecognitionObjects::CommImageObjectRecognitionResults> *imageObjectRecognitionCoordinationServiceobjectqueryClient;
	ImageObjectRecognitionCoordinationServiceObjectqueryQueryHandler *imageObjectRecognitionCoordinationServiceobjectqueryQueryHandler;
	Smart::IEventClientPattern<CommBasicObjects::CommVoid, CommObjectRecognitionObjects::CommObjectRecognitionEventResult> *imageObjectRecognitionCoordinationServiceobjectrecognitioneventClient;
	ImageObjectRecognitionCoordinationServiceObjectrecognitioneventEventHandlerCore *imageObjectRecognitionCoordinationServiceobjectrecognitioneventEventHandlerCore;
 };
#endif /* IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICE_H_ */
