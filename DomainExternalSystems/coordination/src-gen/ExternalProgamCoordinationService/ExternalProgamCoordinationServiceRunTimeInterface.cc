#include "ExternalProgamCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<ExternalProgamCoordinationServiceCore, ACE_Thread_Mutex> EXTERNALPROGAMCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initExternalProgamCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	EXTERNALPROGAMCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return EXTERNALPROGAMCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiExternalProgamCoordinationService(const std::string& ciInstanceName){
	return EXTERNALPROGAMCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchExternalProgamCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return EXTERNALPROGAMCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
