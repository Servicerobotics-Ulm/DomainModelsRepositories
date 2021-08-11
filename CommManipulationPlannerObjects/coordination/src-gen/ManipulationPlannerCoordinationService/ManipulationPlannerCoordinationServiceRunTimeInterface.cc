#include "ManipulationPlannerCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<ManipulationPlannerCoordinationServiceCore, ACE_Thread_Mutex> MANIPULATIONPLANNERCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initManipulationPlannerCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	MANIPULATIONPLANNERCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return MANIPULATIONPLANNERCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiManipulationPlannerCoordinationService(const std::string& ciInstanceName){
	return MANIPULATIONPLANNERCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchManipulationPlannerCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return MANIPULATIONPLANNERCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
