#ifndef FILEOPERATIONSCOORDINATIONSERVICE_H_
#define FILEOPERATIONSCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommFileMoverEventParameter.hh>
#include <CommBasicObjects/CommFileMoverEventParameterACE.hh>
#include <CommBasicObjects/CommFileMoverEventResult.hh>
#include <CommBasicObjects/CommFileMoverEventResultACE.hh>
#include <CommBasicObjects/CommFileMoverEventState.hh>
#include <CommBasicObjects/CommFileMoverEventStateACE.hh>


#include "FileOperationsCoordinationServiceFileEventEventHandlerCore.hh"


class FileOperationsCoordinationService {
 	
public:
	FileOperationsCoordinationService ();
	~FileOperationsCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult> *fileOperationsCoordinationServicefileEventClient;
	FileOperationsCoordinationServiceFileEventEventHandlerCore *fileOperationsCoordinationServicefileEventEventHandlerCore;
 };
#endif /* FILEOPERATIONSCOORDINATIONSERVICE_H_ */
