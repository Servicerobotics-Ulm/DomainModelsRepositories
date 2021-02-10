#include "FestMPSVisualDockingCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<FestMPSVisualDockingCoordinationServiceCore, ACE_Thread_Mutex> FESTMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initFestMPSVisualDockingCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	FESTMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return FESTMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiFestMPSVisualDockingCoordinationService(const std::string& ciInstanceName){
	return FESTMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchFestMPSVisualDockingCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return FESTMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
