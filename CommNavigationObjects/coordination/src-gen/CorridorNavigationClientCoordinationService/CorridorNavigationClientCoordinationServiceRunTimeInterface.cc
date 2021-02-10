#include "CorridorNavigationClientCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<CorridorNavigationClientCoordinationServiceCore, ACE_Thread_Mutex> CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initCorridorNavigationClientCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiCorridorNavigationClientCoordinationService(const std::string& ciInstanceName){
	return CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchCorridorNavigationClientCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
