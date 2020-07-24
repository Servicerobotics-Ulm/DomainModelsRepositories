#include "RobotDockingCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<RobotDockingCoordinationServiceCore, ACE_Thread_Mutex> ROBOTDOCKINGCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initRobotDockingCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	ROBOTDOCKINGCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return ROBOTDOCKINGCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiRobotDockingCoordinationService(const std::string& ciInstanceName){
	return ROBOTDOCKINGCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchRobotDockingCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return ROBOTDOCKINGCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
