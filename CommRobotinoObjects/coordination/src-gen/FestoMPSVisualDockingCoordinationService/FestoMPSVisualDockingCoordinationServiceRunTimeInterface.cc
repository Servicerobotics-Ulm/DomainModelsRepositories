#include "FestoMPSVisualDockingCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<FestoMPSVisualDockingCoordinationServiceCore, ACE_Thread_Mutex> FESTOMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initFestoMPSVisualDockingCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	FESTOMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return FESTOMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiFestoMPSVisualDockingCoordinationService(const std::string& ciInstanceName){
	return FESTOMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchFestoMPSVisualDockingCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return FESTOMPSVISUALDOCKINGCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
