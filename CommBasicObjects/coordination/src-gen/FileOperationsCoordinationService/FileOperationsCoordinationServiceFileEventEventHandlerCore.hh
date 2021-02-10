#ifndef _FILEOPERATIONSCOORDINATIONSERVICEFILEEVENTEVENTHANDLERCORE_HH_
#define _FILEOPERATIONSCOORDINATIONSERVICEFILEEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommBasicObjects/CommFileMoverEventResult.hh"
#include "CommBasicObjects/CommFileMoverEventParameter.hh"
#include "FileOperationsCoordinationServiceFileEventEventHandler.hh"

class FileOperationsCoordinationServiceFileEventEventHandlerCore : public Smart::IEventHandler<CommBasicObjects::CommFileMoverEventResult>
{
public:
	FileOperationsCoordinationServiceFileEventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommFileMoverEventResult &r) override;
	CommBasicObjects::CommFileMoverEventParameter activateEventParam(const std::string& parameterString);
private:
	FileOperationsCoordinationServiceFileEventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
