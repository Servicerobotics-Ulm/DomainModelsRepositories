#include "CorridorNavigationServerCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<CorridorNavigationServerCoordinationServiceCore, ACE_Thread_Mutex> CORRIDORNAVIGATIONSERVERCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initCorridorNavigationServerCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	CORRIDORNAVIGATIONSERVERCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return CORRIDORNAVIGATIONSERVERCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiCorridorNavigationServerCoordinationService(const std::string& ciInstanceName){
	return CORRIDORNAVIGATIONSERVERCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchCorridorNavigationServerCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return CORRIDORNAVIGATIONSERVERCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
