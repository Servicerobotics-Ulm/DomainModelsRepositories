#include "NavPathClientCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<NavPathClientCoordinationServiceCore, ACE_Thread_Mutex> NAVPATHCLIENTCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initNavPathClientCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	NAVPATHCLIENTCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return NAVPATHCLIENTCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiNavPathClientCoordinationService(const std::string& ciInstanceName){
	return NAVPATHCLIENTCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchNavPathClientCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return NAVPATHCLIENTCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
