#include "BundledNavigationCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<BundledNavigationCoordinationServiceCore, ACE_Thread_Mutex> BUNDLEDNAVIGATIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initBundledNavigationCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	BUNDLEDNAVIGATIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return BUNDLEDNAVIGATIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiBundledNavigationCoordinationService(const std::string& ciInstanceName){
	return BUNDLEDNAVIGATIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchBundledNavigationCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return BUNDLEDNAVIGATIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
