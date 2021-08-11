#include "KBCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<KBCoordinationServiceCore, ACE_Thread_Mutex> KBCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initKBCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	KBCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return KBCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiKBCoordinationService(const std::string& ciInstanceName){
	return KBCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchKBCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return KBCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
