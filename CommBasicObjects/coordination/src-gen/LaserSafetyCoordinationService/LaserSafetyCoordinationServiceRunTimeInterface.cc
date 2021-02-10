#include "LaserSafetyCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<LaserSafetyCoordinationServiceCore, ACE_Thread_Mutex> LASERSAFETYCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initLaserSafetyCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	LASERSAFETYCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return LASERSAFETYCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiLaserSafetyCoordinationService(const std::string& ciInstanceName){
	return LASERSAFETYCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchLaserSafetyCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return LASERSAFETYCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
