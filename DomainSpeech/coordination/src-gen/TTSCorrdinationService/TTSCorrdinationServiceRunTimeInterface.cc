#include "TTSCorrdinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<TTSCorrdinationServiceCore, ACE_Thread_Mutex> TTSCORRDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initTTSCorrdinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	TTSCORRDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return TTSCORRDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiTTSCorrdinationService(const std::string& ciInstanceName){
	return TTSCORRDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchTTSCorrdinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return TTSCORRDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
