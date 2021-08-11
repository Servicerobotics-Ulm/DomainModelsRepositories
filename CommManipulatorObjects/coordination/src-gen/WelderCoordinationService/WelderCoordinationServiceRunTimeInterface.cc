#include "WelderCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<WelderCoordinationServiceCore, ACE_Thread_Mutex> WELDERCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initWelderCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	WELDERCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return WELDERCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiWelderCoordinationService(const std::string& ciInstanceName){
	return WELDERCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchWelderCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return WELDERCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
