#include "FleetCommunicationCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<FleetCommunicationCoordinationServiceCore, ACE_Thread_Mutex> FLEETCOMMUNICATIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initFleetCommunicationCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	FLEETCOMMUNICATIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return FLEETCOMMUNICATIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiFleetCommunicationCoordinationService(const std::string& ciInstanceName){
	return FLEETCOMMUNICATIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchFleetCommunicationCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return FLEETCOMMUNICATIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
