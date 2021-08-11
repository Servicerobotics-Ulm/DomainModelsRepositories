#include "FestoMPSDockingCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<FestoMPSDockingCoordinationServiceCore, ACE_Thread_Mutex> FESTOMPSDOCKINGCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initFestoMPSDockingCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	FESTOMPSDOCKINGCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return FESTOMPSDOCKINGCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiFestoMPSDockingCoordinationService(const std::string& ciInstanceName){
	return FESTOMPSDOCKINGCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchFestoMPSDockingCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return FESTOMPSDOCKINGCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
