#include "PickDetectionCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<PickDetectionCoordinationServiceCore, ACE_Thread_Mutex> PICKDETECTIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initPickDetectionCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	PICKDETECTIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return PICKDETECTIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiPickDetectionCoordinationService(const std::string& ciInstanceName){
	return PICKDETECTIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchPickDetectionCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return PICKDETECTIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
