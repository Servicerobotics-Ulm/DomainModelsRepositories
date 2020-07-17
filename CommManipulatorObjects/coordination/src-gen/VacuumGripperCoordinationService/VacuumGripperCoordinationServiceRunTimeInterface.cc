#include "VacuumGripperCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<VacuumGripperCoordinationServiceCore, ACE_Thread_Mutex> VACUUMGRIPPERCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initVacuumGripperCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	VACUUMGRIPPERCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return VACUUMGRIPPERCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiVacuumGripperCoordinationService(const std::string& ciInstanceName){
	return VACUUMGRIPPERCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchVacuumGripperCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return VACUUMGRIPPERCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
