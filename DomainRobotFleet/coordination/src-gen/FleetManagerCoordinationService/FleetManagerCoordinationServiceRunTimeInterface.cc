#include "FleetManagerCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<FleetManagerCoordinationServiceCore, ACE_Thread_Mutex> FLEETMANAGERCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initFleetManagerCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	FLEETMANAGERCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return FLEETMANAGERCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiFleetManagerCoordinationService(const std::string& ciInstanceName){
	return FLEETMANAGERCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchFleetManagerCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return FLEETMANAGERCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
