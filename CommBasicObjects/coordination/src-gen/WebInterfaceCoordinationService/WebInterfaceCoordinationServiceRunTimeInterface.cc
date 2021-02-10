#include "WebInterfaceCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<WebInterfaceCoordinationServiceCore, ACE_Thread_Mutex> WEBINTERFACECOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initWebInterfaceCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	WEBINTERFACECOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return WEBINTERFACECOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiWebInterfaceCoordinationService(const std::string& ciInstanceName){
	return WEBINTERFACECOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchWebInterfaceCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return WEBINTERFACECOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
