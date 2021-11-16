#include "NavPathCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<NavPathCoordinationServiceCore, ACE_Thread_Mutex> NAVPATHCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initNavPathCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	NAVPATHCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return NAVPATHCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiNavPathCoordinationService(const std::string& ciInstanceName){
	return NAVPATHCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchNavPathCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return NAVPATHCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
