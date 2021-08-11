#include "ManipulatorCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<ManipulatorCoordinationServiceCore, ACE_Thread_Mutex> MANIPULATORCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initManipulatorCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	MANIPULATORCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return MANIPULATORCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiManipulatorCoordinationService(const std::string& ciInstanceName){
	return MANIPULATORCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchManipulatorCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return MANIPULATORCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
