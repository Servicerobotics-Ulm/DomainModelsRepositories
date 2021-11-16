#include "ManipulationCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<ManipulationCoordinationServiceCore, ACE_Thread_Mutex> MANIPULATIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initManipulationCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	MANIPULATIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return MANIPULATIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiManipulationCoordinationService(const std::string& ciInstanceName){
	return MANIPULATIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchManipulationCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return MANIPULATIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
