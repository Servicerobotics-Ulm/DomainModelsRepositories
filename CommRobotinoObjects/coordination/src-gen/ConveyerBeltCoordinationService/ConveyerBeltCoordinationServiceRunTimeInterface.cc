#include "ConveyerBeltCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<ConveyerBeltCoordinationServiceCore, ACE_Thread_Mutex> CONVEYERBELTCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initConveyerBeltCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	CONVEYERBELTCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return CONVEYERBELTCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiConveyerBeltCoordinationService(const std::string& ciInstanceName){
	return CONVEYERBELTCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchConveyerBeltCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return CONVEYERBELTCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
