#include "FileOperationsCoordinationServiceFileEventEventHandler.hh"

std::string FileOperationsCoordinationServiceFileEventEventHandler::handleEvent(const CommBasicObjects::CommFileMoverEventResult &r) throw() {
	std::string outString;

	switch(r.getState()) {
	case CommBasicObjects::FileMoverEventType::TYPE_FILE_UNKNOWN:
		outString = "(unknown)";
		break;
	case CommBasicObjects::FileMoverEventType::TYPE_FILE_ERROR:
		outString ="(error)";
		break;
	case CommBasicObjects::FileMoverEventType::TYPE_FILE_SUCCESS:
		outString = "(success)";
		break;
	default:
		outString = "(unknownerror)";
		break;
	}

	return outString;
}

CommBasicObjects::CommFileMoverEventParameter FileOperationsCoordinationServiceFileEventEventHandler::activateEventParam(const std::string& parameterString){
	CommBasicObjects::CommFileMoverEventParameter param;
	param.setOldState(CommBasicObjects::FileMoverEventType::TYPE_FILE_UNKNOWN);
	return param;
}
