#include "IOQueryCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<IOQueryCoordinationServiceCore, ACE_Thread_Mutex> IOQUERYCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initIOQueryCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	IOQUERYCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return IOQUERYCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiIOQueryCoordinationService(const std::string& ciInstanceName){
	return IOQUERYCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchIOQueryCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return IOQUERYCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
