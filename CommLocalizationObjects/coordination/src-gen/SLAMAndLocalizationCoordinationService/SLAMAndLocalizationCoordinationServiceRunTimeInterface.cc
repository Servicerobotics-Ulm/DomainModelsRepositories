#include "SLAMAndLocalizationCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<SLAMAndLocalizationCoordinationServiceCore, ACE_Thread_Mutex> SLAMANDLOCALIZATIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initSLAMAndLocalizationCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	SLAMANDLOCALIZATIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return SLAMANDLOCALIZATIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiSLAMAndLocalizationCoordinationService(const std::string& ciInstanceName){
	return SLAMANDLOCALIZATIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchSLAMAndLocalizationCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return SLAMANDLOCALIZATIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
