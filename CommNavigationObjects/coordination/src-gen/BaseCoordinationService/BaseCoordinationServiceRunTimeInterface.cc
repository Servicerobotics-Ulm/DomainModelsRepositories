#include "BaseCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<BaseCoordinationServiceCore, ACE_Thread_Mutex> BASECOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initBaseCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	BASECOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return BASECOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiBaseCoordinationService(const std::string& ciInstanceName){
	return BASECOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchBaseCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return BASECOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
