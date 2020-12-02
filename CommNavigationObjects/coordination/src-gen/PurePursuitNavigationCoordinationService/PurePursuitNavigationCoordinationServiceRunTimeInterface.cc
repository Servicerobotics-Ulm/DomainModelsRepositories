#include "PurePursuitNavigationCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<PurePursuitNavigationCoordinationServiceCore, ACE_Thread_Mutex> PUREPURSUITNAVIGATIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initPurePursuitNavigationCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	PUREPURSUITNAVIGATIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return PUREPURSUITNAVIGATIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiPurePursuitNavigationCoordinationService(const std::string& ciInstanceName){
	return PUREPURSUITNAVIGATIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchPurePursuitNavigationCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return PUREPURSUITNAVIGATIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
