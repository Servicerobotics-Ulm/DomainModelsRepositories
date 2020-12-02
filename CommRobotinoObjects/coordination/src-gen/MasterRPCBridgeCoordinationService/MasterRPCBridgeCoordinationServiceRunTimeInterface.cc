#include "MasterRPCBridgeCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<MasterRPCBridgeCoordinationServiceCore, ACE_Thread_Mutex> MASTERRPCBRIDGECOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initMasterRPCBridgeCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	MASTERRPCBRIDGECOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return MASTERRPCBRIDGECOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiMasterRPCBridgeCoordinationService(const std::string& ciInstanceName){
	return MASTERRPCBRIDGECOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchMasterRPCBridgeCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return MASTERRPCBRIDGECOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
