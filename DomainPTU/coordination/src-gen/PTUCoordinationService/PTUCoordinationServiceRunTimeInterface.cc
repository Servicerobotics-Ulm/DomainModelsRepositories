#include "PTUCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<PTUCoordinationServiceCore, ACE_Thread_Mutex> PTUCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initPTUCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	PTUCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return PTUCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiPTUCoordinationService(const std::string& ciInstanceName){
	return PTUCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchPTUCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return PTUCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
