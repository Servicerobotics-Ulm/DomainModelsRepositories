#include "PlannerCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<PlannerCoordinationServiceCore, ACE_Thread_Mutex> PLANNERCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initPlannerCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	PLANNERCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return PLANNERCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiPlannerCoordinationService(const std::string& ciInstanceName){
	return PLANNERCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchPlannerCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return PLANNERCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
