#include "CdlCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<CdlCoordinationServiceCore, ACE_Thread_Mutex> CDLCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initCdlCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	CDLCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return CDLCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiCdlCoordinationService(const std::string& ciInstanceName){
	return CDLCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchCdlCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return CDLCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
