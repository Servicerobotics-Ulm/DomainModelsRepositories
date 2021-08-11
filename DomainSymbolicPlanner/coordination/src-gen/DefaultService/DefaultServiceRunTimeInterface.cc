#include "DefaultServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<DefaultServiceCore, ACE_Thread_Mutex> DEFAULTSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initDefaultService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	DEFAULTSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return DEFAULTSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiDefaultService(const std::string& ciInstanceName){
	return DEFAULTSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchDefaultService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return DEFAULTSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
