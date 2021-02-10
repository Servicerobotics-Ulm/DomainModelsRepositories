#ifndef _FILEOPERATIONSCOORDINATIONSERVICEFILEEVENTEVENTHANDLER_HH_
#define _FILEOPERATIONSCOORDINATIONSERVICEFILEEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommBasicObjects/CommFileMoverEventResult.hh"
#include "CommBasicObjects/CommFileMoverEventParameter.hh"

class FileOperationsCoordinationServiceFileEventEventHandler
{
public:
	std::string handleEvent(const CommBasicObjects::CommFileMoverEventResult &r) throw();
	CommBasicObjects::CommFileMoverEventParameter activateEventParam(const std::string& parameterString);
};

#endif
