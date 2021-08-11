#include "LocalizationCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<LocalizationCoordinationServiceCore, ACE_Thread_Mutex> LOCALIZATIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initLocalizationCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	LOCALIZATIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return LOCALIZATIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiLocalizationCoordinationService(const std::string& ciInstanceName){
	return LOCALIZATIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchLocalizationCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return LOCALIZATIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
