#include "IRComponentCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<IRComponentCoordinationServiceCore, ACE_Thread_Mutex> IRCOMPONENTCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initIRComponentCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	IRCOMPONENTCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return IRCOMPONENTCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiIRComponentCoordinationService(const std::string& ciInstanceName){
	return IRCOMPONENTCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchIRComponentCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return IRCOMPONENTCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
