#include "VisionCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<VisionCoordinationServiceCore, ACE_Thread_Mutex> VISIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initVisionCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	VISIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return VISIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiVisionCoordinationService(const std::string& ciInstanceName){
	return VISIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchVisionCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return VISIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
