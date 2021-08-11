#include "DefaultCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<DefaultCoordinationServiceCore, ACE_Thread_Mutex> DEFAULTCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initDefaultCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	DEFAULTCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return DEFAULTCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiDefaultCoordinationService(const std::string& ciInstanceName){
	return DEFAULTCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchDefaultCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return DEFAULTCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
