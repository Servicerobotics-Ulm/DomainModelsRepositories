#include "RemoteControlCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<RemoteControlCoordinationServiceCore, ACE_Thread_Mutex> REMOTECONTROLCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initRemoteControlCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	REMOTECONTROLCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return REMOTECONTROLCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiRemoteControlCoordinationService(const std::string& ciInstanceName){
	return REMOTECONTROLCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchRemoteControlCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return REMOTECONTROLCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
