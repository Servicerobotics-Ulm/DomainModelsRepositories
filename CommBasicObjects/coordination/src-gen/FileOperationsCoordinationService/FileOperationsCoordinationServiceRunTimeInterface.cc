#include "FileOperationsCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<FileOperationsCoordinationServiceCore, ACE_Thread_Mutex> FILEOPERATIONSCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initFileOperationsCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	FILEOPERATIONSCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return FILEOPERATIONSCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiFileOperationsCoordinationService(const std::string& ciInstanceName){
	return FILEOPERATIONSCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchFileOperationsCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return FILEOPERATIONSCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
