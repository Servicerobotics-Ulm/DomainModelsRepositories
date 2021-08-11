#include "VisualizationCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<VisualizationCoordinationServiceCore, ACE_Thread_Mutex> VISUALIZATIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initVisualizationCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	VISUALIZATIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return VISUALIZATIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiVisualizationCoordinationService(const std::string& ciInstanceName){
	return VISUALIZATIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchVisualizationCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return VISUALIZATIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
