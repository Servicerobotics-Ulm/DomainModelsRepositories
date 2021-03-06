#include "RobotToRobotDockingCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<RobotToRobotDockingCoordinationServiceCore, ACE_Thread_Mutex> ROBOTTOROBOTDOCKINGCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initRobotToRobotDockingCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	ROBOTTOROBOTDOCKINGCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return ROBOTTOROBOTDOCKINGCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiRobotToRobotDockingCoordinationService(const std::string& ciInstanceName){
	return ROBOTTOROBOTDOCKINGCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchRobotToRobotDockingCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return ROBOTTOROBOTDOCKINGCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
