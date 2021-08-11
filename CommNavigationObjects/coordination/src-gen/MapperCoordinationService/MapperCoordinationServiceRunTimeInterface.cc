#include "MapperCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<MapperCoordinationServiceCore, ACE_Thread_Mutex> MAPPERCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initMapperCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	MAPPERCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return MAPPERCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiMapperCoordinationService(const std::string& ciInstanceName){
	return MAPPERCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchMapperCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return MAPPERCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
